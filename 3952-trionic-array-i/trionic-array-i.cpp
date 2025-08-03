class Solution {
public:
    bool isTrionic(vector<int>& nums) 
    {
        int p=-1,q=-1;
        for(int i=1;i<nums.size()-1;i++)
            {
                if(nums[i]==nums[i-1]) //strictly condition
                    return false;
                if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
                if(p == -1) //seen a maxima
                    p = i;
                else 
                    return false;
                if(nums[i]<nums[i-1] && nums[i]<nums[i+1])
                if(q==-1) //seen a minima
                    q = i;
                else
                    return false;
            }
        return p!=-1 && q!=-1 && p<q; //seen and maxima comes first
        
    }
};