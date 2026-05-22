class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        auto idx=-1;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]%2!=0){
                if(mp[s[i]]>maxi){
                    maxi=mp[s[i]];
                    idx=i;
                }
            }
        }
        if(idx!=-1){
           mp[s[idx]]=0;
        }
        int cnt=0;
        if(mp.size()==1){
            return s.length();
        }
        for(auto i:mp){
            if(i.second%2==0){
                cnt+=i.second;
            }else{
                cnt+=i.second-1;
            }
        }
        return cnt+maxi;
    }
};