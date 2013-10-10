#include<SFML/Graphics.hpp>
#include<vector>
#include"button.hpp"
#ifndef UI_HPP
#define UI_HPP
class UI : public sf::Drawable {
private:
    Button                      blue_button;

    sf::Font                    font;
    std::vector<sf::Text*>      texts;
    
    sf::View                    view;

    virtual void                draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
                                UI();
    void                        addText(std::string text, sf::Vector2f postition);
    void                        addTextPointer(sf::Text* text);
};

#endif
