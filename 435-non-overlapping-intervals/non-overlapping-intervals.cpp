class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> meet;
        for(int i=0;i<intervals.size();i++){
            meet.push_back({intervals[i][1], intervals[i][0]});
        }
        sort(meet.begin(),meet.end());
        int cnt=1;
        int check=meet[0].first;
        for(int i=1;i<intervals.size();i++){
            if(meet[i].second>=check){
                cnt++;
                check=meet[i].first;
            }
        }
        return intervals.size()-cnt;
    }
};