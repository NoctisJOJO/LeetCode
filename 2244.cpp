#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
private:
    int ans = 0;
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int , int> map;
        for (int num : tasks) {
            // if (map.find(num) == map.end()) {
            //     map.insert({ num,1 });
            // }
            // else
                map[num]++;
        }
        for (const auto& it : map) {
            if (it.second == 1)
                return -1;
            else {
                if (it.second % 3 == 0)
                    ans += it.second / 3;
                else
                    ans += it.second / 3 + 1;
            }
        }
        return ans;
    }
};
int main(void) {
    Solution S;
    vector<int> task = { 2,2,3,3,2,4,4,4,4,4 };
    S.minimumRounds(task);
}