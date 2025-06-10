class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(27,0);
        for(char i: s){
            freq[i-'a']++;
        }
        int even_freq=INT_MAX;
        int odd_freq=0;
        int ans=0;
        for(char i:s){
            if(freq[i-'a']%2==0){
                even_freq=min(even_freq,freq[i-'a']);
            }else{
                odd_freq=max(odd_freq,freq[i-'a']);
            }
        }
        return (odd_freq-even_freq);
    }
};