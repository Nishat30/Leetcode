class Solution {
public:
    vector<long long> prime(long long n){
        vector<bool> primes(n,true);
        primes[0]=primes[1]=false;
        for(long long i=2;i<n;i++){
            if (primes[i]) {
                for (long long j=i*i;j<n;j+=i) {
                    primes[j]=false;
                }
            }
        }
        vector<long long> p;
        for(long long i=0;i<n;i++){
            if(primes[i]){
                p.push_back(i);
            }
        }
        return p;
    }
    long long splitArray(vector<int>& nums) {
        if(nums.size()==2){
            return abs(nums[0]+nums[1]);
        }
        if(nums.size()==1){
            return nums[0];
        }
        long long n=nums.size();
        vector<long long> primes=prime(n);
        vector<long long> A;
        vector<long long> B;
        long long j=0;
        for(long long i=0;i<n;i++){
            if(j<primes.size() && primes[j]==i ){
                A.push_back(nums[i]);
                j++;
            }else{
                B.push_back(nums[i]);
            }
        }
        long long sum1=0;
        long long sum2=0;
        for(auto i:A){
            sum1+=i;
        }
        for(auto j:B){
            sum2+=j;
        }
        long long ans= abs(sum1-sum2);
        return ans;
    }
};