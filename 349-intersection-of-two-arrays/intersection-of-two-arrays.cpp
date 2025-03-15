class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i:nums1){
            mp[i]++;
        }
        vector<int> ans;
        for(int j:nums2){
            if(mp[j]>0){
                ans.push_back(j);
                mp[j]=0;
            }
        }
        return ans;
    }
};