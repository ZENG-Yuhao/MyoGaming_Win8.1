#include "pch.h"
#include "FileManager.h"

using namespace concurrency;
using namespace Windows::Storage;
using namespace Platform;

FileManager::FileManager()
{
	
}

FileManager::~FileManager()
{
	if (targetFile!=nullptr) delete(targetFile);
	//if (returnContent != nullptr) delete(returnContent);
}

void FileManager::CreateFile(String^ fileName)
{
	create_task(KnownFolders::PicturesLibrary->CreateFileAsync(fileName, CreationCollisionOption::OpenIfExists)).then([this](StorageFile^ file)
	{
		targetFile = file;
	});
	//Sleep(1000);
}

void FileManager::WriteToFile(String^ content)
{
	if (targetFile != nullptr)
	{
		if (content != nullptr && !content->IsEmpty())
		{
			StorageFile^ tmpTargetFile = targetFile;
			create_task(FileIO::WriteTextAsync(targetFile, content)).then([this, tmpTargetFile, content](task<void> task)
			{
				try
				{
					task.get();

				}
				catch (COMException^ ex)
				{

				}
			});

		}
	}
}

String^ FileManager::ReadFromFile()
{
	StorageFile^ file = targetFile;
	if (file != nullptr)
	{
		create_task(FileIO::ReadTextAsync(file)).then([this, file](task<String^> task)
		{
			try
			{
				returnContent = task.get();

			}
			catch (COMException^ ex)
			{

			}
		});
	}
	else
	{

	}
	return returnContent;
}

void FileManager::ValidateFile(Platform::String^ filename)
{
	create_task(KnownFolders::PicturesLibrary->GetFileAsync(filename)).then([this](task<StorageFile^> getFileTask)
	{
		try
		{
			targetFile = getFileTask.get();
		}
		catch (Exception^)
		{
		}
	});
}