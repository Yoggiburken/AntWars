#include"../include/UI.hpp"
#include"../include/TextureClass.hpp"

using namespace sf;

extern RenderWindow app;

UI::UI()
{
    this->blue_button.setTexture("blue_button");
    this->blue_button.setPosition(Vector2f(0,600-blue_button.getLocalBounds().height));
	
	this->view.setSize(800,600);
	this->view.setCenter(400,300);
    this->font.loadFromFile("resources/VT323-Regular.ttf");
}


void UI::draw(RenderTarget& target, RenderStates states) const
{
    View foo = app.getView();   
    target.setView(this->view);
    target.draw(this->blue_button);
    for(int i=0; i<texts.size(); i++) {
        target.draw(*texts[i]);
    }
    target.setView(foo);
}

void UI::addStaticText(std::string text_string, Vector2f position)
{
    Text* text = new Text(text_string, this->font, 18);
    text->setPosition(position);
    texts.push_back(text); 
}

void UI::addTextPointer(Text* text)
{
    texts.push_back(text);
}
