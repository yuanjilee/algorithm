#include <iostream>
#include <list>
#include <vector>
using namespace std;

/**
 * 递归实现0-100求和
 */
class Solution {
   public:
    int sum(int val) {
        if (val <= 0) {
            return 0;
        }
        return val + sum(val - 1);
    }
};

// 正常实现
class Solution2 {
   public:
    int sum(int val) {
        int s = 0;
        while (val >= 0) {
            s += val;
            val--;
        }
        return s;
    }
};

int main() { cout << Solution().sum(100); }