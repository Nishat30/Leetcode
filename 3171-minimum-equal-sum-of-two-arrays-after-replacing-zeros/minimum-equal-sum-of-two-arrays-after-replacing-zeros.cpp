class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long zero_cnt1=0;
        long long sum1=0;
        for(int i:nums1){
            if(i==0) zero_cnt1++;
            else{
                sum1+=i;
            }
        }
        long long zero_cnt2=0;
        long long sum2=0;
        for(int i:nums2){
            if(i==0) zero_cnt2++;
            else{
                sum2+=i;
            }
        }
        if(zero_cnt1==0){
            if(sum1==sum2+zero_cnt2) return sum1;
            if(sum1<sum2+zero_cnt2) return -1;
        }
        if(zero_cnt2==0){
            if(sum2==sum1+zero_cnt1) return sum2;
            if(sum2<sum1+zero_cnt1)return -1;
        }
        if(sum1==sum2){
            if(zero_cnt1==zero_cnt2) return sum1+zero_cnt1;
            else if(zero_cnt1>zero_cnt2) return sum1+zero_cnt1;
            else return zero_cnt2+sum1;
        }
        else if(sum2>sum1){
            long long min_sum=sum2+zero_cnt2;
            if(sum1+zero_cnt1<min_sum) return min_sum;
            else if(zero_cnt2!=0){
                return sum1+zero_cnt1;
            }else{
                return -1;
            }
        }else if(sum1>sum2){
            long long min_sum=sum1+zero_cnt1;
            if(sum2+zero_cnt2<min_sum) return min_sum;
            else if(zero_cnt1!=0){
                return sum2+zero_cnt2;
            }else{
                return -1;
            }
        }
        return -1;
    }
};