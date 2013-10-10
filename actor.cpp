#include"TextureClass.hpp"
#include"actor.hpp"

using namespace sf;

extern TextureClass TextureBucket;

void Actor::draw(RenderTarget& target, RenderStates states) const
{
}

void Actor::addSprite(std::string texture_name)
{
    Sprite* sprite = new Sprite;
    sprite->setTexture(TextureBucket.getTexture("friendly_soldierminion"));
    this->actor_sprites.push_back(*sprite);
}

void Actor::addSprite(Sprite& sprite)
{
    this->actor_sprites.push_back(sprite);
}
