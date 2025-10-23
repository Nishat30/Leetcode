class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length()!=2){
            string temp;
            for(int i=0;i<s.length()-1;i++){
               int dig=(s[i]+s[i+1])%10;
               temp.push_back(dig);
            }
            s=temp;
        }
        if(s[0]==s[1]) return true;
        return false;
    }
};