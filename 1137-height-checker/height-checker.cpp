class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> check(heights.begin(),heights.end());
        sort(check.begin(),check.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=check[i]){
                cnt++;
            }
        }
        return cnt;
    }
};