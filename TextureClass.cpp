#include<fstream>
#include"TextureClass.hpp"

using namespace std;

TextureClass::TextureClass()
{
    string filepath, hashname;
    ifstream file;
    file.open("textures.txt");
    
    sf::Texture temp;

    while(!file.eof())
    {   
        file>>hashname>>filepath; 
        temp.loadFromFile(filepath.c_str());
        textures.insert( std::pair<std::string, sf::Texture>(hashname, temp));
    }
}

sf::Texture& TextureClass::getTexture(std::string textureID)
{
    return textures[textureID.c_str()];
}
