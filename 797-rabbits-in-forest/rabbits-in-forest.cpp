class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map <int,int> mpp;
        for (int i : answers) mpp[i]++;
        int total=0;
        for (auto& p : mpp){
            int  x=p.first;
            int count=p.second; //kitne logon se answer dia

            int grup_size=(x+1);
            int groups = ceil((double)count/grup_size);
            total+=groups*grup_size;
        }
        return total;
    }
};