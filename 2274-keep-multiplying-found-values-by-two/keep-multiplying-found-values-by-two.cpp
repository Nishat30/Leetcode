class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int i:nums)  {
            if(i==original){
                ans=i;
            }
            mp[i]++;
        }
        if(ans==0){
            return original;
        }
        bool flag=true;
        while(flag){
            if(mp.find(ans)!=mp.end()){
                ans=ans*2;
            }else{
                flag=false;
            }
        }
        return ans;
    }
};