#include<SFML/Network.hpp>
#include<vector>
#include"UI.hpp"
#include"soldier_minion.hpp"
#include"minion_base.hpp"
#include"MinionSquad.hpp"
#include"EnemyBase.hpp"
#include"EnemySquad.hpp"

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
	
	std::vector<EnemyBase>						enemy_bases;
	std::vector<std::vector<EnemySquad>	>		enemy_squads;
	std::vector<int>							add_minion_to_squadID;
    std::vector<sf::Vector2f>					add_squad;
	std::vector<MinionBase>						friendly_bases;
    std::vector<MinionSquad>                   	friendly_squads;
    sf::View                                    view;
    
	bool										networking;
	sf::Mutex									enemy_data_mutex;
	sf::Mutex									friendly_data_mutex;
	sf::Thread									network_thread;
	sf::Packet									sending_packet;
	sf::Packet									receiving_packet;
	sf::IpAddress								server_address;
	unsigned short 								server_port;
	unsigned short								packet_type;
	void										network();
	void										createPacket(sf::Packet& packet);
	void										parsePacket();

	int											getNumberOfMinions();
    void                                        input();
    void                                        update();
public:
    											World();
	void										intro();
	void                                        menu();
    void                                        game();
   
    void                                        spawnFriendlySoldierminion(int i);
};
#endif
