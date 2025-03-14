class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;
        for (int i : candies) total += i;

        int left = 1, right = total / k, ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long count = 0;
            for (int c : candies) {
                count += c / mid;
            }

            if (count >= k) {  
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};