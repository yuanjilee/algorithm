#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 *
 */

class Solution {
   public:
    int fintInt(string s) {
        if (s.empty()) {
            return 0;
        }
        map<char, int> m = {
            {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
            {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
        };
        string res;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                res += c;
            } else {
                break;
            }
        }
        int ret = 0;
        for (int i = 0; i < res.size(); i++) {
            int val = m[res[i]];
            ret = ret * 10 + val;
        }
        return ret;
    }
};

int main() {
    cout << Solution().fintInt("123wsd") << endl;
    return 0;
}