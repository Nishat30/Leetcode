class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int cnt=0;
        int first_day=meetings[0][0];
        cnt=first_day-1;
        int prev_day=meetings[0][1];
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]>prev_day){
            cnt+=meetings[i][0]-prev_day-1;}
            prev_day = max(prev_day, meetings[i][1]);
        }
        cnt+=days-prev_day;
        return cnt;
    }
};