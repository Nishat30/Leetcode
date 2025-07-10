class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size();
        int i=0;
        //left
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i=i+1;
        }
        //middle overlap
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]= min(newInterval[0],intervals[i][0]);
            newInterval[1]= max(newInterval[1],intervals[i][1]);
            i=i+1;
        }
        res.push_back(newInterval);
        //right
        while(i<n){
            res.push_back(intervals[i]);
            i=i+1;
        }
        return res;
    }
};