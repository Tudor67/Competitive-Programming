class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        const int P = players.size();
        const int T = trainers.size();

        vector<int> sortedPlayers = players;
        sort(sortedPlayers.begin(), sortedPlayers.end());

        vector<int> sortedTrainers = trainers;
        sort(sortedTrainers.begin(), sortedTrainers.end());

        int maxMatchings = 0;
        int tIdx = 0;
        for(int pIdx = 0; pIdx < P; ++pIdx){
            while(tIdx < T && sortedTrainers[tIdx] < sortedPlayers[pIdx]){
                tIdx += 1;
            }
            if(tIdx < T){
                maxMatchings += 1;
                tIdx += 1;
            }
        }

        return maxMatchings;
    }
};