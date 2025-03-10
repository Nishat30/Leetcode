class Solution {
public:
    bool compare(string& s1,string& s2){
        if(s1.size()!=s2.size()+1) return false;
        int first = 0, second = 0;
        while (first < s1.size() && second < s2.size()) { 
            if (s1[first] == s2[second]) {
                second++;
            }
            first++;
        }
        return second == s2.size();
    }
    static bool comp(const string& s1, const string& s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp); 
        int n=words.size();
        int maxi=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};