#include<iostream>
#include"../include/World.hpp"

using namespace sf;

void World::network()
{
	UdpSocket 		socket;
	socket.bind(Socket::AnyPort);
	unsigned short	packet_type;

	while(this->networking)
	{
		this->friendly_data_mutex.lock();
		this->createPacket(this->sending_packet);
		this->friendly_data_mutex.unlock();
		socket.send(this->sending_packet, this->server_address, this->server_port);
		socket.receive(this->receiving_packet, this->server_address, this->server_port);
		this->enemy_data_mutex.lock();
		this->parsePacket();
		this->enemy_data_mutex.unlock();	
	}
}

void World::createPacket(Packet& packet)
{
	for(int i=0; i<this->add_squad.size(); i++) {
		Vector2f	squad_position = this->add_squad[i];
		packet<<ADD_SQUAD<<squad_position.x<<squad_position.y;
	}
	this->add_squad.clear();
	for(int i=0; i<this->add_minion_to_squadID.size(); i++) {
		packet<<ADD_MINION<<this->add_minion_to_squadID[i];
	}
	this->add_minion_to_squadID.clear();
	
	for(int i=0; i<this->friendly_squads.size(); i++) {
		Vector2f	squad_position = this->friendly_squads[i].getPosition();
		packet<<UPDATE_SQUAD<<i<<squad_position.x<<squad_position.y;
		for(int j=0; j<this->friendly_squads[i].getNumberOfMinions(); j++) {
			Vector2f	minion_position = this->friendly_squads[i].getMinionPosition(j);
			packet<<UPDATE_MINION<<i<<j<<minion_position.x<<minion_position.y;
		}
	}
}

void World::parsePacket()
{
	while(this->receiving_packet.endOfPacket()) {
		this->receiving_packet>>this->packet_type;
		if(packet_type == UPDATE_SQUAD) {
			unsigned short 	userID;
			unsigned short 	squadID;
			Vector2f 		squad_position;
			receiving_packet>>userID>>squadID>>squad_position.x>>squad_position.y;
			this->enemy_squads[userID][squadID].setPosition(squad_position);
		} else if(packet_type == ADD_SQUAD) {
			unsigned short 	userID;
			Vector2f 		squad_position;
			receiving_packet>>userID>>squad_position.x>>squad_position.y;
			this->enemy_squads[userID].push_back(EnemySquad(squad_position));
			} else if(packet_type == UPDATE_MINION) {
			unsigned short 	userID;
			unsigned short 	squadID;
			unsigned short 	minionID;
			Vector2f 		minion_position;
			receiving_packet>>userID>>squadID>>minionID>>minion_position.x>>minion_position.y;
			this->enemy_squads[userID][squadID].squad[minionID].setPosition(minion_position);
		} else if(packet_type == ADD_MINION) {
			unsigned short 	userID;
			unsigned short 	squadID;
			Vector2f		minion_position;
			receiving_packet>>userID>>squadID>>minion_position.x>>minion_position.y;
			EnemyMinion minion(minion_position);
			this->enemy_squads[userID][squadID].addMinion(minion);
		} else if(packet_type == REMOVE_MINION) {
			unsigned short 	userID;
			unsigned short 	squadID;
			unsigned short 	minionID;
			receiving_packet>>userID>>squadID>>minionID;
			this->enemy_squads[userID][squadID].removeMinion(minionID);
		} else if(packet_type == ADD_PLAYER) {
			Vector2f 		base_position;
			receiving_packet>>base_position.x>>base_position.y;
			EnemyBase base(base_position);
			this->enemy_bases.push_back(base);
		} else if(packet_type == REMOVE_PLAYER) {
			unsigned short	userID;
			receiving_packet>>userID;
			this->enemy_bases.erase(this->enemy_bases.begin()+userID);
			this->enemy_squads.erase(this->enemy_squads.begin()+userID);
		} else if(packet_type == ATTACK_MINION) {
			unsigned short	userID;
			unsigned short	enemy_squadID;
			unsigned short	enemy_minionID;
			unsigned short	squadID;
			unsigned short	minionID;
			unsigned int 	damage;
			receiving_packet>>userID>>enemy_squadID>>enemy_minionID>>squadID>>minionID>>damage;
			/*this->friendly_minions[minionID].attacked(damage);*/
		} else if(packet_type == ATTACK_BASE) {
			unsigned short 	userID;
			unsigned short 	squadID;
			unsigned short 	minionID;
			unsigned int 	damage;
			receiving_packet>>userID>>squadID>>minionID>>damage;
		}	
	}
}


