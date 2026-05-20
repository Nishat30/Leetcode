class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<A.size();i++){
            int cnt=0;
            mp[A[i]]++;
            mp[B[i]]++;
            for(auto j:mp){
                if(j.second>1){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};