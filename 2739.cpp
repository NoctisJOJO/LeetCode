#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int ans = 0;
public:
    int distanceTraveled(int mainTank , int additionalTank) {
        int main = 0;
        while (mainTank) {
            if (mainTank < 5) {
                ans += mainTank;
                break;
            }
            main = mainTank / 5;
            mainTank -= main * 5;
            ans += main * 5;
            if (additionalTank < main) {
                ans += additionalTank+mainTank;
                break;
            }
            additionalTank -= main;
            mainTank += main;
        }
        return ans * 10;
    }
};
//11 1