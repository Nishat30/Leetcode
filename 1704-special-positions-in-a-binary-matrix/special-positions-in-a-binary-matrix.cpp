class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt=0;
        int rows = mat.size(), cols = mat[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==1){
                    int row=0,col=0;
                    bool check=true;
                    // Check row
                    for (int col = 0; col < cols; col++) {
                        if (col != j && mat[i][col] == 1) {
                            check = false;
                            break;
                        }
                    }
                    // Check column
                    for (int row = 0; row < rows; row++) {
                        if (row != i && mat[row][j] == 1) {
                            check = false;
                            break;
                        }
                    }
                    if(check){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};