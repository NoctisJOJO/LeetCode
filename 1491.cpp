#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int ans = 0;
    int maxn = 0;
    int minn = INT_MAX;
public:
    double average(vector<int>& salary) {
        for (int num : salary) {
            ans += num;
            maxn = max(maxn , num);
            minn = min(minn , num);
        }
        return (double)(ans - maxn - minn) / (salary.size() - 2);
    }
};