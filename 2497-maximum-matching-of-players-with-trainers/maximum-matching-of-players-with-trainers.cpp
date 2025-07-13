class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end()); 
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int t:trainers) {
            pq.push(t);
        }

        int cnt = 0;
        for (int i=0; i<players.size(); ++i) {
            while(!pq.empty() && pq.top()<players[i]) {
                pq.pop();
            }
            if (!pq.empty()) {
                cnt++;    
                pq.pop(); 
            }
        }
        return cnt;
    }
};
