class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double total_sum=0;
        for(int i:nums){
            pq.push(i);
            total_sum+=i;
        }
        double halve_sum=total_sum/2;
        int count=0;
        while(total_sum>halve_sum){
            double ele=pq.top()/2;
            pq.pop();
            total_sum-=ele;
            pq.push(ele);
            count++;
        }
        return count;
    }
};