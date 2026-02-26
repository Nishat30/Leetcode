class Solution {
public:
    int numSteps(string s) {
        int j=s.length()-1;
        int opr=0;
        while(s.length() > 1){
            j=s.length()-1;
            if(s[j]=='0'){
                s.pop_back();
            }else{
                int i=j;
                while(i>=0 && s[i]=='1'){
                    s[i]='0';
                    i--;
                }
                
                if(i>=0)
                    s[i]='1';
                else
                    s='1'+s;
            }
            opr++;
        }
        return opr;
    }
};