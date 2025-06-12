class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n= nums.size();
        vector<int> arr(n+n);
        int j=0;
        for(int i=0;i<n;i++){
            arr[j++]=nums[i];
        }
        for(int i=0;i<n;i++){
            arr[j++]=nums[i];
        }
        int maxi=0;
        for(int i=1;i<nums.size()*2;i++){
            int diff=abs(arr[i]-arr[i-1]);
            maxi=max(maxi,diff);
        }
        return maxi;
    }
};