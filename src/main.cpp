#include <cmath>
#include <iostream>
#include <thread>

#include <event_system.hpp>
#include <player.hpp>
#include <random01.hpp>

int main()
{
	EventSystem<int> enemy_hit;
	EventSystem<float> health_change;

	Player player(5, 50.0f);

	enemy_hit.addSubscriber([&player](int hits) { player.onEnemyHit(hits); });
	health_change.addSubscriber([&player](float damage)
								{ player.onDamageTaken(damage); });

	while (true)
	{
		int hit_chance = random01();

		if (hit_chance > 0)
		{
			enemy_hit.onInvoke(1);
			std::cout << "Player hit enemy." << std::endl;
		}
		else
		{
			health_change.onInvoke(10.0f);
			std::cout << "Player was hit by enemy." << std::endl;
		}

		std::cout << "Player has hit " << player.enemies_hit << " enemies."
				  << std::endl;
		std::cout << "Player has " << player.health << " health." << std::endl;
		std::cout << "      +++      " << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
	return 0;
}
