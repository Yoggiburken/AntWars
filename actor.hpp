#include<SFML/Graphics.hpp>
#include<vector>

#ifndef ACTOR_HPP
#define ACTOR_HPP

class Actor : public sf::Drawable {
protected:
    std::vector<sf::Sprite> actor_sprites;
    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void                    addSprite(std::string texture_name);
    void                    addSprite(sf::Sprite& sprite);
public:
};

#endif
