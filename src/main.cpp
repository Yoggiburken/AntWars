#include"../include/TextureClass.hpp"
#include"../include/World.hpp"

using namespace sf;

extern const double PI = 3.14159265359; 

RenderWindow app(VideoMode(800,600,32), "ClickAttack");
Event event;
Time  elapsed_time;

TextureClass TextureBucket;
World world;

int main()
{
	app.setVerticalSyncEnabled(true);
    world.intro();
	world.game();

	return 0;
}
