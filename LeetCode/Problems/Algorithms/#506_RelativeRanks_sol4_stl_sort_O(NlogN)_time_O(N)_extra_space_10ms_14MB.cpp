class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int N = score.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (score[lhs] > score[rhs]);
             });
        
        vector<string> rank(N);
        int currentRank = 1;
        for(int i: p){
            if(currentRank == 1){
                rank[i] = "Gold Medal";
            }else if(currentRank == 2){
                rank[i] = "Silver Medal";
            }else if(currentRank == 3){
                rank[i] = "Bronze Medal";
            }else{
                rank[i] = to_string(currentRank);
            }
            currentRank += 1;
        }

        return rank;
    }
};