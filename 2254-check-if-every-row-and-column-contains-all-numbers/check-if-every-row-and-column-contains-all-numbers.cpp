class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++) mp[i]++;

        // check rows
        for(int i=0;i<n;i++){
            unordered_map<int,int> temp = mp;
            for(int j=0;j<n;j++){
                if(--temp[matrix[i][j]] == 0) {
                    temp.erase(matrix[i][j]);
                }
            }
            if(!temp.empty()) return false;
        }

        // check cols
        for(int j=0;j<n;j++){
            unordered_map<int,int> temp = mp;
            for(int i=0;i<n;i++){
                if(--temp[matrix[i][j]] == 0) {
                    temp.erase(matrix[i][j]);
                }
            }
            if(!temp.empty()) return false;
        }

        return true;
    }
};
