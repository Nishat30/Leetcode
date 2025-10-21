class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        // Sort the array to make the two-pointer approach easier
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Avoid duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Store the triplet
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move left and right to avoid duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move both pointers inward
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // Move the left pointer to increase the sum
                    left++;
                } 
                else {
                    // Move the right pointer to decrease the sum
                    right--;
                }
            }
        }
        
        return ans;
    }
};
