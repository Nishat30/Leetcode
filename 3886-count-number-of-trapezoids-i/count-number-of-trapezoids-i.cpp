class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        //combination formula used!
        //n*(n-1)2
        int mod=1e9 + 7;
        long long ans=0;
        unordered_map<int,vector<int>> adj;
        for(auto i:points){
            adj[i[1]].push_back(i[0]); //y axis ka basis m
        }
        vector<long long> cnt;
        for(auto i:adj){
            int n=i.second.size();
            if(n>=2){
                cnt.push_back(((1LL*(n)*(n-1))/2) %mod);//can make trapezoid
            }
        }
        
        long long cal=0;
        long long com=0;
        for(auto i:cnt){
            cal=(cal+i)%mod;
            com=(com+(i*i)%mod)%mod;
        }
        //
        ans=((cal*cal)%mod- com)%mod;
        const int inv2=500000004; //to remove above plus mod 
        ans=(ans*inv2)%mod;
        return (int)ans;
        
    }
};