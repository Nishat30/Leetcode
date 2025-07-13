class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end()); // sort players ascending

        // Min-heap for trainers (so smallest available trainer is on top)
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int t : trainers) {
            pq.push(t);
        }

        int cnt = 0;
        for (int i = 0; i < players.size(); ++i) {
            // Pop trainers until we find one strong enough
            while (!pq.empty() && pq.top() < players[i]) {
                pq.pop();  // too weak
            }
            if (!pq.empty()) {
                cnt++;     // match found
                pq.pop();  // remove matched trainer
            }
        }
        return cnt;
    }
};
