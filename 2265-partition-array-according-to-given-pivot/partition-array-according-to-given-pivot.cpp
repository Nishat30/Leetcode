class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> grea;
        vector<int> same;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                less.push_back(nums[i]);
            }else if(nums[i]==pivot){
                same.push_back(nums[i]);
            }else{
                grea.push_back(nums[i]);
            }
        }
        int j=0;
        vector<int> ans(nums.size());
        for(int i=0;i<less.size();i++){
            ans[j]=less[i];
            j++;
        }
        for(int i=0;i<same.size();i++){
            ans[j]=(same[i]);
            j++;
        }
        for(int i=0;i<grea.size();i++){
            ans[j]=(grea[i]);
            j++;
        }
        return ans;
    }
};