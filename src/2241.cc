#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class ATM {
 public:
  ATM() : counts_(5, 0) {}

  void deposit(vector<int> banknotesCount) {
    for (size_t i = 0; i < banknotesCount.size(); ++i) {
      counts_[i] += banknotesCount[i];
    }
  }

  vector<int> withdraw(int amount) {
    std::vector<int> ans(5, 0);
    int total_amount = 0;
    for (int i = 4; i >= 0; --i) {
      ans[i] = std::min((amount - total_amount) / faces_[i], counts_[i]);
      total_amount += ans[i] * faces_[i];
      counts_[i] -= ans[i];
    }
    if (total_amount == amount) {
      return ans;
    }
    for(int i=0; i<5; ++i){
      counts_[i] += ans[i];
    }
    return std::vector<int>{-1};
  }

 private:
  const std::vector<int> faces_ = {20, 50, 100, 200, 500};
  std::vector<int> counts_;
};

template<typename T>
void PrintVec(const std::vector<T>& vec){
  for(const auto& elem: vec){
    std::cout << elem << ", ";
  }
  std::cout << std::endl;
}

int main(int argc, char const* argv[]) {
  /* code */
  auto atm = new ATM();
  atm->deposit(std::vector<int>{0,0,1,2,1});
  auto res1 = atm->withdraw(600);
  PrintVec(res1);
  atm->deposit(std::vector<int>{0,1,0,1,1});
  auto res2 = atm->withdraw(600);
  PrintVec(res2);
  auto res3 = atm->withdraw(550);
  PrintVec(res3);
  return 0;
}
