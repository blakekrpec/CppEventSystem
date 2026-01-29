#ifndef EVENTSYSTEM_HPP
#define EVENTSYSTEM_HPP

// STL
#include <functional>
#include <mutex>

template <typename event_type> class EventSystem
{
	// Alias for a subscriber function that takes a const reference to the event
	// type. Using std::function allows storing lambdas, function pointers, or
	// bind expressions.
	using listener = std::function<void(const event_type &)>;

	// Both addSubscriber and onInvoke lock the mutex to prevent race conditions
	// when listeners are added or invoked concurrently from multiple threads.
	std::mutex mtx;

  public:
	void addSubscriber(listener &&l)
	{
		std::lock_guard<std::mutex> lock(mtx);
		// Move the listener into the vector to avoid copying and support
		// move-only types.
		listeners.push_back(std::move(l));
	}

	void onInvoke(const event_type &event)
	{
		std::lock_guard<std::mutex> lock(mtx);

		for (auto &listener : listeners)
		{
			listener(event);
		}
	}

  private:
	std::vector<listener> listeners;
};

#endif // EVENTSYSTEM_HPP
