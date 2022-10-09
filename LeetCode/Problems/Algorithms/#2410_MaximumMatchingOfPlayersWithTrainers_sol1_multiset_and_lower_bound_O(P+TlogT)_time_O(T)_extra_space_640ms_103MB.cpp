class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        const int P = players.size();
        const int T = trainers.size();
        
        multiset<int> trainersMultiset(trainers.begin(), trainers.end());
        
        int matchings = 0;
        for(int i = 0; i < P; ++i){
            multiset<int>::iterator it = trainersMultiset.lower_bound(players[i]);
            if(it != trainersMultiset.end()){
                trainersMultiset.erase(it);
                matchings += 1;
            }
        }
        
        return matchings;
    }
};