#include<vector>
#include<SFML/System.hpp>
#include"targetable.hpp"
#include"EnemyMinion.hpp"

#ifndef ENEMYSQUAD_HPP
#define ENEMYSQUAD_HPP
class EnemySquad : public Targetable {
public:
	std::vector<EnemyMinion>			squad;
	sf::Vector2f						position;

										EnemySquad(sf::Vector2f position);

	void								setPosition(sf::Vector2f position);
	virtual sf::Vector2f				getPosition();

	void								addMinion(EnemyMinion& minion);
	void								removeMinion(int index);
};
#endif
