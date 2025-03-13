class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> mp;
            int cnt=0;
            for(int j=i;j<s.length();j++){
            if(mp[s[j]]==1){
                break;
            }else {
                mp[s[j]]=1;
                cnt++;
                ans=max(ans,cnt);
            }
            }
        }
        return ans;
    }
};