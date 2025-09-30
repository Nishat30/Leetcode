class Solution {
public:
    int triangularSum(vector<int>& nums) {
        queue<int> q;
        for(int i:nums){
            q.push(i);
        }
        while(q.size()!=1){
            queue<int> temp;
            while(q.size()!=1){
                int num1=q.front();
                q.pop();
                int num2=q.front();
                temp.push((num1+num2)%10);
            }
            q.pop();
            q=temp;
        }
        return q.front();
    }
};