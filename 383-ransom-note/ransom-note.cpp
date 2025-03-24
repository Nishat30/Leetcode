class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(char i:magazine){
            mp[i]++;
        }
        for(char j:ransomNote){
            if(mp.find(j)==mp.end() || mp[j]==0){
                return false;
            }else{
                mp[j]--;
            }
        }
        return true;
    }
};