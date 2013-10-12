#include<vector>
#include"UI.hpp"
#include"soldier_minion.hpp"
#include"minion_base.hpp"
#include"MinionSquad.hpp"

#ifndef	PACKET_TYPE 
#define PACKET_TYPE
enum PacketType {UPDATE_SQUAD = 0, ADD_SQUAD, UPDATE_MINION, ADD_MINION, REMOVE_MINION, UPDATE_BASE, ADD_PLAYER, REMOVE_PLAYER, ATTACK_MINION, ATTACK_BASE};
#endif

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
    std::vector<MinionSquad>                   	friendly_squads;
    sf::View                                    view;
    

	int											getNumberOfMinions();
    void                                        input();
    void                                        update();
public:
    void										intro();
	void                                        menu();
    void                                        game();
   
    void                                        spawnFriendlySoldierminion(int i);
};
#endif
