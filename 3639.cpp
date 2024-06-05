#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> res;
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int rows = grid.size() , columns = grid[0].size();
        for (int i = 0; i < columns; i++)
            res.emplace_back(getlen(grid[0][i]));
        for (int r = 1; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                res[c] = max(res[c] , getlen(grid[r][c]));
            }
        }
        return res;
    }
    int getlen(int n) {
        int len = (n > 0 ? 0 : 1);
        n = abs(n);
        while (n > 0) {
            n /= 10;
            len++;
        }
        return len;
    }
};