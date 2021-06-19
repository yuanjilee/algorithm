#include <iostream>
using namespace std;

/**
 * 冒泡排序
 * 时间复杂度：O(n^2)
 */
class Solution {
   public:
    void bubble_sort(int arr[], int len) {
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

/**
 * 改进：加个 flag 标志位判断是否已经是有序，则直接返回
 */
class Solution2 {
   public:
    void bubble_sort(int arr[], int len) {
        for (int i = 0; i < len - 1; i++) {
            bool flag = true;  // 标志符用来优化有序数组
            for (int j = 0; j < len - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    flag = false;
                    swap(arr[j], arr[j + 1]);
                }
            }
            if (flag) {  // 未冒泡，表示所有已排好
                return;
            }
        }
    }
};

/**
 * 改进：如果有100个数的数组，仅前面10个无序，后面90个都已排好序且都大于前面10个数字，
 * 那么在第一趟遍历后，最后发生交换的位置必定小于10，且这个位置之后的数据必定已经有序了。
 */
class Solution3 {
   public:
    void bubble_sort(int arr[], int len) {
        int index = len - 1;  // 标记最大交换位的下标，表示需要交换的前几个数
        int k;
        for (int i = 0; i < index; i++) {
            k = index;
            for (int j = 0; j < k; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    index = j + 1;
                }
            }
            cout << "🍉" << index << endl;
        }

        // int j, k;
        // int flag;
        // flag = len;
        // while (flag > 0) {
        //     k = flag;
        //     flag = 0;
        //     for (j = 1; j < k; j++)
        //         if (arr[j - 1] > arr[j]) {
        //             swap(arr[j - 1], arr[j]);
        //             flag = j;
        //         }
        // }
    }
};

int main() {
    int arr[] = {5, 3, 1, 2, 4};
    int len = (int)sizeof(arr) / sizeof(*arr);
    Solution3().bubble_sort(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
}