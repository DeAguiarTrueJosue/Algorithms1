#pragma once
#include "Texture.h"
#include <UnorderedMap.h>

class TextureManager
{
public:
	static TextureManager* Get();

	size_t LoadTexture(const std::string& filePath);

	Texture& GetTexture(const size_t hash);

private:
	UnorderedMap<size_t, Texture> mTextures;
};