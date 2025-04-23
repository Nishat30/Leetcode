class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> groups;
        int prevSum = 0;

        for (int i = 1; i <= n; ++i) {
            if (i % 10 == 0) {
                int num = i;
                prevSum = 0;
                while (num > 0) {
                    prevSum += num % 10;
                    num /= 10;
                }
            } else {
                prevSum += 1;
            }
            groups[prevSum]++;
        }

        int maxSize = 0;
        for (auto& [key, count] : groups)
            maxSize = max(maxSize, count);

        int res = 0;
        for (auto& [key, count] : groups)
            if (count == maxSize) res++;

        return res;
    }
};