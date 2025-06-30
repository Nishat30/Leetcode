class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, i = 0;

        while (i < nums.size()) {
            int count_i = 1, count_ip1 = 0;
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[i]) {
                count_i++;
                j++;
            }
            int temp = j;
            while (temp < nums.size() && nums[temp] == nums[i] + 1) {
                count_ip1++;
                temp++;
            }
            if (count_ip1 > 0) {
                ans = max(ans, count_i + count_ip1);
            }
            i = j; 
        }

        return ans;
    }
};
