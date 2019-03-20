#include "ReadDirectory.h"
#include <fstream>
#include <filesystem>
#include <iterator>

namespace RESOURCE
{
	typedef std::vector<std::string> stringVec;
	ReadDirectory::ReadDirectory()
	{
	}
	struct path_leaf_string
	{
		std::string operator()(const std::filesystem::directory_entry& entry) const
		{
			return entry.path().string();
		}
	};
	void ReadDirectory::read_directory(const std::string& name, stringVec& v)
	{
		std::filesystem::path p(name);
		std::filesystem::directory_iterator start(p);
		std::filesystem::directory_iterator end;
		std::transform(start, end, std::back_inserter(v), path_leaf_string());
	}
	void ReadDirectory::readFile(const std::string& name)
	{
		std::ifstream fileName(name);
		if (!fileName)
		{
			std::cerr << "Unable to open txt file.";
			exit(1);// call system to stop
		}
		else if (fileName)
		{
			while (fileName >> stringObject)
			{
				std::cout << stringObject << std::endl;
			}
		}
	}
	void ReadDirectory::listFiles(std::string Directory_)
	{
		stringVec v;
		//std::vector<Tile*> ObjectList;
		std::string rootDirectory;
		rootDirectory = Directory_;
		read_directory(Directory_, v);
		std::copy(v.begin(), v.end(),
			std::ostream_iterator<std::string>(std::cout, "\n"));
		std::vector<std::string> fileList = v;
		nameFile = fileList;
		printf("Loading in File Level... \n");
		printf("Here are the files: \n");

	}
	ReadDirectory::~ReadDirectory()
	{
	}
}