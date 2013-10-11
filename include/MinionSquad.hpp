#include<vector>
#include"minion.hpp"

#ifndef MINION_SQUAD_HPP
#define MINION_SQUAD_HPP
class MinionSquad : public sf::Drawable, public Targetable {
private:
	std::vector<Minion*>		squad;
	int 						max_size;
	MinionMovement				movement;
	MinionStatus				status;
	sf::Vector2f				position;
	Targetable*					target;

	sf::CircleShape			body;
	
	virtual void				draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
								MinionSquad(sf::Vector2f position, int size);
	void						addMinion(Minion* minion);
	void						update();
	
	Minion&						getRandomMinion();
	bool						isFull();
};
#endif
