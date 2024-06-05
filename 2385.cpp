#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include <functional>
#include<queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<int , vector<int>> graph;
    unordered_set<int> used;
    queue<TreeNode*> Q;
    int times = 0;
public:
    int amountOfTime(TreeNode* root , int start) {
        Q.push(root);
        int len = Q.size();
        //广度优先搜索建立邻接表
        while (len) {
            if (Q.empty())
                break;
            TreeNode* temp = Q.front();
            Q.pop();
            if (temp->left) {
                graph[temp->val].emplace_back(temp->left->val);
                graph[temp->left->val].emplace_back(temp->val);
                Q.push(temp->left);
                len++;
            }
            if (temp->right) {
                graph[temp->val].emplace_back(temp->right->val);
                graph[temp->right->val].emplace_back(temp->val);
                Q.push(temp->right);
                len++;
            }
        }
        //测试
        // for (auto rows = graph.begin(); rows != graph.end(); rows++) {
        //     cout << rows->first << ": ";
        //     for (auto num : rows->second)
        //         cout << num << ",";
        //     cout << endl;
        // }
        // cout << endl;


        queue<int> QQ;
        QQ.push(start);
        used.emplace(start);
        len--;
        int cur_len = 1;
        int next_len = 0;
        while (len) {
            int head = QQ.front();
            QQ.pop();
            cur_len--;
            for (int tail : graph[head]) {
                if (used.count(tail) == 0) {
                    used.emplace(tail);
                    QQ.push(tail);
                    len--;
                    next_len++;
                }
            }
            if (cur_len == 0) {
                times++;
                cur_len = next_len;
                next_len = 0;
            }
            if (len == 0 && next_len != 0)
                times++;
        }
        return times;
    }
};
int main() {
    Solution S;

    // TreeNode* root=new TreeNode(1);
    // TreeNode* five = new TreeNode(5);
    // root->left = five;
    // root->right = new TreeNode(3);
    // TreeNode* T = root->left;
    // T->right = new TreeNode(4);
    // T = T->right;
    // T->left = new TreeNode(9);
    // T->right = new TreeNode(2);
    // T = root->right;
    // T->left = new TreeNode(10);
    // T->right = new TreeNode(6);
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    TreeNode* temp = root->left;
    temp->left = new TreeNode(4);
    temp->right = new TreeNode(1);
    temp = temp->right;
    temp->right = new TreeNode(5);

    cout<<S.amountOfTime(root , 1);
}