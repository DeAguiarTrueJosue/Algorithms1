#include "Entity.h"
#include "TextureManager.h"
#include <iostream>

void Entity::Initialize(const std::string& textureFilePath)
{
	mTextureID = TextureManager::Get()->LoadTexture(textureFilePath);
}

void Entity::Update()
{
	mPosition.x = rand() % 401 - 200;
	mPosition.y = rand() % 401 - 200;
}

void Entity::Render()
{
	std::cout << "x: " << mPosition.x << ", y: " << mPosition.y << std::endl;
	std::cout << "Sqrd distance to origin: " << SquaredDistance(mPosition) << std::endl;
	TextureManager::Get()->GetTexture(mTextureID).Print();
}
