#include<map>
#include<SFML/Graphics.hpp>

#ifndef TEXTURECLASS_HPP
#define TEXTURECLASS_HPP
class TextureClass {
private:
    std::map<std::string, sf::Texture> textures;
public:
    TextureClass();
    sf::Texture&    getTexture(std::string textureID);

};
#endif
