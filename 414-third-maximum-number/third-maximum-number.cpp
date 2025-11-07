class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int maxi=0;
        int ans=0;
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i:nums){
            if(mp.find(i)!=mp.end()){
                continue;
            }
            maxi=max(maxi,i);
            ans=i;
            cnt++;
            mp[i]++;
            if(cnt==3){return ans;}
        }
        return maxi;
    }
};