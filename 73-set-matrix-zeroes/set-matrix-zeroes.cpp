class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    visited[i][j]=true;
                }
            }
        }
        //(0,3) (i,j)
        //row- (0,0) (0,1) (0,2) (0,3) i
        //col- (0,3) (1,3) (2,3) j
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==true){
                    //row-zero
                    for(int k=0;k<m;k++){
                        matrix[i][k]=0;
                    }
                    //column-zero
                    for(int k=0;k<n;k++){
                        matrix[k][j]=0;
                    }
                }
            }
        }


    }
};