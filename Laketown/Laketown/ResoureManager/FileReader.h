#ifndef FILEREADER_H
#define FILEREADER_H
#include "IFileType.h"


using namespace std;

class FileReader : public IFileType
{
private:
	std::vector<T> ObjectArray;
public:
	FileReader();
	void createFile(IFileType FileType_);
	void FileWrite(IFileType FileType_);
	~FileReader();
};

#endif
