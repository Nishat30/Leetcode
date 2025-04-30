class Solution {
public:
    int strStr(string haystack, string needle) {
        int t=needle.length();
        int cnt=0;
        for(int i=0;i<haystack.length();i++){
            int j=0;
            cnt=0;
            if(haystack[i]==needle[j]){
                int idx=i;
                while(haystack[idx]==needle[j] && j<t){
                    cnt++;
                    j++;
                    idx++;
                }
                if(cnt==t) return i;
            }
        }
        return -1;
    }
};