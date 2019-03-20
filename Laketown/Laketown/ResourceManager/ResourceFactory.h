#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H
#include <string>
#include <vector>
#include "ReadDirectory.h"

template<class T> 
class ResourceFactory
{
private:
	ReadDirectory DirPath = new ReadDirectory();
public:		
	ResourceFactory()
	{
	}
	T CreateAsset(std::string PathName)
	{
		return T.CreateAsset(PathName);
	}
	std::vector<T> CreateAssetArray(std::string PathName, int numOfObjects)
	{
		std::vector<T> objectArray = new std::vector<T>();
		for (i = 0; i < numOfObjects; i++)
		{
			objectArray.push_back(T.CreateAsset(PathName));
		}
		return objectArray;
	}
	~ResourceFactory()
	{
	}
};
#endif

