#include"../include/World.hpp"
#include"../include/minion_base.hpp"
#include"../include/soldier_minion.hpp"

using namespace sf;

extern RenderWindow app;

const long              Minionbase_click_count = 0;
const int               MinionBase_base_health = 1000;
const short             MinionBase_minion_damage_modifier = 1;
const short             MinionBase_minion_health_modifier = 1;
const sf::Vector2f      MinionBase_size(100,100);

MinionBase::MinionBase(sf::Vector2f starting_position, sf::Color MinionBase_color)
{  
    this->click_count = 0;
     
    this->hp = MinionBase_base_health;

    this->minion_damage_modifier = MinionBase_minion_damage_modifier;
    this->minion_health_modifier = MinionBase_minion_health_modifier;
    
    this->body.setPosition(starting_position);
    this->body.setFillColor(MinionBase_color);
    this->body.setSize(MinionBase_size);
    this->body.setOrigin(this->body.getSize().x/2, this->body.getSize().y/2);
}

void MinionBase::update()
{}

bool MinionBase::isClicked()
{
    if(Mouse::isButtonPressed(Mouse::Left) && !this->mouse_down) {
        mouse_down = true;
        Vector2f mouse_pos  = (Vector2f)app.mapPixelToCoords(Mouse::getPosition(app));
        Vector2f base_pos   = body.getPosition();
        Vector2f base_size  = body.getSize();

        if(mouse_pos.x >= base_pos.x - base_size.x/2 && mouse_pos.x <= base_pos.x + base_size.x/2) {
            if(mouse_pos.y >= base_pos.y - base_size.y/2 && mouse_pos.y <= base_pos.y + base_size.y/2) {
                return true;
            }
        }
    } if(!Mouse::isButtonPressed(Mouse::Left)) {
        this->mouse_down = false;
    }
    return false;
}

Vector2f MinionBase::getPosition()
{
    return body.getPosition();
}
