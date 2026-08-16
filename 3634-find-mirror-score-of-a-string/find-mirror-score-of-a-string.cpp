class Solution {
public:
    long long calculateScore(string s) {
        long long ans = 0;
        vector<stack<int>> indices(26);
        
        for(int i = 0; i < s.size(); i++){
            int currChar = s[i] - 'a';
            int mirrorChar = 25 - currChar;

            if(!indices[mirrorChar].empty()){
                int j = indices[mirrorChar].top();
                indices[mirrorChar].pop();
                ans += i - j;
            } else {
                indices[currChar].push(i);
            }
        }

        return ans;
    }
};