class Solution {
public:
    void solve(vector<int>& nums,int i,int curr_or,int& cnt, int max_or){
        if(curr_or==max_or){
            cnt++;
        }
        for(int ind=i;ind<nums.size();ind++){
            solve(nums,ind+1,curr_or|nums[ind],cnt,max_or);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int max_or=0;
        for(int i:nums){
            max_or|=i;
        }
        int cnt=0;
        solve(nums,0,0,cnt,max_or);
        return cnt;
    }
};