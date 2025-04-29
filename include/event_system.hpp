#include <functional>
#include <vector>

template <typename... args> class EventSystem
{
	using listener = std::function<void(args...)>;

  public:
	void AddSubscriber(listener l)
	{
		listeners.push_back(l);
	}
	void OnInvoke(args... a)
	{
		for (auto &listener : listeners)
		{
			listener(a...);
		}
	}

  private:
	std::vector<listener> listeners;
};
