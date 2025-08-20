class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int col0 = 1;
        // Step 1: Mark rows & cols
        for (int i=0; i<n;i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j=1;j<m;j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // Step 2: Fill from (1,1) → (n-1,m-1)
        for (int i=1;i<n;i++) {
            for (int j=1; j<m;j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // Step 3: Handle first row
        if (matrix[0][0] == 0) {
            for (int j=0;j<m;j++) matrix[0][j] = 0;
        }
        // Step 4: Handle first col
        if (col0 == 0) {
            for (int i=0;i<n;i++) matrix[i][0] = 0;
        }
    }
};
