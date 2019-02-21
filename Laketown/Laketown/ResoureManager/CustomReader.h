#ifndef CUSTOMREADER_H
#define CUSTOMREADER_H
#include <map>
#include <memory>
class FileReader;
class ReadDirectory;

using namespace std;

namespace RESOURCE
{
	
	class CustomReader
	{
	private:
		std::map<std::string, FileReader>FileReaderlist;
		std::shared_ptr<ReadDirectory*> Directory;
	public:
		CustomReader(std::shared_ptr<ReadDirectory*> Directory_);
		void setFileReaderList(std::map<std::string, FileReader> FileReaderList_);
		void insertFileReader(FileReader* FileReader_);
		void setRDirectory(std::shared_ptr<ReadDirectory*> RDirectory_);
		std::map<std::string, FileReader> returnFileReaderList();
		std::shared_ptr<const ReadDirectory*> returnDirectory() const;
		~CustomReader();
	};
#endif 
}