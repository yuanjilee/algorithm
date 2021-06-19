#include <iostream>
using namespace std;

class Solution {
   public:
    void quick_sort(int arr[], int len) { q_sort(arr, 0, len - 1); }
    void q_sort(int arr[], int low, int high) {  // 递归
        if (low >= high) {                       // 结束条件
            return;
        }
        int base = partition(arr, low, high);
        q_sort(arr, low, base - 1);
        q_sort(arr, base + 1, high);
    }
    int partition(int arr[], int low, int high) {  // 分治
        int base = arr[low];
        while (low < high) {
            while (low < high && arr[high] >= base) {
                --high;
            }
            arr[low] = arr[high];
            while (low < high && arr[low] <= base) {
                ++low;
            }
            arr[high] = arr[low];
        }
        arr[low] = base;
        return low;
    }
};

int main() {
    int arr[] = {5, 3, 1, 2, 4};
    int len = (int)sizeof(arr) / sizeof(*arr);
    Solution().quick_sort(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
}