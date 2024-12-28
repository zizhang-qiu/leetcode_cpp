#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class ExamRoom {
 public:
  ExamRoom(int n) : n_(n), num_seated_(0), seats_(n, 0) {}

  int seat() {
    if (num_seated_ == 0) {
      seats_[0] = 1;
      ++num_seated_;
      return 0;
    }

    std::vector<int> dists(n_, 0);
    for (int i = 0; i < n_; ++i) {
      if (seats_[i] == 1) {
        continue;
      }
      int dist = 0;
      for (int j = 0; j < n_; ++j) {
        if (seats_[j] == 1) {
          dist += std::abs(j - i);
        }
      }
      dists[i] = dist;
    }
    int seat = 0;
    int max_dist = 0;
    for (int i = 0; i <n_; ++i) {
      if (dists[i] > max_dist) {
        seat = i;
        max_dist = dists[i];
      }
    }
    seats_[seat] = 1;
    ++num_seated_;
    return seat;
  }

  void leave(int p) {
    seats_[p] = 0;
    --num_seated_;
  }

 private:
  int n_;
  int num_seated_;
  std::vector<int> seats_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main(int argc, char const* argv[]) {
  ExamRoom* obj = new ExamRoom(10);
  int s1 = obj->seat();
  printf("%d", s1);
  int s2 = obj->seat();
  printf("%d", s2);
  int s3 = obj->seat();
  printf("%d", s3);
  int s4 = obj->seat();
  printf("%d", s4);
  obj->leave(4);
  int s5 = obj->seat();
  printf("%d", s5);
  return 0;
}
