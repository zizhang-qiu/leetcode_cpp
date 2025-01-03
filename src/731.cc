#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo(): booked_(), overlapped_() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(const auto& [l, r]: overlapped_){
          if (l < endTime && startTime < r){
            return false;
          }
        }

        for(const auto& [l, r]: booked_){
          if (l < endTime && startTime < r){
            overlapped_.emplace_back(std::max(l, startTime), std::min(r, endTime));
          }
        }

        booked_.emplace_back(startTime, endTime);
        return true;
    }

    private:
    std::vector<std::pair<int, int>> booked_;
    std::vector<std::pair<int ,int>> overlapped_;
};

int main(int argc, char const* argv[]) {
  /* code */
  auto calendar = new MyCalendarTwo();
  std::cout << calendar->book(10, 20) << "\n";
  std::cout << calendar->book(50, 60) << "\n";
  std::cout << calendar->book(10, 40) << "\n";
  std::cout << calendar->book(5, 15) << "\n";
  std::cout << calendar->book(5, 10) << "\n";
  std::cout << calendar->book(25, 55) << "\n";
  return 0;
}
