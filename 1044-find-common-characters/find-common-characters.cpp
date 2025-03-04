class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> mp;
        vector<string> ans;
        for (char c : words[0]) {
            mp[c]++;
        }
        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> temp;
            for (char c : words[i]) {
                temp[c]++;
            }
            for (auto& pair : mp) {
                if (temp.find(pair.first) != temp.end()) {
                    pair.second = min(pair.second, temp[pair.first]);
                } else {
                    pair.second = 0; 
                }
            }
        }
        for (auto& pair : mp) {
            while (pair.second-- > 0) {
                ans.push_back(string(1, pair.first));
            }
        }

        return ans;
    }
};
