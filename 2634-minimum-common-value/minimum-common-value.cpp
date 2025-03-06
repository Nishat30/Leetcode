class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i:nums1){
            mp[i]++;
        }
        for(int i:nums2){
            if(mp.find(i)!=mp.end()){
                return i;
            }
        }
        return -1;
    }
};