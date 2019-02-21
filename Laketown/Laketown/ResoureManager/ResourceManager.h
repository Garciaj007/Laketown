#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <map>
#include <string>
#include <memory>

class CustomFileReader;
using namespace std;

namespace RESOURCE
{
	class ResourceManager
	{
	private:
		void I_insertTextureAsset(std::string Key_, std::string AssetNamePath_);
		void I_insertAudioAsset(std::string Key_, std::string AssetNamePath_);
		void I_getTextureAsset(std::string Name_);
		void I_setTextureAssetMap(std::map<std::string, std::string> TextureAsset_);
		void I_getAudioAsset(std::string Name_);
		void I_setAudioAssetMap(std::map<std::string, std::string> AudioAsset_);

		std::map<std::string, std::string> TextureAssetMap;
		std::map<std::string, std::string> AudioAssetMap; 
		static ResourceManager* instance;
	public:
		ResourceManager();
		static std::shared_ptr<ResourceManager> getInstance();
		static void getTextureAssets(std::string Name_);
		static void setTextureAssetsMap(std::map<std::string, std::string> TextureAssets_);
		static void getAudioAssets(std::string Name_);
		static void getAudioAssetsMap(std::map<std::string, std::string> AudioAssets_);
		

		~ResourceManager();
	};
#endif 
}