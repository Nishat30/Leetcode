class Solution {
public:
    // Checks whether pattern repeated k times is a subsequence of s
    bool solve(string sub, string t, int k) {
        int cnt = 0, i = 0;
        for (char ch : t) {
            if (ch == sub[i]) {
                if (++i == sub.size()) {
                    i = 0;
                    if (++cnt == k)
                        return true;
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        string ans = "";
        queue<string> q;
        q.push("");

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                string next = curr + ch;
                if (solve(next, s, k)) {
                    ans = next;
                    q.push(next);
                }
            }
        }
        return ans;
    }
};