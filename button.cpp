#include"TextureClass.hpp"
#include"button.hpp"

extern TextureClass TextureBucket;

using namespace sf;
using namespace std;

void Button::setTexture(string hashname)
{
    sprite.setTexture(TextureBucket.getTexture(hashname));
}

void Button::setPosition(Vector2f position)
{
    sprite.setPosition(position);
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(sprite);
}

/*bool Button::isClicked()
{
    if(Mouse::isButtonClicked(Mouse::Left)) {
        Vector2f mouse_pos      = app.mapPixelToCoords(Mouse::getPosition(app));
        Vector2f button_pos     = this->sprite.getPosition();
        Vector2f button_size    = Vector2f(this->sprite.getLocalBounds().width, this->sprite.getLocalBounds().height);
    
        
    }
}*/
