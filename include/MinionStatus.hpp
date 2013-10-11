#include<SFML/Graphics.hpp>

#ifndef MINION_MOVEMENT
#define MINION_MOVEMENT
struct MinionMovement {
    sf::Vector2f                direction;
    sf::Time                    next_move;
};
#endif

#ifndef MINION_STATUS
#define MINION_STATUS
enum MinionStatus {IDLING=0, ATTACKING=1, DEFENDING=2};
#endif
