class TopVotedCandidate {
private:
    map<int, int> topVotedCandidateAtTime;
    
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int, int> votes;
        map<int, int> lastTime;
        set<tuple<int, int, int>> votesTimePersonSet;
        for(int i = 0; i < (int)times.size(); ++i){
            votesTimePersonSet.erase({votes[persons[i]], lastTime[persons[i]], persons[i]});
            votes[persons[i]] += 1;
            lastTime[persons[i]] = times[i];
            votesTimePersonSet.insert({votes[persons[i]], times[i], persons[i]});
            topVotedCandidateAtTime[times[i]] = get<2>(*votesTimePersonSet.rbegin());
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