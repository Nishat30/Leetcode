class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int,int> mp;
        for(char i:s) mp[i-'0']++;
        for(char i:t) mp[i-'0']--;
        for(int i=0;i<t.length();i++){
            if(mp[t[i]-'0']!=0) return t[i];
        }
        return ' ';
    }
};