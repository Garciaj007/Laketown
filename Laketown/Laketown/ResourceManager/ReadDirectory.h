#ifndef READDIRECTORY_H
#define	READDIRECTORY_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace RESOURCE
{
	class ReadDirectory
	{
		typedef std::vector<std::string> stringVec;
	private:
		std::string stringObject;
		std::vector<std::string> nameFile;
	public:
		ReadDirectory();
		~ReadDirectory();
		void read_directory(const std::string& name, stringVec& v);
		void readFile(const std::string& name);
		inline std::vector<std::string>  returnFilenNames() { return nameFile;};
		void listFiles(std::string Directory_);
	};
#endif // ! READDIRECTORY_H
}