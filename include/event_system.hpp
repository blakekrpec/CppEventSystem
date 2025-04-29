#ifndef EVENTSYSTEM_HPP
#define EVENTSYSTEM_HPP

#include <functional>
#include <mutex>

template<typename event_type>
class EventSystem 
{
    using listener = std::function<void(const event_type&)>;
    std::mutex mtx;

  public:
    void addSubscriber(listener&& l)
    {
        std::lock_guard<std::mutex> lock(mtx);
        listeners.push_back(std::move(l));

    }

    void onInvoke(const event_type& event)
    {
        std::lock_guard<std::mutex> lock(mtx);

        for (auto& listener : listeners)
        {
            listener(event);
        }
    }

  private:
    std::vector<listener> listeners;

};

#endif //EVENTSYSTEM_HPP
