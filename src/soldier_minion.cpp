#include<cmath>
#include"../include/soldier_minion.hpp"

using namespace sf;

extern Time             elapsed_time;

const unsigned short    SoldierMinion_base_damage   =   2;
const unsigned short    SoldierMinion_base_health   =   10;
const Vector2f          SoldierMinion_size(10,10);
extern const double            PI;

SoldierMinion::SoldierMinion(Color minion_color, Vector2f starting_position, unsigned int health_modifier, unsigned int damage_modifier)
{
    this->damage    	=   SoldierMinion_base_damage * damage_modifier;
    this->health    	=   SoldierMinion_base_health * health_modifier;

    this->body.setFillColor(minion_color);
    this->body.setPosition(starting_position);
    this->body.setSize(SoldierMinion_size);

    this->status                = IDLING;
    this->movement.next_move    = seconds(0);

    this->addSprite("friendly_soldierminion");
    this->actor_sprites[0].setOrigin(this->actor_sprites[0].getLocalBounds().width/2, this->actor_sprites[0].getLocalBounds().height/2);
    this->actor_sprites[0].setPosition(starting_position);
}

void SoldierMinion::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(this->body);
    target.draw(this->actor_sprites[0]);
}
void SoldierMinion::update()
{
    if(this->movement.next_move <= seconds(0)) {
        if(this->status == 0) {
			double x;
			x=100*cos((rand()%360)*PI/180)*pow(-1,rand()%2);
            this->movement.direction = Vector2f(x, sqrt((pow(100,2)-pow(x,2)))*pow(-1,rand()%2));
        }
        this->movement.next_move = milliseconds(2);
    }
    this->body.move(this->movement.direction*elapsed_time.asSeconds());
    this->actor_sprites[0].move(this->movement.direction*elapsed_time.asSeconds());
    this->movement.next_move -= elapsed_time;
}

void SoldierMinion::update(Vector2f squad_position)
{
	Vector2f distance_to_squad = this->actor_sprites[0].getPosition()-squad_position;
	if(pow(distance_to_squad.x, 2) + pow(distance_to_squad.y, 2) > 100) {
		if(this->status == 0) {
			double x = distance_to_squad.x/distance_to_squad.y;
			double y = distance_to_squad.y/distance_to_squad.y;
			this->movement.direction = Vector2f(100*x, 100*y);
		}
	}
    if(this->movement.next_move <= seconds(0)) {
        if(this->status == 0) {
			double x;
			x=100*cos((rand()%360)*PI/180)*pow(-1,rand()%2);
            this->movement.direction = Vector2f(x, sqrt((pow(100,2)-pow(x,2)))*pow(-1,rand()%2));
        }
        this->movement.next_move = milliseconds(2);
    }
    this->body.move(this->movement.direction*elapsed_time.asSeconds());
    this->actor_sprites[0].move(this->movement.direction*elapsed_time.asSeconds());
    this->movement.next_move -= elapsed_time;
}
