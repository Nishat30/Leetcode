class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>mp;
        vector<int> ans(2);
        for(auto i:grid){
            for(int j:i){
                mp[j]++;
            }
        }
        for (int i = 1; i <= n * n; i++) {
            if (mp[i] == 2) ans[0] = i;  
            if (mp[i] == 0) ans[1] = i;  
        }
        return ans;
    }
};