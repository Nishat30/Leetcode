class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int i=0,j=n-1;
        int e=n-1;
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                ans[e]=(abs(nums[i])*abs(nums[i]));
                e--;
                i++;
            }else{
                ans[e]=(abs(nums[j])*abs(nums[j]));
                e--;
                j--;
            }
        }
        return ans;
    }
};