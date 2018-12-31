#pragma once

#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"

struct Material
{
	Color ambient = {1.0f, 0.5f, 0.31f};
	Color diffuse = {1.0f, 0.5f, 0.31f};
	Color specular = {0.5f, 0.5f, 0.5f};
	float shininess = 32.0f;
};

class Object 
{
public:
	Object(const char* fileName,
		const char* textureName = nullptr, 
		const char* specularMap = nullptr,
		const char* normapMap = nullptr);
	Object(Object&& other);
	~Object();

	Mesh* GetMesh() const;
	Texture* GetDiffuseMap() const;
	Texture* GetSpecularMap() const;
	Texture* GetNormalMap() const;

	Material GetMaterial() const;
	Transform GetTransform() const;

	void SetMaterial(const Material& transform);
	void SetTransform(const Transform& transform);

	void SetPosition(const Vector3f& pos);

	void Move(const Vector3f& dR);
	void Rotate(const Vector3f& dR);
	void Scale(const Vector3f& dR);
private:
	Mesh* mesh;
	Texture* texture;
	Texture* specularMap;
	Texture* normalMap;

	Material material;

	Transform transform;
};