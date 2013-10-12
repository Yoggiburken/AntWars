#include"../include/TextureClass.hpp"
#include"../include/EnemyMinion.hpp"

using namespace sf;

extern TextureClass	TextureBucket;

EnemyMinion::EnemyMinion(Vector2f position)
{
	Sprite sprite;
	sprite.setTexture(TextureBucket.getTexture("friendly_soldierminion"));
	sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
	sprite.setPosition(position);
	this->actor_sprites.push_back(sprite);
}

void EnemyMinion::setPosition(Vector2f position)
{
	for(int i=0; i<actor_sprites.size(); i++) {
		this->actor_sprites[i].setPosition(position);
	}
}
