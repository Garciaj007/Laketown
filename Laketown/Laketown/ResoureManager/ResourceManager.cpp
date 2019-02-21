#include "ResourceManager.h"

namespace RESOURCE
{
	ResourceManager* ResourceManager::instance = nullptr;
	ResourceManager::ResourceManager()
	{
		getInstance();
	}
	std::shared_ptr<ResourceManager> ResourceManager::getInstance()
	{
		if (!instance)
		{
			instance = new ResourceManager();
		}
		return std::shared_ptr<ResourceManager>(instance);
	}
	 void ResourceManager::getTextureAssets(std::string Name_)
	{
		//calls the instance for private method.
		 instance->I_getTextureAsset(Name_);
	}
	 void ResourceManager::setTextureAssetsMap(std::map<std::string, std::string> TextureAssets_)
	{
		 //calls the instance for private method.
		 instance->I_setTextureAssetMap(TextureAssets_);
	}
	 void ResourceManager::getAudioAssets(std::string Name_)
	{
		 //calls the instance for private method.
		 instance->I_getAudioAsset(Name_);
	}
	 void ResourceManager::getAudioAssetsMap(std::map<std::string, std::string> AudioAssets_)
	{
		 //calls the instance for private method.
		 instance->getAudioAssetsMap(AudioAssets_);
	}
	void ResourceManager::I_insertTextureAsset(std::string Key_, std::string AssetNamePath_)
	{
		//Insert the asset by the key and string path.
	}
	void ResourceManager::I_insertAudioAsset(std::string Key_, std::string AssetNamePath_)
	{
		//Insert the asset by the key and the string path.
	}
	void ResourceManager::I_getTextureAsset(std::string Name_)
	{
		//Get the Texture from the texture map.
	}
	void ResourceManager::I_setTextureAssetMap(std::map<std::string, std::string> TextureAsset_)
	{
		//Sets the Map for the Texture map
	}
	void ResourceManager::I_getAudioAsset(std::string Name_)
	{
		//Get Audio asset by key string. 
	}
	void ResourceManager::I_setAudioAssetMap(std::map<std::string, std::string> AudioAsset_)
	{
		//Sets the Map for the Audio map.
	}
	ResourceManager::~ResourceManager()
	{
		//Delete any pointers.
		instance = nullptr;
		delete instance;
	}

}

