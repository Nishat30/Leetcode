class Solution {
public:
    char kthCharacter(int k) {
        string ans;
        ans.push_back('a');
        while(ans.length()<k){
            string temp;
            string s=ans;
            for(char i:s){
                char next = (i == 'z') ? 'a' : i + 1;
                temp.push_back(next);
            }
            ans+=(temp);
        }
        return ans[k-1];
    }
};