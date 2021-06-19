#include <iostream>
#include <vector>
using namespace std;

/**
 * 判断一个字符串是否是IP地址
 * ip: 192.168.1.1   1.1.1.1
 * string = "1111111"
 */

class Solution {
   public:
    bool isIP(string s) {
        if (s.size() < 7 || s.size() > 15) {
            return false;
        }
        vector<string> v(4);
        int index = 0;
        for (auto c : s) {
            if (c == '.') {
                index++;
            } else {
                v[index] += c;
            }
        }
        if (v.size() == 4) {
            for (auto s : v) {
                if (s >= "0" && s <= "255") {
                    // 跳过
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
        return true;
    }
};

int main() {
    string s = "1.1.1.1";
    cout << Solution().isIP(s) << endl;
}