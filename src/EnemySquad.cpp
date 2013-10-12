#include"../include/EnemySquad.hpp"

using namespace sf;

EnemySquad::EnemySquad(Vector2f position)
{
	this->position = position;
}

void EnemySquad::setPosition(Vector2f position)
{
	this->position = position;
}

Vector2f EnemySquad::getPosition()
{
	return this->position;
}

void EnemySquad::addMinion(EnemyMinion &minion)
{
	this->squad.push_back(minion);
}

void EnemySquad::removeMinion(int index)
{
	this->squad.erase(this->squad.begin()+index);
}
