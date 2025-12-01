class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        long long sum=0;
        for(int i:batteries){
            sum+=i;
        }
        for(int i=batteries.size()-1; ;i--){
            if(batteries[i]<=sum/n){
                return sum/n;
            }
            sum-=batteries[i];
            --n;
        }
        return 0;
    }
};
    