#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Event {
  std::string badge_id;
  bool is_entry;  // if false, event is exit
  int timestamp;
};

// Fill in this function:
// Print the max occupancy and when it occurred.
void FindMaxOccupancy(const std::vector<Event>& events) {
  ///...
  int max_occupancy = 0;
  int max_occupancy_timestamp = 0;
  
  // sort the timestamp
  // record the id that went into in a vector<string>
  // std::vector<std::string> badges;
  std::vector<Event> entry_log = events;
  for (auto x: events)
  {
    std::sort(entry_log.begin(), entry_log.end(), [](const Event& lhs, const Event& rhs) -> bool {
      return rhs.timestamp > lhs.timestamp;
    });
  }

  std::unordered_set<std::string> badges;
  std::vector<std::string> badges;

  int curr_occupancy = 0;
  for (auto event: entry_log)
  {
    if (event.is_entry)
    {
      if (!badges.contains(event.badge_id))
      {
        // this user isnt tap in yet
        std::cout << "badge " << event.badge_id << " enterred "<< std::endl;
        badges.insert(event.badge_id);
        curr_occupancy++;
        if (curr_occupancy >= max_occupancy)
        {
          max_occupancy = curr_occupancy;
          max_occupancy_timestamp = event.timestamp;
        }
      }
      else
      {
        std::cout << "multiple tap in for badge " << event.badge_id << std::endl;
        // user tap in twice
      }
    }
    else 
    {
      
      if ( !badges.contains(event.badge_id))
      {
        // missing tap in
        std::cout << "multiple tap out for badge " << event.badge_id << std::endl;
      }
      else 
      {
        // valid tapout
        std::cout << "badge " << event.badge_id << " exited"<< std::endl;
        badges.erase(event.badge_id);
        curr_occupancy--;
      }
    }
  }

  std::cout << "max: " << max_occupancy << std::endl;               
  std::cout << "max at: " << max_occupancy_timestamp << std::endl; 
}

int main(int argc, char** argv) {
  Event m1 =
      Event{.badge_id = "jsfe31a", .is_entry = true, .timestamp = 341356};
  Event m2 =
      Event{.badge_id = "jsfe31a", .is_entry = false, .timestamp = 357281};
  Event m3 =
      Event{.badge_id = "khjsdf3", .is_entry = true, .timestamp = 348634};
  Event m4 =
      Event{.badge_id = "khjsdf3", .is_entry = false, .timestamp = 379346};

  std::vector<Event> events = {
      m2,
      m1,
      m4,
      m3,
      Event{.badge_id = "a", .is_entry = true, .timestamp = 348635},
      Event{.badge_id = "a", .is_entry = true, .timestamp = 348655},
      Event{.badge_id = "b", .is_entry = false, .timestamp = 341357},
  };
  FindMaxOccupancy(events);
  return 0;
}
