#include<vector>
#include"UI.hpp"
#include"soldier_minion.hpp"
#include"minion_base.hpp"


#ifndef WORLD_HPP
#define WORLD_HPP
class World {
private:
    double                                      map_scroll_speed;
    double                                      current_zoom;    
    UI                                          ui;

    std::vector<MinionBase*>                    enemy_bases;
    std::vector<MinionBase*>                    friendly_bases;
    std::vector<std::vector<Minion*> >          enemy_minions;
    std::vector<Minion*>                        friendly_minions;
    sf::View                                    view;
    
    void                                        input();
    void                                        update();
public:
    void										intro();
	void                                        menu();
    void                                        game();
   
    void                                        spawnFriendlySoldierminion(int i);
};
#endif
