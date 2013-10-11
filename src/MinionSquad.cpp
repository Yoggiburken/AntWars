#include<cmath>
#include"../include/MinionSquad.hpp"

using namespace sf;

extern const double PI;

extern Time 		elapsed_time;

MinionSquad::MinionSquad(Vector2f position, int size)
{
	this->position 	= position;
	this->max_size 	= size;
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
			x=100*cos((rand()%360)*PI/180)*pow(-1,rand()%2);
            this->movement.direction = Vector2f(x, sqrt((pow(100,2)-pow(x,2)))*pow(-1,rand()%2));
        }
        this->movement.next_move = milliseconds(2);
    }
	this->position = this->movement.direction * elapsed_time.asSeconds();

	for(int i=0; i<this->squad.size(); i++) {
		this->squad[i]->update(this->position);
	}
}

void MinionSquad::draw(RenderTarget& target, RenderStates states) const
{
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

Minion& MinionSquad::getRandomMinion()
{
	return *this->squad[rand()%this->squad.size()];
}
	
	bool						isFull();
