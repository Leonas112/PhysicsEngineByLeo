#include "GameObject.h"

std::map<char, bool> GameObject::keys;
std::map<int, bool> GameObject::specialKeys;

GameObject::GameObject(Vec3 _position, Vec3 _colour)
{
	position = _position;
	colour = _colour;
}

GameObject::~GameObject()
{
}

Collider* GameObject::GetCollider()
{
	return nullptr;
}