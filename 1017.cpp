#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> ans=vector<int>(32);
    int base = 31;
public:
    string baseNeg2(int n) {
        if (n == 0)
            return "0";
        while (n != 1) {
            if (n < 0) {
                n = n * -1 + 1;
                ans[base--] = !(n % 2);
                n = n / 2;
            }
            else {
                ans[base--]= n % 2 ;
                n = n / 2 * -1;
            }
        }
        ans[base]= 1;
        string ress;
        base = 0;
        while (ans[base] == 0)
            base++;
        while (base < 32)
            ress.push_back(ans[base++] + '0');
        return ress;
    }
};

int main() {
    Solution S;
    cout << S.baseNeg2(3);
    vector<int> b;
}