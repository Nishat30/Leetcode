class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int a=nums[0];
        int b=nums[nums.size()-1];
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        bool flag=false;
        for(int i:nums){
            if(mp[i]==1){
                flag=true;
            }
        }
        if(mp.size()==1 && nums.size()==k && nums[0]==0)return 0;
        else if(mp.size()==1 && nums.size()==k && nums[0]!=0 ) return nums[0];
        if(!flag)return -1;
        int maxi=0;
        if(k==nums.size()){
            for(int i:nums){
                if(i>maxi) maxi=i;
            }
            return maxi;
        }
        if(k==1){
            for(int i:nums){
                if(i>maxi && !(mp[i]>1)) maxi=i;
            }
            return maxi; 
        }
        if(mp[a]>1 && mp[b]>1)return -1;
        if(mp[a]>1){
            return b;
        }else if(mp[b]>1){
            return a;
        }else{
            if(a>b){
                return a;
            }
        }
        return b;
    }
};