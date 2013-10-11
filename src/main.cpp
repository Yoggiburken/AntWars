#include<fstream>
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
	bool show_introscreen = true;
	std::ifstream file;
	file.open("properties.conf");
	while(!file.eof()) {
		std::string parse;
		file>>parse;
		if(parse == "introscreen") {
			file>>parse;
			file>>parse;
			if(parse == "false") {
				show_introscreen = false;
			}
		}
	}
	app.setVerticalSyncEnabled(true);
    if(show_introscreen) {
		world.intro();
	}
	world.game();

	return 0;
}
