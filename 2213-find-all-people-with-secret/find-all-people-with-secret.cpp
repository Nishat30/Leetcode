class UnionFind {
public:
    UnionFind(int n) {
        group_ = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            group_[i] = i;
        }
    }

    int Find(int i) {
        current_round_.insert(i);
        if (group_[i] != i) {
            group_[i] = Find(group_[i]);
        }
        return group_[i];
    }

    int UnionTwo(int i, int j) {
        int pi = Find(i);
        int pj = Find(j);
        if (pi > pj) {
            swap(pi, pj);
        }
        group_[pj] = pi;
        return pi;
    }

    void ResetCurrentRound() {
        // Update all groups.
        for (int i : current_round_) {
            Find(i);
        }
        // Reset all none-zero groups.
        for (int i : current_round_) {
            if (group_[i] != 0) {
                group_[i] = i;
            }
        }
        current_round_.clear();
    }

private:
    vector<int> group_;
    unordered_set<int> current_round_;
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        auto compare = [](const vector<int>& meeting0, const vector<int>& meeting1) {
            return meeting0[2] < meeting1[2];
        };
        sort(meetings.begin(), meetings.end(), compare);
        
        UnionFind uf(n);
        uf.UnionTwo(0, firstPerson);
        for (int i = 0; i < meetings.size(); ++i) {
            uf.UnionTwo(meetings[i][0], meetings[i][1]);
            if (i + 1 == meetings.size() || meetings[i][2] < meetings[i + 1][2]) {
                // End of current round.
                uf.ResetCurrentRound();
            }
        }

        // Recover results.
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (uf.Find(i) == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};