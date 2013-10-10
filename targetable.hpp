
#ifndef TARGETABLE_HPP
#define TARGETABLE_HPP

class Targetable {
public:
    virtual void            attacked(int damage) {}
    virtual sf::Vector2f    getPosition() {}
};

#endif
