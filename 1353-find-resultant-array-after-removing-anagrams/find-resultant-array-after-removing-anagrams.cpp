class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for (string &word : words) {
            if (ans.empty()) {
                ans.push_back(word);
            } else {
                string prev = ans.back();
                string sortedPrev = prev;
                string sortedCurr = word;
                sort(sortedPrev.begin(), sortedPrev.end());
                sort(sortedCurr.begin(), sortedCurr.end());
                if (sortedPrev != sortedCurr) {
                    ans.push_back(word);
                }
            }
        }
        return ans;
    }
};