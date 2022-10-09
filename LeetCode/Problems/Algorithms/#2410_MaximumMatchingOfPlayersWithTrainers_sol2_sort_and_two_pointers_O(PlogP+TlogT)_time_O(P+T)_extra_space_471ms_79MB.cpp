class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        const int P = players.size();
        const int T = trainers.size();
        
        vector<int> sortedPlayers = players;
        sort(sortedPlayers.begin(), sortedPlayers.end());
        
        vector<int> sortedTrainers = trainers;
        sort(sortedTrainers.begin(), sortedTrainers.end());
        
        int matchings = 0;
        int trainerIdx = 0;
        for(int playerIdx = 0; playerIdx < P; ++playerIdx){
            while(trainerIdx < T && sortedTrainers[trainerIdx] < sortedPlayers[playerIdx]){
                trainerIdx += 1;
            }
            if(trainerIdx < T){
                matchings += 1;
                trainerIdx += 1;
            }else{
                break;
            }
        }
        
        return matchings;
    }
};