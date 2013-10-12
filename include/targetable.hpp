#include<SFML/System.hpp>
#ifndef TARGETABLE_HPP
#define TARGETABLE_HPP

class Targetable {
public:
    virtual sf::Vector2f    getPosition() {}
};

#endif
