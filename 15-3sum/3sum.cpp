class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int p1, p2, p3;
        int n = nums.size();
        for(int i=0;i<n;i++){
            p1 = nums[i];
            if(p1>0) break;
            if(i>0 && p1 == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                p2 = nums[j];
                p3 = nums[k];
                if(p1 + p2 + p3 == 0){
                    result.push_back({p1, p2, p3});
                    while(j<n && p2 == nums[j]) j++;
                    while(k>0 && p3 == nums[k]) k--; 
                }else if(p1 + p2 + p3 > 0){
                    k--;
                }else{
                    j++;
                }
            }

        }
        return result;
    }
};