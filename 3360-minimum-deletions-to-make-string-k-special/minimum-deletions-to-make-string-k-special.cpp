class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        vector<int> cnt;
        for(int i=0;i<26;i++){
            if(freq[i]!=0) cnt.push_back(freq[i]);
        }
        sort(cnt.begin(),cnt.end());
        int ans = INT_MAX;
        
        for (int i = 0; i < cnt.size(); i++) {
            int target = cnt[i]; // try making all frequencies <= target + k
            int del = 0;
            for (int f : cnt) {
                if (f < target) del += f;
                else if (f > target + k) del += f - (target + k);
            }
            ans = min(ans, del);
        }
        return ans;
    }
};