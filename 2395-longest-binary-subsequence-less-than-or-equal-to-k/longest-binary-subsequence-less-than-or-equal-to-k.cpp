class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt=0;
        for(auto& ch:s){
            if(ch=='0'){cnt++;}
        }

        int num=0, pos=0;
        int ans = 0;

        // traverse from last & form new string or num greedly
        for(int i=s.size()-1;i>=0;i-=1){
            if(s[i]=='1'){
                int tmp = (num | (1<<pos));
                if(tmp <= k){
                    num = tmp;
                    pos++;
                }
                else{
                    break;
                }
            }
            else{
                pos++;
                cnt--;
            }

            ans = max(ans, pos+cnt);

            if(pos>=31){break;}
        }
        
        return ans;
    }
};