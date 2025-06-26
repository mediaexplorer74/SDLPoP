// UWPDataCopy.cpp
// Реализация копирования файлов из Assets/data в LocalFolder/data для UWP C++/CX


#include "common.h"
#include <time.h>
#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#include <wchar.h>
#else
#include "dirent.h"
#endif
#include <ppltasks.h>
#include <wrl.h>
#include <windows.storage.h>
#include <windows.applicationmodel.h>
#include <string>

using namespace Windows::Storage;
using namespace Windows::ApplicationModel;
using namespace Windows::Foundation::Collections;
using namespace Platform;
using namespace concurrency;


// Рекурсивная функция копирования папок и файлов
void CopyFolderRecursive(StorageFolder^ sourceFolder, StorageFolder^ destFolder)
{
    // Копируем все файлы
    create_task(sourceFolder->GetFilesAsync()).then([destFolder](IVectorView<StorageFile^>^ files)
    {
        for (unsigned int i = 0; i < files->Size; ++i)
        {
            auto file = files->GetAt(i);
            create_task(file->CopyAsync(destFolder, file->Name, NameCollisionOption::ReplaceExisting));
        }
    });
    // Копируем все подпапки рекурсивно
    create_task(sourceFolder->GetFoldersAsync()).then([destFolder, sourceFolder](IVectorView<StorageFolder^>^ folders)
    {
        for (unsigned int i = 0; i < folders->Size; ++i)
        {
            auto subfolder = folders->GetAt(i);
            create_task(destFolder->CreateFolderAsync(subfolder->Name, CreationCollisionOption::OpenIfExists)).then([subfolder](StorageFolder^ newSubfolder)
            {
                CopyFolderRecursive(subfolder, newSubfolder);
            });
        }
    });
}

// Асинхронная функция копирования файлов
void EnsureDataFolderAndCopyAssets()
{
    auto localFolder = ApplicationData::Current->LocalFolder;
    create_task(localFolder->TryGetItemAsync("data")).then([localFolder](IStorageItem^ item)
    {
        if (item == nullptr)
        {
            // Папки нет, создаём и копируем файлы
            create_task(localFolder->CreateFolderAsync("data")).then([](StorageFolder^ dataFolder)
            {
                auto assetsFolderTask = create_task(Package::Current->InstalledLocation->GetFolderAsync("Assets"));
                assetsFolderTask.then([dataFolder](StorageFolder^ assetsFolder)
                {
                    create_task(assetsFolder->GetFolderAsync("data")).then([dataFolder](StorageFolder^ assetsDataFolder)
                    {
                        
                            // Рекурсивное копирование
                            CopyFolderRecursive(assetsDataFolder, dataFolder);
              
                            Sleep(10000); // 10 seconds
                    });

                    
                });
            });
        }
        // else: папка уже есть — ничего не делаем
    });

    
}

extern "C" {
    __declspec(dllexport) void EnsureDataFolderAndCopyAssets_UWP()
    {
        EnsureDataFolderAndCopyAssets();
    }
}
