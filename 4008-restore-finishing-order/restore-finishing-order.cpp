class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int> mp;
        for(int i:friends){
            mp[i]++;
        }
        vector<int> ans;
        for(int i=0;i<order.size();i++){
            if(mp.find(order[i])!=mp.end()){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};