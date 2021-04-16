class TopVotedCandidate {
private:
    vector<pair<int, int>> winnerTimes;
    
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int winner = -1;
        int winnerVotes = 0;
        unordered_map<int, int> votes;
        for(int i = 0; i < (int)times.size(); ++i){
            votes[persons[i]] += 1;
            if(votes[persons[i]] >= winnerVotes){
                winnerVotes = votes[persons[i]];
                if(persons[i] != winner){
                    winner = persons[i];
                    winnerTimes.emplace_back(persons[i], times[i]);
                }
            }
        }
        winnerTimes.emplace_back(-1, INT_MAX);
    }
    
    int q(int t) {
        int l = 0;
        int r = (int)winnerTimes.size() - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(winnerTimes[mid].second <= t){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return winnerTimes[r - 1].first;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */