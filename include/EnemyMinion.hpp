#include"actor.hpp"

#ifndef ENEMYMINION_HPP
#define ENEMYMINION_HPP
class EnemyMinion : public Actor {
public:
					EnemyMinion(sf::Vector2f position);
	void			setPosition(sf::Vector2f position);
	sf::Vector2f	getPosition();
};
#endif
