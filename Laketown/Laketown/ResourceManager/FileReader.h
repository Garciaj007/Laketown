#ifndef FILEREADER_H
#define FILEREADER_H
#include "IFileType.h"
#include <vector>

using namespace std;

namespace RESOURCE
{
	class FileReader
	{
	private:
		//std::vector<T> ObjectArray;
	public:
		FileReader();
		void createFile(IFileType* FileType_);
		void readFile(IFileType* FileType_);
		void FileWrite(IFileType* FileType_);
		~FileReader();
	};

#endif
}