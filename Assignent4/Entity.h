#pragma once
#include <Vector2.h>
#include <string>

class Entity
{
	private:
		static float SquaredDistance(const Vector2& vec)
		{
			return vec.x * vec.x + vec.y * vec.y;
		}
public:
	void Initialize(const std::string& textureFilePath);

	void Update();

	void Render();

	struct ClosestToCenter
	{
	public:
		bool operator()(const Entity& a, const Entity& b)
		{
			return SquaredDistance(b.mPosition) < SquaredDistance(a.mPosition);
		}
	};

private:
	int mTextureID;
	Vector2 mPosition;
};
