#include"actor.hpp"

#ifndef LASER_HPP
#define LASER_HPP
class Laser : public Actor {
private:
	sf::Time		lifetime;
public:
					Laser(sf::Vector2f start, sf::Vector2f stop);

};
#endif
