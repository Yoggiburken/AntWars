#include"../include/World.hpp"

using namespace sf;

void World::network()
{
	UdpSocket 		socket;
	socket.bind(Socket::AnyPort);
	unsigned short	packet_type;

	while(this->networking)
	{
		socket.send(this->sending_packet, this->server_address, this->server_port);
		socket.receive(this->receiving_packet, this->server_address, this->server_port);
	
		while(this->receiving_packet.endOfPacket()) {
			this->receiving_packet>>packet_type;
			if(packet_type == UPDATE_SQUAD) {
				unsigned short 	userID;
				unsigned short 	squadID;
				Vector2f 		squad_position;
				receiving_packet>>userID>>squadID>>squad_position.x>>squad_position.y;
			} else if(packet_type == ADD_SQUAD) {
				unsigned short 	userID;
				Vector2f 		squad_position;
				receiving_packet>>userID>>squad_position.x>>squad_position.y;
			} else if(packet_type == UPDATE_MINION) {
				unsigned short 	userID;
				unsigned short 	squadID;
				unsigned short 	minionID;
				Vector2f 		minion_position;
				receiving_packet>>userID>>squadID>>minionID>>minion_position.x>>minion_position.y;
			} else if(packet_type == ADD_MINION) {
				unsigned short 	userID;
				unsigned short 	squadID;
				Vector2f		minion_position;
				receiving_packet>>userID>>squadID>>minion_position.x>>minion_position.y;
			} else if(packet_type == REMOVE_MINION) {
				unsigned short 	userID;
				unsigned short 	squadID;
				unsigned short 	minionID;
				receiving_packet>>userID>>squadID>>minionID;
			} else if(packet_type == ADD_PLAYER) {
				Vector2f 		base_position;
				receiving_packet>>base_position.x>>base_position.y;
			} else if(packet_type == REMOVE_PLAYER) {
				unsigned short	userID;
				receiving_packet>>userID;
			} else if(packet_type == ATTACK_MINION) {
				unsigned short	userID;
				unsigned short	enemy_squadID;
				unsigned short	enemy_minionID;
				unsigned short	squadID;
				unsigned short	minionID;
				unsigned int 	damage;
				receiving_packet>>userID>>enemy_squadID>>enemy_minionID>>squadID>>minionID>>damage;
			} else if(packet_type == ATTACK_BASE) {
				unsigned short 	userID;
				unsigned short 	squadID;
				unsigned short 	minionID;
				unsigned int 	damage;
				receiving_packet>>userID>>squadID>>minionID>>damage;
			}	
		}
	}
}
