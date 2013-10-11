#include<cmath>
#include<iostream>
#include<sstream>
#include"../include/World.hpp"
#include"../include/TextureClass.hpp"

using namespace sf;

extern RenderWindow 	app;
extern Event        	event;
extern Time         	elapsed_time;
extern TextureClass 	TextureBucket;

std::string itoa(double num)
{
    std::stringstream ss;
    ss<<num;
    std::string s = ss.str();

    return s;
}

void World::intro()
{
    this->view.setCenter(400,300);
    this->view.setSize(800,600);
	app.setView(this->view);
	Sprite firecan;
	firecan.setTexture(TextureBucket.getTexture("firecan"));
	firecan.setOrigin(firecan.getLocalBounds().width/2, firecan.getLocalBounds().height/2);
	firecan.setPosition(400, 300);
	Time	intro_time = seconds(4);
	Clock 	clock;

	double opacity = 255;

	RectangleShape filter;
	filter.setFillColor(Color(255,255,255,opacity));
	filter.setSize(Vector2f(800,600));
	filter.setOrigin(400,300);
	filter.setPosition(400,300);

	while(intro_time > seconds(0)) 
	{
		elapsed_time = clock.restart();
		intro_time -= elapsed_time;
		if(opacity >= 0) {
			opacity -= 255/2*elapsed_time.asSeconds();
			if(opacity < 0) {
				opacity = 0;
			}
		}
		filter.setFillColor(Color(255,255,255,opacity));
		app.clear(Color::White);
		app.draw(firecan);
		app.draw(filter);
		app.display();
	}
}

void World::game()
{
    this->map_scroll_speed = 300;
    MinionBase base(Vector2f(400,300), Color(Color::Green));
    friendly_bases.push_back(&base);
    bool game = true;
    srand(time(NULL));
    
    Font    font;
    font.loadFromFile("../resources/VT323-Regular.ttf");
    Text no_minions("0",font);
    no_minions.setPosition(0,0);
    no_minions.setColor(Color::Black);
    ui.addTextPointer(&no_minions);
    
    this->current_zoom = 1;
    this->view.setCenter(400,300);
    this->view.setSize(800,600);
    app.setView(this->view);
    Clock clock;
    while(app.isOpen())
    {
        while(app.pollEvent(event))
        {
            if(event.type == Event::Closed) {
                app.close();
            }
            if(event.type == Event::Resized) {
                this->view.setSize(event.size.width, event.size.height);
                app.setView(view);
            }
            if(event.type == Event::MouseWheelMoved) {
                this->current_zoom =this->current_zoom*(1+0.2*event.mouseWheel.delta*elapsed_time.asSeconds());
                this->view.zoom(1+0.2*event.mouseWheel.delta*elapsed_time.asSeconds());
                event.mouseWheel.delta = 0;
            }
        }
        
        elapsed_time = clock.restart(); 
        //read input
        this->input();
        //update all actors
		no_minions.setString(itoa(this->getNumberOfMinions()));
		     
        this->update();   
        //clear screen
        app.clear(Color::White);
        
        //draw all 
        for(int i=0; i<this->enemy_bases.size(); i++) {
            app.draw(*this->enemy_bases[i]);
        }
        for(int i=0; i<this->friendly_bases.size(); i++) {
            app.draw(*this->friendly_bases[i]);
        }
        for(int i=0; i<this->enemy_minions.size(); i++) {
            for(int j=0; i<this->enemy_minions[i].size(); j++) {
                app.draw(*this->enemy_minions[i][j]);
            }
        }
        for(int i=0; i<this->friendly_squads.size(); i++) {
            app.draw(this->friendly_squads[i]);
        }
        app.draw(ui);
        //display frame
        app.display();
    }
}

void World::input()
{
	if(Keyboard::isKeyPressed(Keyboard::Escape)) {
		app.close();	
	}
	
    if(Keyboard::isKeyPressed(Keyboard::W)) {
    	this->view.move(0,-this->map_scroll_speed*elapsed_time.asSeconds());
    }
    if(Keyboard::isKeyPressed(Keyboard::S)) {
        this->view.move(0,this->map_scroll_speed*elapsed_time.asSeconds());
    }
    if(Keyboard::isKeyPressed(Keyboard::A)) {
        this->view.move(-this->map_scroll_speed*elapsed_time.asSeconds(),0);
    }
    if(Keyboard::isKeyPressed(Keyboard::D)) {
        this->view.move(this->map_scroll_speed*elapsed_time.asSeconds(),0);
    }
    if(Keyboard::isKeyPressed(Keyboard::R)) {
        this->view = app.getDefaultView();
        this->view.zoom(this->current_zoom);
    }

    for(int i=0; i<friendly_bases.size(); i++) {
        if(friendly_bases[i]->isClicked()) {
            this->spawnFriendlySoldierminion(i);
        }
    }
    app.setView(this->view);
}

void World::update()
{
    for(int i=0; i<this->friendly_bases.size(); i++) {
        this->friendly_bases[i]->update();
    }
    for(int i=0; i<this->friendly_squads.size(); i++) {
        this->friendly_squads[i].update();
    }
}

void World::spawnFriendlySoldierminion(int base_number)
{
    Minion* minion;
    minion = new SoldierMinion(Color(Color::Black), Vector2f(friendly_bases[base_number]->getPosition()), 1, 1);
	
	if(friendly_squads.size() > 0) {
		for(int i=0; i<friendly_squads.size(); i++) {
			if(!friendly_squads[i].isFull()) {
				Vector2f distance_to_base = friendly_squads[i].getPosition() - friendly_bases[base_number]->getPosition();
				if(sqrt(pow(distance_to_base.x, 2) + pow(distance_to_base.x, 2)) < 3000) {
					friendly_squads[i].addMinion(minion);
					return;
				}
			}
		}
	}
	friendly_squads.push_back(MinionSquad(this->friendly_bases[base_number]->getPosition(), 5));
	friendly_squads[friendly_squads.size()-1].addMinion(minion);
}

int World::getNumberOfMinions()
{
	int no_minions =0;
	for(int i=0; i<friendly_squads.size(); i++) {
		no_minions +=this->friendly_squads[i].getNumberOfMinions();
	}
	return no_minions;
}
