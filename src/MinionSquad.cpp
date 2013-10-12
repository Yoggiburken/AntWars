#include<cmath>
#include"../include/MinionSquad.hpp"

using namespace sf;

extern const double PI;

extern Time 		elapsed_time;

MinionSquad::MinionSquad(Vector2f position, int size)
{
	this->position 	= position;
	this->max_size 	= size;

	this->movement.next_move = seconds(1);
	this->status = IDLING;

	this->body.setRadius(75);
	this->body.setFillColor(Color(0,0,150,150));
	this->body.setOrigin(75,75);
	this->body.setPosition(this->position);
}

void MinionSquad::addMinion(Minion* minion)
{
	this->squad.push_back(minion);
}

void MinionSquad::update()
{
	if(this->squad.size() > 0) {
		this->squad[0]->update();
	}
	this->position	= this->squad[0]->getPosition();
	this->body.setPosition(this->position);
	
	for(int i=1; i<this->squad.size(); i++) {
		this->squad[i]->update(this->position, this->movement.direction);
	}
}

void MinionSquad::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(this->body);
	for(int i=0; i<squad.size(); i++) {
		target.draw(*squad[i]);
	}
}

bool MinionSquad::isFull()
{
	if(this->squad.size() == this->max_size) {
		return true;
	}
	return false;
}

int MinionSquad::getNumberOfMinions()
{
	return this->squad.size();
}

Vector2f MinionSquad::getMinionPosition(int index)
{
	return this->squad[index]->getPosition();
}
