class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int N = score.size();

        priority_queue<pair<int, int>> maxHeap;
        for(int i = 0; i < N; ++i){
            maxHeap.push({score[i], i});
        }

        vector<string> rank(N);
        for(int currentRank = 1; currentRank <= N; ++currentRank){
            int i = maxHeap.top().second;
            maxHeap.pop();

            if(currentRank == 1){
                rank[i] = "Gold Medal";
            }else if(currentRank == 2){
                rank[i] = "Silver Medal";
            }else if(currentRank == 3){
                rank[i] = "Bronze Medal";
            }else{
                rank[i] = to_string(currentRank);
            }
        }

        return rank;
    }
};