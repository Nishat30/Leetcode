class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Reference array: [1,2,...,n]
        vector<int> check(n);
        for(int i=0; i<n; i++) check[i] = i+1;

        // Check rows
        for(int i=0; i<n; i++){
            vector<int> row = matrix[i];   // copy row
            sort(row.begin(), row.end());
            if(row != check) return false;
        }

        // Check columns
        for(int j=0; j<n; j++){
            vector<int> col;
            for(int i=0; i<n; i++){
                col.push_back(matrix[i][j]);
            }
            sort(col.begin(), col.end());
            if(col != check) return false;
        }

        return true;
    }
};
