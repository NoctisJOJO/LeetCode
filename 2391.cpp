#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
private:
    int ans = 0;
public:
    int garbageCollection(vector<string>& garbage , vector<int>& travel) {
        vector<int> flag(3);
        vector<int> sums(travel.size());
        for (int i = 0; i < travel.size();i++) {
            if (i == 0)
                sums[i] = travel[i];
            else
                sums[i] = travel[i] + sums[i - 1];
        }

        int temp = garbage.size() - 1;
        while (temp) {
            for (char c : garbage[temp]) {
                if (c == 'M' && flag[0] == 0) {
                    flag[0] = 1;
                    ans += sums[temp - 1];
                }
                else if (c == 'P' && flag[1] == 0) {
                    flag[1] = 1;
                    ans += sums[temp - 1];
                }
                else if (c == 'G' && flag[2] == 0) {
                    flag[2] = 1;
                    ans += sums[temp - 1];
                }
            }
            temp--;
        }
        for (string list : garbage)
            ans += list.size();

        return ans;
    }
};