class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>mp;
        int repeated=-1,missing=-1;
        for(auto i:grid){
            for(int j:i){
                mp[j]++;
            }
        }
        for (int i = 1; i <= n * n; i++) {
            if (mp[i] == 2) repeated = i; 
            if (mp[i] == 0) missing = i;
            if (repeated != -1 && missing != -1) break;  
        }
        return {repeated,missing};
    }
};