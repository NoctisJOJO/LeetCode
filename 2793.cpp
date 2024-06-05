#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours , int target) {
        int ans = 0;
        for (int num : hours) {
            if (num >= target)
                ans++;
        }
        return ans;

    }
};