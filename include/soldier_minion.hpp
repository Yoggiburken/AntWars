#include<SFML/Graphics.hpp>
#include"minion.hpp"
#ifndef SOLDIER_MINION_HPP
#define SOLDIER_MINION_HPP

class SoldierMinion : public Minion {
private:
    int                     damage;

    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
                            SoldierMinion(sf::Color minion_color, sf::Vector2f starting_position, unsigned int health_modifier, unsigned int damage_modifier);
    virtual void            update();
    virtual void			update(sf::Vector2f squad_position);
	virtual void            attacked(int damage) {}

};

#endif
