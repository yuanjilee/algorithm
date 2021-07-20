#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 描述
 * 设计LRU缓存结构，该结构在构造时确定大小，假设大小为K，并有如下两个功能
 * set(key, value)：将记录(key, value)插入该结构
 * get(key)：返回key对应的value值
 * [要求]
 * set和get方法的时间复杂度为O(1)
 * 某个key的set或get操作一旦发生，认为这个key的记录成了最常使用的。
 * 当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
 * 若opt=1，接下来两个整数x, y，表示set(x, y)
 * 若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1
 * 对于每个操作2，输出一个答案
 *
 * 示例1
 * 输入：
 * [[1,1,1],[1,2,2],[1,3,2],[2,1],[1,4,4],[2,2]],3
 *
 * 返回值：
 * [1,-1]
 *
 * 说明：
 * 第一次操作后：最常使用的记录为("1", 1)
 * 第二次操作后：最常使用的记录为("2", 2)，("1", 1)变为最不常用的
 * 第三次操作后：最常使用的记录为("3", 2)，("1", 1)还是最不常用的
 * 第四次操作后：最常用的记录为("1", 1)，("2", 2)变为最不常用的
 * 第五次操作后：大小超过了3，所以移除此时最不常使用的记录("2",
 * 2)，加入记录("4", 4)，并且为最常使用的记录，然后("3", 2)变为最不常使用的记录
 *
 * 思路：
 * 既然要达到O(1),那么可以用 hash 表用来get，而用链表实现 set;
 * 链表插入时间复杂度O(1),查找O(n),那么就需要实现查找O(1).那么要实现
 * 每次移除最后一个，添加在第一个。而双向链表能通过pre记住前一个，故选择
 * 双向链表。
 */

class Solution {
   public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    struct Node {
        int key, val;
        Node *pre, *next;
        Node() : key(0), val(0), pre(nullptr), next(nullptr) {}
        Node(int _key, int _val)
            : key(_key), val(_val), pre(nullptr), next(nullptr) {}
    };

    Node *head = new Node();
    Node *tail = new Node();
    unordered_map<int, Node *> map;
    int size = 0;
    int cap = 0;

    vector<int> LRU(vector<vector<int>> &operators, int k) {
        vector<int> res;
        cap = k;
        head->next = tail;
        tail->pre = head;
        for (auto opt : operators) {
            if (opt[0] == 1) {  // set
                set(opt[1], opt[2]);
            } else {  // get
                int val = get(opt[1]);
                res.push_back(val);
            }
        }
        return res;
    };

    int get(int key) {
        if (!map.count(key)) {
            return -1;
        };
        // 存在，则通过哈希表定位，并移到头部表示最新
        Node *node = map[key];
        moveToHead(node);
        return node->val;
    };

    void set(int key, int value) {
        if (!map.count(key)) {  // 不存在
            Node *node = new Node(key, value);

            map[key] = node;  // 添加进哈希表
            addToHead(node);  // 添加到链表头
            size++;

            if (size > cap) {                      // 超出容量
                Node *removed = removeTailNode();  // 移除尾结点
                map.erase(removed->key);           // 移除字典
                delete removed;
                size--;
            }
        } else {  // 存在, 找到赋新值，并移到头节点
            Node *node = map[key];
            node->val = value;
            moveToHead(node);
        }
    };

    void addToHead(Node *node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    };

    void moveToHead(Node *node) {
        removeNode(node);
        addToHead(node);
    };

    void removeNode(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    Node *removeTailNode() {
        Node *node = tail->pre;
        removeNode(node);
        return node;
    };
};

int main() {
    vector<vector<int>> v = {{1, 1, 1}, {1, 2, 2}, {1, 3, 2},
                             {2, 1},    {1, 4, 4}, {2, 2}};
    vector<int> ret = Solution().LRU(v, 3);
    for (auto v : ret) {
        cout << v << endl;
    }
    return 0;

    vector<vector<int>> res;
    for (int i = 0; i < nodes.size(); i++) {
        if (i % 2 == 0) {  // 偶数行
            res.push_back(nodes[i]);
        } else {  // 奇数行
            vector<int> to_reversed = nodes[i];
            reverse(to_reversed.begin(), to_reversed.end());
            res.push_back(to_reversed);
        }
    }
}