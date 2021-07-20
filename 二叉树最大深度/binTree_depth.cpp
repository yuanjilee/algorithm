#include <iostream>
#include <queue>

using namespace std;

/**
 * 链表最大深度
 */
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    int maxDepth(TreeNode* root) {
        //空树返回 0
        if (root == nullptr) return 0;
        //遍历左子树
        int left_depth = maxDepth(root->left);
        //遍历右子树
        int right_depth = maxDepth(root->right);
        return left_depth > right_depth ? left_depth : right_depth + 1;
    }
};

// Test

TreeNode* initBTree(int elements[], int size) {
    if (size < 1) {
        return NULL;
    }
    //动态申请size大小的指针数组
    TreeNode** nodes = new TreeNode*[size];
    //将int数据转换为TreeNode节点
    for (int i = 0; i < size; i++) {
        if (elements[i] == 0) {
            nodes[i] = NULL;
        } else {
            nodes[i] = new TreeNode(elements[i]);
        }
    }
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(nodes[0]);

    TreeNode* node;
    int index = 1;
    while (index < size) {
        node = nodeQueue.front();
        nodeQueue.pop();
        nodeQueue.push(nodes[index++]);
        node->left = nodeQueue.back();
        nodeQueue.push(nodes[index++]);
        node->right = nodeQueue.back();
    }
    return nodes[0];
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = initBTree(nums, 7);
    cout << Solution().maxDepth(root) << endl;

    return 0;
}