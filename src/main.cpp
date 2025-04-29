#include <event_system.hpp>
#include <iostream>
#include <thread>

EventSystem<int> event_system;

void listener(int i)
{
	std::cout << "Tick #: " << i << std::endl;
}
void sub_listener()
{
	event_system.AddSubscriber(listener);
}

int main()
{
	sub_listener();

	int tick = 0;
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		event_system.OnInvoke(tick++);
	}

	return 0;
}
