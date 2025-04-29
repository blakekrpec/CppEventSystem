#include <cmath>
#include <iostream>
#include <thread>

#include <event_system.hpp>
#include <player.hpp>
#include <random01.hpp>

// Simple script demonstrating an event-based system in C++. 
// The player object subscribes to `enemy_hit` and `health_change` events. 
// When these events are invoked, the associated player methods are executed. 
// This decouples objects, enabling indirect communication—useful in large systems 
// (e.g., games) to reduce tight coupling between classes.

int main()
{
	EventSystem<int> enemy_hit;
	EventSystem<float> health_change;

	Player player(5, 50.0f);

    // `player.onEnemyHit` is a non-static method, but `addSubscriber` expects 
    // a `std::function`, which requires a static-like callable. 
    // We wrap the member function in a lambda to bind it to the player instance.
    // Alternatively, `std::bind` could be used instead of a lambda.
	enemy_hit.addSubscriber([&player](int hits) { player.onEnemyHit(hits); });
    // Same explanation as above—lambda wraps a non-static method to allow 
    // subscription to the event system.
	health_change.addSubscriber([&player](float damage)
								{ player.onDamageTaken(damage); });

	while (true)
	{
		int hit_chance = random01();

        // If the player succesfully hits enemy.
		if (hit_chance > 0)
		{
			enemy_hit.onInvoke(1);
			std::cout << "Player hit enemy." << std::endl;
		}
        // If the player misses and takes damage.
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
