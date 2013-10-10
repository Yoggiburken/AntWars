#include<SFML/Graphics.hpp>
#include"clickable.hpp"

#ifndef BUTTON_HPP
#define BUTTON_HPP
class Button : public sf::Drawable, public Clickable{
private:
    sf::Sprite      sprite;
    virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    void            setPosition(sf::Vector2f position);
    void            setTexture(std::string hashname);
    //bool            isClicked(); 
};

#endif
