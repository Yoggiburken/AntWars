#include"TextureClass.hpp"
#include"World.hpp"

using namespace sf;

RenderWindow app(VideoMode(800,600,32), "ClickAttack");
Event event;
Time  elapsed_time;

TextureClass TextureBucket;
World world;

int main()
{
    app.setVerticalSyncEnabled(true);
    world.game();

	return 0;
}
