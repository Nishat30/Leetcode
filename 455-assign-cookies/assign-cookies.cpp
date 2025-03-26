class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int j=0;
        while(j < s.size() && cnt < g.size()){
            if(g[cnt]<=s[j]){
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};