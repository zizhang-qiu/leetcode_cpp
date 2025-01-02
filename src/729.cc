#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class MyCalendar {
 public:
  MyCalendar() : booked_time_() {}

  bool book(int startTime, int endTime) {
    for(const auto& time: booked_time_){
      if(endTime > time.first && startTime < time.second){
        return false;
      }
    }
    booked_time_.push_back(std::make_pair(startTime, endTime));
    return true;
  }

 private:
  std::vector<std::pair<int, int>> booked_time_;
};

int main(int argc, char const* argv[]) {
  /* code */
  MyCalendar* obj = new MyCalendar();
  std::cout << obj->book(10, 20) << "\n";
  std::cout << obj->book(15, 25) << "\n";
  std::cout << obj->book(20, 30) << "\n";
  return 0;
}
