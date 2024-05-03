#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double average(vector<int>& salary) {
    int min_salary = INT_MAX;
    int max_salary = INT_MIN;
    int sum = 0;
    for (int i = 0; i < salary.size(); i++) {
      if (salary[i] < min_salary) {
        min_salary = salary[i];
      }
      if (salary[i] > max_salary) {
        max_salary = salary[i];
      }
      sum += salary[i];
    }
    return (double)(sum - min_salary - max_salary) / (salary.size() - 2);
  }
};

int main(int argc, char** argv) {
    vector<int> salary = {4000, 3000, 1000, 2000};
    Solution solution;
    double result = solution.average(salary);
    cout << result << endl;
    return 0;
}