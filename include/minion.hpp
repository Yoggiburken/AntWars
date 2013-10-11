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
    virtual void				update() {}
	virtual void				update(sf::Vector2f squad_position) {}
	virtual sf::Vector2f        getPosition() {}
};

#endif
