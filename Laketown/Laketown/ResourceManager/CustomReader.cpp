#include "CustomReader.h"

namespace RESOURCE
{
	CustomReader::CustomReader(std::shared_ptr<ReadDirectory*> Directory_)
	{
		//default constructor that sets the DirectoryReader.
		setRDirectory(Directory_);
	}
	void CustomReader::setFileReaderList(std::map<std::string, FileReader> FileReaderList_)
	{
		//This set the map.
	}
	void CustomReader::insertFileReader(FileReader* FileReader_)
	{
		//This will insert how the FileReader to the custom map.

	}
	void CustomReader::setRDirectory(std::shared_ptr<ReadDirectory*> Directory_)
	{
		//Set Directory;
		Directory = Directory_;
	}
	std::map<std::string, FileReader> CustomReader::returnFileReaderList()
	{
		//return FileReader Map.
		return FileReaderlist;
	}
	std::shared_ptr<ReadDirectory*> CustomReader::returnDirectory() const
	{
		//return ReadDirectory.
		return Directory;
	}
	CustomReader::~CustomReader()
	{
	}
}
