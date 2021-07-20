#include <iostream>
#include <list>
#include <vector>
using namespace std;

/**
 * 0-1 背包问题，给定数组，任意元素和为 target
 */

class Solution {
   public:
    bool isEqual(vector<int> v, int target) {
        if (v.empty()) {
            return false;
        }
        int ret = 0;
        for (auto a : v) {
            ret += a;
        }
        if (ret == target) {
            return true;
        }
        return false;
    }
};

class Solution2 {
   public:
    bool isEqual(vector<int> v, int target) {
        if (v.empty()) {
            return false;
        }

        int size = v.size();
        int ret = 0;
        for (int i = 0; i < size; i++) {
            ret += i;
            int sum = 0;
            for (int j = i; j < size; j++) {
                sum += v[i];
                if (sum == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution3 {
   public:
    int res[100], k = 0;

    void sumOfKNumber(vector<int> a, int n, int sum) {
        if (n <= 0 || sum <= 0) return;

        if (k > 0) {
            if (sum == a[n - 1]) {
                for (int i = k - 1; i >= 0; --i) cout << res[i] << "+";

                cout << a[n - 1]
                     << endl;  //特别注意，输出时，该元素还未加入数组
            }
        }

        //考虑是否取第n个数
        res[k++] = a[n - 1];
        sumOfKNumber(a, n - 1, sum - a[n - 1]);
        k--;

        sumOfKNumber(a, n - 1, sum);
    }
};

class Solution5 {
   private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

   public:
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }

        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int num : candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};

// function findGroup(arr, n, sum) {
//     if (n > arr.length) return false
//     if (sum == 0 && n == 0) {
//         return true;
//     } else if (n <= 0) {
//         return false;
//     }
//     if (n > 0) {
//         // if (arr.length === 0) return false
//         let temp = arr.slice(1, arr.length)
//         return findGroup(temp, n - 1, sum - arr[0]) || findGroup(temp, n,
//         sum)
//     }
// }

int main() {
    vector<int> v = {1, 3, 5, 2};
    // cout << Solution3().sumOfKNumber(v, 3, 9) << endl;
    Solution3().sumOfKNumber(v, 4, 8);
    return 0;
}