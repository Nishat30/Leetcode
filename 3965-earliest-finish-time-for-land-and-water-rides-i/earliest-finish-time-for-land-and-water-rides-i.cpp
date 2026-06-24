class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int,int>>land;
        for(int i=0;i<landStartTime.size();i++){
            land.push_back({landStartTime[i],landDuration[i]});
        }

        vector<pair<int,int>>water;
        for(int i=0;i<waterStartTime.size();i++){
            water.push_back({waterStartTime[i],waterDuration[i]});
        }
        int min_time=INT_MAX;
        for(auto& i:land){
            for(auto& j:water){
                int time1=max(j.first,i.first+i.second)+j.second; //max(6,2+4)+3=9
                min_time=min(min_time,time1);

                int time2=max(i.first,j.first+j.second)+i.second;//max(5,11)+3=14
                min_time=min(min_time,time2);   
            }
        }
        return min_time;
    }
};