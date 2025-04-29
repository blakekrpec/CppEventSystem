#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <event_system.hpp>

class Player
{
  public:
	int enemies_hit;
	float health;

	Player(int enemies_hit = 0, float health = 100.0f)
		: enemies_hit(enemies_hit), health(health)
	{
	}

	void onEnemyHit(int hits)
	{
		enemies_hit += hits;
	}

	void onDamageTaken(float damage)
	{
		health -= damage;
	}
};
#endif // PLAYER_HPP
