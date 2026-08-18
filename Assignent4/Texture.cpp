#include "Texture.h"
#include <iostream>

Texture::Texture(const std::string& filePath)
	:mFilePath(filePath)
{}

Texture::Texture()
	:mFilePath("")
{}

void Texture::Print() const
{
	std::cout << "Rendering: " << mFilePath << "\n";
}
