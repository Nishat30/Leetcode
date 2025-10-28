class Solution {
public:
    bool canMakeAllZero(vector<int> nums, int curr, int direction) {
    int n = nums.size();
    while (curr >= 0 && curr < n) {
        if (nums[curr] == 0) {
            // Move in the current direction
            curr += direction;
        } else {
            // Decrease the value and reverse the direction
            nums[curr]--;
            direction = -direction;
            curr += direction;
        }
    }

    // Check if all elements are zero
    for (int num : nums) {
        if (num != 0) {
            return false;
        }
    }
    return true;
    }
    int countValidSelections(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    // Iterate through all positions where nums[curr] == 0
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            // Check for both directions: left (-1) and right (+1)
            bool leftValid = canMakeAllZero(nums, i, -1);
            bool rightValid = canMakeAllZero(nums, i, 1);

            // Increment count for each valid direction
            if (leftValid) count++;
            if (rightValid) count++;
        }
    }

    return count;
    }
};