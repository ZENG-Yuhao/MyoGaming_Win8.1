#pragma once
#include "pch.h"
class FileManager
{
public:
	Windows::Storage::StorageFile^ targetFile;
	Platform::String^ returnContent;
	FileManager();
	~FileManager();
	void CreateFile(Platform::String^ fileName);
	void WriteToFile(Platform::String^ content);
	Platform::String^ ReadFromFile();

	void ValidateFile(Platform::String ^ filename);


};


