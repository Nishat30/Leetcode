class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans="";
        int n=s.length();
        for(int i=0;i<s.length();i++){
            char c=s[(i+k)%n];
            ans.push_back(c);
        }
        return ans;
    }
};