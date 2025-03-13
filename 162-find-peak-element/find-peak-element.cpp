class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
          return 0;
        }
        int l = 0;
        int r = nums.size() - 1;
        while(l<=r){
           int mid = l + (r-l)/2;
           if(mid+1 < n && mid-1>=0 && nums[mid]>nums[mid+1] && nums[mid] > nums[mid-1]){
                return mid;
            }else if(mid+1 < n && nums[mid]<nums[mid+1]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
       return nums[0]>nums[n-1] && nums[0] > nums[1] ? 0 : n-1;
    }
};