#include <iostream>
#include <map>
#include <stack>

using namespace std;

/**
 * 题目：括号匹配，判断所给出的字符串括号是否成对出现
 * 输入："([{}])"  输出: true  输入 "([)]"  输出：false
 * 考点：栈
 * 分析：未匹配入栈，匹配出栈
 */
class Solution {
   public:
    bool isValid(string s) {
        stack<char> stack;
        map<char, char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        for (auto c : s) {
            if (map.find(c) != map.end()) {
                stack.push(c);
            } else {
                if (!stack.empty() && map[stack.top()] == c) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};

int main() {
    string s = "([{}])";
    cout << Solution().isValid(s) << endl;

    return 0;
}