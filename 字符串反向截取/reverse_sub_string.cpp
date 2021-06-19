#include <iostream>
#include <vector>
using namespace std;

/**
 * 从后向前分段(1,2,3,4...)截取字符串成新的字符串
 * 例如电话号码 "17610357889",得到
 * 98835776101
 */

class Solution {
   public:
    string reverse_sub_string(string str) {
        int count = 1;
        string ret;
        while (!str.empty()) {
            string sub;
            if (str.length() <= count) {
                ret += str;
                break;
            } else {
                string sub = str.substr(str.length() - count);
                str.erase(str.length() - count);
                ret += sub;
            }

            count++;
        }
        return ret;
    }
};

int main() {
    cout << Solution().reverse_sub_string("17610357889") << endl;
    return 0;
}
