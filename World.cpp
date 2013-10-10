#include<iostream>
#include<sstream>
#include"World.hpp"

using namespace sf;

extern RenderWindow app;
extern Event        event;
extern Time         elapsed_time;

std::string itoa(double num)
{
    std::stringstream ss;
    ss<<num;
    std::string s = ss.str();

    return s;
}

void World::game()
{
    this->map_scroll_speed = 300;
    MinionBase base(Vector2f(100,100), Color(Color::Green));
    friendly_bases.push_back(&base);
    bool game = true;
    srand(time(NULL));
    
    Font    font;
    font.loadFromFile("resources/VT323-Regular.ttf");
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
        
        no_minions.setString(itoa(this->friendly_minions.size()));
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
        for(int i=0; i<this->friendly_minions.size(); i++) {
            app.draw(*this->friendly_minions[i]);
        }
        app.draw(ui);
        //display frame
        app.display();
    }
}

void World::input()
{
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
    for(int i=0; i<this->friendly_minions.size(); i++) {
        this->friendly_minions[i]->update();
    }
}

void World::spawnFriendlySoldierminion(int i)
{
    Minion* minion;
    minion = new SoldierMinion(Color(Color::Black), Vector2f(friendly_bases[i]->getPosition()), 1, 1);
    this->friendly_minions.push_back(minion);
}
