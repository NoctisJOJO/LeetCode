#include<iostream>
#include<vector>
#include <queue>
using namespace std;

class Solution {
private:
    long long ans = 0;
public:
    long long totalCost(vector<int>& costs , int k , int candidates) {
        int n = costs.size();
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> q;
        int left = candidates - 1 , right = n - candidates;
        
        for (int i = 0; i <= left; i++) {
            q.push({ costs[i],i });
        }
        for (int i = right; i < n; i++) {
            if (i > left)
                q.push({ costs[i],i });
        }
        while (left +1< right && k) {
            auto [cost , id] = q.top();
            q.pop();
            ans += cost;
            k--;
            if (id <= left) {
                left++;
                q.push({ costs[left],left });
            }
            else {
                right--;
                q.push({ costs[right],right });
            }
        }
        while (k) {
            auto [cost , id] = q.top();
            q.pop();
            ans += cost;
            k--;
            // if (id <= left) {
            //     left++;
            //     q.push({ costs[left],left });
            // }
            // else {
            //     right--;
            //     q.push({ costs[right],right });
            // }
        }
        return ans;
    }
};

int main(void) {
    vector<int> costs = { 28,35,21,13,21,72,35,52,74,92,25,65,77,1,73,32,43,68,8,100,84,80,14,88,42,53,98,69,64,40,60,23,99,83,5,21,76,34 };
    //                    2,2,7,8,10,11,12,17,20
    int k = 32 , candidates = 12;
    Solution S;
    cout << S.totalCost(costs , k , candidates);
}