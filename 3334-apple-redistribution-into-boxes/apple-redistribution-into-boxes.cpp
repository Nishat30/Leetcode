class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(int i:apple){
            sum+=i;
        }
        int tot_sum=0;
        int cnt=0;
        sort(capacity.begin(),capacity.end());
        for(int i=capacity.size()-1;i>=0;i--){
            tot_sum+=capacity[i];
            cnt++;
            if(tot_sum>=sum){
                return cnt;
            }
        }
        return cnt;
    }
};