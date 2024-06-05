#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<queue>
using namespace std;

class Solution {
private:
    double ans = __DBL_MAX__;
public:
    double mincostToHireWorkers(vector<int>& quality , vector<int>& wage , int k) {
        int n = quality.size();
        vector<int> L(n , 0);
        iota(L.begin() , L.end() , 0);
        sort(L.begin() , L.end() , [&](int& a , int& b) {
            return (double)wage[a] / quality[a] < (double)wage[b] / quality[b];
            });
        double totalq = 0.0;
        priority_queue<int , vector<int> , less<int>> q;
        for (int i = 0; i < k - 1; i++) {
            totalq += quality[L[i]];
            q.push(quality[L[i]]);
        }
        for (int i = k - 1; i < n; i++) {
            int rate = L[i];
            totalq += quality[rate];
            q.push(quality[rate]);
            ans = min(ans , totalq * (double)wage[rate] / quality[rate]);
            totalq -= q.top();
            q.pop();
        }
        return ans;
    }
};