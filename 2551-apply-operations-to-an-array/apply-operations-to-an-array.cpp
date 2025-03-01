class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> temp(nums.begin(),nums.end());
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i]==temp[i+1]){
                temp[i]=temp[i]*2;
                temp[i+1]=0;
            }
        }
        int n=temp.size();
        vector<int>num;
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=0){
                num.push_back(temp[i]);
            }
        }
        int nums_size=num.size();
        int zero_count=n-nums_size;
        for(int i=0;i<zero_count;i++){
            num.push_back(0);
        }
        return num;
    }
};