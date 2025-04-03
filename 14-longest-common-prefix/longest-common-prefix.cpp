class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        int len=prefix.length();
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            while(len>s.length() || prefix!=s.substr(0,len)){
                len--;
                if(len==0){
                    return "";
                }
                prefix=prefix.substr(0,len);
            }

        }
        return prefix;
    }
};