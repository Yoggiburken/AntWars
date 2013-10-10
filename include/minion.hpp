#include<SFML/Graphics.hpp>
#include"actor.hpp"
#include"targetable.hpp"

#ifndef MINION_HPP
#define MINION_HPP

#ifndef MINION_MOVEMENT
#define MINION_MOVEMENT
struct MinionMovement {
    sf::Vector2f                direction;
    sf::Time                    next_move;
};
#endif

#ifndef MINION_STATUS
#define MINION_STATUS
enum Status {IDLING=0, ATTACKING=1, DEFENDING=2};
#endif

class Minion : public Actor, public Targetable{
protected:    
    unsigned int                health;
    MinionMovement              movement;
    Status                      status;

    Targetable*                 target;

    sf::RectangleShape          body;

    virtual void                draw(sf::RenderTarget &target, sf::RenderStates states) const {target.draw(body);}
public:
    virtual void                update() {}
    virtual sf::Vector2f        getPosition() { return this->body.getPosition(); }
};

#endif
