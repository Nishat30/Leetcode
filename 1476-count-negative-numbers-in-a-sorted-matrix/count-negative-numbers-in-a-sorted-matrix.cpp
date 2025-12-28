class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, i = grid.size() - 1, j = 0, n = grid[0].size();
        while(i >= 0 && j < n) {
            if(grid[i][j] >= 0) {
                j++;
            } else {
                count += n - j;
                i--; 
            }
        }
        return count;
    }
};