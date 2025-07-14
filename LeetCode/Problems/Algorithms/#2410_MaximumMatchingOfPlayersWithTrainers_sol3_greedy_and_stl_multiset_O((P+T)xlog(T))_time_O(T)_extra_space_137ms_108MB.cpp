class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        const int P = players.size();
        const int T = trainers.size();

        int maxMatchings = 0;
        multiset<int> tMultiset(trainers.begin(), trainers.end());
        for(int player: players){
            multiset<int>::iterator it = tMultiset.lower_bound(player);
            if(it != tMultiset.end()){
                maxMatchings += 1;
                tMultiset.erase(it);
            }
        }

        return maxMatchings;
    }
};