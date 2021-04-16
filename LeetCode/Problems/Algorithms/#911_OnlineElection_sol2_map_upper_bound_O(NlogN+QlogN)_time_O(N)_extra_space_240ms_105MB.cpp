class TopVotedCandidate {
private:
    map<int, int> topVotedCandidateAtTime;
    
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
                    topVotedCandidateAtTime[times[i]] = persons[i];
                }
            }
        }
    }
    
    int q(int t) {
        return prev(topVotedCandidateAtTime.upper_bound(t))->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */