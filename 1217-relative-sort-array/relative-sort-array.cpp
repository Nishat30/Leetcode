class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int ,int> mp2;
        for(int j:arr1){
            mp2[j]++;
        }
        vector<int> ans;
        for(int i:arr2){
            while(mp2[i]--!=0){
                ans.push_back(i);
            }
        }
        vector<int> temp;
        for(auto& pair:mp2){
            while(pair.second-->0){
                temp.push_back(pair.first);
            }
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};