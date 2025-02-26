#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class BrowserHistory {
 public:
  BrowserHistory(string homepage) : current_index_(0){
    history_.push_back(homepage);
  }

  void visit(string url) {
    history_.resize(current_index_ + 1);
    history_.push_back(url);
    ++current_index_;
  }

  string back(int steps) {
    current_index_ = std::max(0, current_index_ - steps);
    return history_[current_index_];
  }

  string forward(int steps) {
    current_index_ = std::min(static_cast<int>(history_.size()) - 1, current_index_ + steps);
    return history_[current_index_];
  }

  private:
    std::vector<std::string> history_;
    int current_index_;
};

/**
   * Your BrowserHistory object will be instantiated and called as such:
   * BrowserHistory* obj = new BrowserHistory(homepage);
   * obj->visit(url);
   * string param_2 = obj->back(steps);
   * string param_3 = obj->forward(steps);
   */

int main(int argc, char const* argv[]) {
  /* code */
  auto bh = new BrowserHistory("leetcode.com");
  bh->visit("google.com");
  bh->visit("facebook.com");
  bh->visit("youtube.com");
  cout << bh->back(1) << endl;
  cout << bh->back(1) << endl;
  cout << bh->forward(1) << endl;
  bh->visit("linkedin.com");
  cout << bh->forward(2) << endl;
  cout << bh->back(2) << endl;
  cout << bh->back(7) << endl;
  return 0;
}
