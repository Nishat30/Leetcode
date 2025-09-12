class Solution {
public:
    bool doesAliceWin(string s) {
        bool ans;
        string vow;
        for(char c:s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vow.push_back(c);}
        }
        if(vow.length()==0)return false;
        if(vow.length()%2!=0)return true;
        return true;
    }
};