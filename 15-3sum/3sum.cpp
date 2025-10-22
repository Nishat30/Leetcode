class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        if(mp.size()==1 && nums[0]==0){
            return {{0,0,0}};
        }
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int>temp;
                int sum=nums[i]+nums[j];
                if(sum==0){
                    if((nums[i]==0 && nums[j]==0) && mp[0]<=2){
                        continue;
                    }else if(nums[i]==0 && mp[0]<=1){
                        continue;
                    }else if(nums[j]==0 && mp[0]<=1){
                        continue;
                    }else if(mp.find(0)!=mp.end()){
                        vector<int> temp = {nums[i], nums[j], 0};
                        sort(temp.begin(), temp.end()); 
                        st.insert(temp);
                    }
                }
                else if(mp.find(-(sum))!=mp.end()){
                    if(mp[-(sum)]<=1 && (nums[i]==-sum) || (nums[j]==-sum)){
                        continue;
                    }
                    vector<int> temp = {nums[i], nums[j], -sum};
                    sort(temp.begin(), temp.end()); // to handle different orderings
                    st.insert(temp);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};