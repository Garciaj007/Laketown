#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <map>
#include <string>
#include <memory>

class CustomFileReader;
class ResourcesFactory;
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
		void I_createTexture(std::string namePath);
		void I_createAudio(std::string namepath);
		void I_createText(std::string namepath);
		void I_createVideo(std::string namepath);

		std::map<std::string, std::string> TextureAssetMap;
		std::map<std::string, std::string> AudioAssetMap; 
		//ResourceFactory<texture> textureFactory;
		//ResourceFactory<audio> audioFactory;
		//ResourceFactory<text> textFactory;
		//ResourceFactory<video> videoFactory;
		static ResourceManager* instance;
	public:
		ResourceManager();
		static std::shared_ptr<ResourceManager> getInstance();
		static void getTextureAssets(std::string Name_);
		static void setTextureAssetsMap(std::map<std::string, std::string> TextureAssets_);
		static void getAudioAssets(std::string Name_);
		static void getAudioAssetsMap(std::map<std::string, std::string> AudioAssets_);
		static void createTexture(std::string namePath);
		static void createAudio(std::string namepath);
		static void createText(std::string namepath);
		static void createVideo(std::string namepath);

		~ResourceManager();
	};
#endif 
}