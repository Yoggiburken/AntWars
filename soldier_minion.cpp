#include<cmath>
#include"soldier_minion.hpp"

using namespace sf;

extern Time             elapsed_time;

const unsigned short    SoldierMinion_base_damage   =   2;
const unsigned short    SoldierMinion_base_health   =   10;
const Vector2f          SoldierMinion_size(10,10);
const double            PI = 3.14159265359;

SoldierMinion::SoldierMinion(Color minion_color, Vector2f starting_position, unsigned int health_modifier, unsigned int damage_modifier)
{
    this->damage    =   SoldierMinion_base_damage * damage_modifier;
    this->health    =   SoldierMinion_base_health * health_modifier;

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
            this->movement.direction = Vector2f(100*cos((rand()%360)*PI/180), 100*sin((rand()%360)*PI/180));
        }
        this->movement.next_move = seconds(2);
    }
    this->body.move(this->movement.direction*elapsed_time.asSeconds());
    this->actor_sprites[0].move(this->movement.direction*elapsed_time.asSeconds());
    this->movement.next_move -= elapsed_time;
}
