#include<SFML/Graphics.hpp>
#include"targetable.hpp"

#ifndef MINION_BASE_HPP
#define MINION_BASE_HPP

class MinionBase : public sf::Drawable, Targetable, Clickable{
private:
    unsigned long           click_count;

    int                     hp;
    sf::RectangleShape      body;
    
    unsigned short          minion_damage_modifier;
    unsigned short          minion_health_modifier;

    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const {target.draw(body);}
public:
                            MinionBase(sf::Vector2f start_position, sf::Color base_color);
    void                    update();
    bool                    isClicked();
    sf::Vector2f            getPosition();
};

#endif
