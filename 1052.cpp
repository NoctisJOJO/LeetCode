#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int num = 0 , ang = 0 , angmax = 0;
        //时间复杂度太大
        // for (int i = 0; i < customers.size();i++)
        // {
        //     if(grumpy[i]==0){
        //         num += customers[i];
        //     }
        //     else{
        //         int temp = 0;
        //         for (int j = 0; j < minutes;j++){
        //             if(i+j<customers.size()&&grumpy[i+j]==1)
        //                 temp += customers[i + j];
        //         }
        //         angmax = max(angmax, temp);
        //     }
        // }

        //滑动窗口法
        for (int i = 0; i < customers.size(); i++){
            num += customers[i] - (customers[i] * grumpy[i]);
        }
        for (int i = 0; i < minutes;i++)
            ang += customers[i] * grumpy[i];
        angmax = ang;
        for (int i = 1; i < customers.size() - minutes+1; i++){
            ang = ang - customers[i - 1] * grumpy[i - 1] + customers[i - 1 + minutes] * grumpy[i - 1 + minutes];
            angmax = max(ang, angmax);
        }
        return num + angmax;
        for (int i = 0;i < 3;i++) {
            i = 3;
        }
        for (int i = 1; i > 3; i++) {
            
        }
    }
};