#include "FileReader.h"
#include "IFileType.h"

namespace RESOURCE
{
	FileReader::FileReader()
	{
	}
	void FileReader::createFile(IFileType* FileType_)
	{
		FileType_->createFile();
	}
	void FileReader::readFile(IFileType* FileType_)
	{
		FileType_->readFile();
	}
	void FileReader::FileWrite(IFileType* FileType_)
	{
		FileType_->WriteFile();
	}
	FileReader::~FileReader()
	{
	}

}