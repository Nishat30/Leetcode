class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n=s.length();
        if(n%k==0){
            for(int i=0;i<n;i+=k){
                string c = s.substr(i, k);
                ans.push_back(c);
            }
        }else{
            int extra=n%k;
            for(int i=0;i<n-extra;i+=k){
                string c = s.substr(i, k);
                ans.push_back(c);
            }
            string c;
            int need=k-(n%k);
            for(int i=n-extra;i<n;i++){
                c.push_back(s[i]);
            }
            while(need){
                c.push_back(fill);
                need--;
            }
            ans.push_back(c);
        }
        return ans;
    }
};