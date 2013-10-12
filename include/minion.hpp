#include<SFML/Graphics.hpp>
#include"actor.hpp"
#include"targetable.hpp"
#include"MinionStatus.hpp"

#ifndef MINION_HPP
#define MINION_HPP

class Minion : public Actor, public Targetable{
protected:    
    unsigned int                health;
    MinionMovement              movement;
    MinionStatus               	status;

    Targetable*                 target;


    virtual void                draw(sf::RenderTarget &target, sf::RenderStates states) const {}
public:
    virtual void				attacked(unsigned int damage) {}
	virtual void				update() {}
	virtual void				update(sf::Vector2f squad_position, sf::Vector2f squad_direction) {}
	virtual sf::Vector2f        getPosition() {return this->actor_sprites[0].getPosition();}
};

#endif
