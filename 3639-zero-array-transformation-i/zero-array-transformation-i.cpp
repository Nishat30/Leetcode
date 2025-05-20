class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(auto i:queries){
            int l=i[0],r=i[1];
            diff[l]-=1;
            if(r+1<=n){
                diff[r+1]+=1;
            }
        }
        int cnt=0;
        for(int i=0;i<nums.size();++i){
            cnt+=diff[i];
            if(nums[i]!=0){
                nums[i]+=cnt;
            }           
        }
        for(int i:nums){
            if(i>0)return false;
        }
        return true;
    }
};