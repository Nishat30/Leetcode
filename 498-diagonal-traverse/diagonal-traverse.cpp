class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        vector<vector<bool>> visited(n, vector<bool>(m, true));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]){
                    int start = ans.size();
                    ans.push_back(mat[i][j]);
                    visited[i][j] = false;

                    int a = i+1, b = j-1;
                    while(a<n && b>=0 && visited[a][b]){
                        ans.push_back(mat[a][b]);
                        visited[a][b] = false;
                        a++; b--;
                    }

                    // reverse this diagonal only
                    if((i+j) % 2 == 0){
                        reverse(ans.begin() + start, ans.end());
                    }
                }
            }
        }
        return ans;
    }
};
