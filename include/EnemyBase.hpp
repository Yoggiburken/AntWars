#include"targetable.hpp"

#ifndef ENEMY_BASE_HPP
#define ENEMY_BASE_HPP
class EnemyBase : public Targetable {
private:
	sf::Vector2f			position;
public:
							EnemyBase(sf::Vector2f position);
	virtual sf::Vector2f	getPosition();
};
#endif
