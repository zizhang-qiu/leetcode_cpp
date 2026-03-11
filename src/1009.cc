#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int num_bits = 0;
        int n_copy = n;
        while (n > 0) {
            n >>= 1;
            num_bits++;
        }
        int mask = (1 << num_bits) - 1;
        return mask - n_copy;
    }
};

int main() {
    Solution s;
    cout << s.bitwiseComplement(5) << endl;
    cout << s.bitwiseComplement(7) << endl;
    cout << s.bitwiseComplement(10) << endl;
    return 0;
}