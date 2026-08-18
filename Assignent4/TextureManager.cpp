#include "TextureManager.h"
#include <Global.h>

TextureManager* TextureManager::Get()
{
	static TextureManager sInstance;
	return &sInstance;
}

size_t TextureManager::LoadTexture(const std::string& filePath)
{
	size_t hash = Global::HashFunction(filePath);

	mTextures[hash] = Texture(filePath);

	return hash;
}

Texture& TextureManager::GetTexture(const size_t hash)
{
	return mTextures[hash];
}
