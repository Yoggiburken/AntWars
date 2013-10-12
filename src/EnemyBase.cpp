#include"../include/EnemyBase.hpp"

using namespace sf;

EnemyBase::EnemyBase(Vector2f position)
{
	this->position = position;
}

Vector2f EnemyBase::getPosition()
{
	return this->position;
}
