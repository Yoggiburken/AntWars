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

	this->body.setRadius(100);
	this->body.setFillColor(Color(0,0,150,150));
	this->body.setOrigin(100,100);
	this->body.setPosition(this->position);
}

void MinionSquad::addMinion(Minion* minion)
{
	this->squad.push_back(minion);
}

void MinionSquad::update()
{
    this->movement.next_move -= elapsed_time;
    if(this->movement.next_move <= seconds(0)) {
        if(this->status == 0) {
			double x;
			x=50*cos((rand()%360)*PI/180)*pow(-1,rand()%2);
            this->movement.direction = Vector2f(x, sqrt((pow(50,2)-pow(x,2)))*pow(-1,rand()%2));
        }
        this->movement.next_move = seconds(2);
    }
	this->position = this->position + this->movement.direction*elapsed_time.asSeconds();
	this->body.setPosition(this->position);
	for(int i=0; i<this->squad.size(); i++) {
		this->squad[i]->update(this->position);
	}
}

void MinionSquad::draw(RenderTarget& target, RenderStates states) const
{
	for(int i=0; i<squad.size(); i++) {
		target.draw(*squad[i]);
	}
	target.draw(this->body);
}

bool MinionSquad::isFull()
{
	if(this->squad.size() == this->max_size) {
		return true;
	}
	return false;
}

Minion& MinionSquad::getRandomMinion()
{
	return *this->squad[rand()%this->squad.size()];
}
	
	bool						isFull();
