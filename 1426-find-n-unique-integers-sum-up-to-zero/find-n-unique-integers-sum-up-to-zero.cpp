class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2!=0){
        ans.push_back(0);}
        int j=1;
        while(ans.size()!=n){
            ans.push_back(j);
            ans.push_back(-j);
            j++;
        }
        return ans;
    }
};