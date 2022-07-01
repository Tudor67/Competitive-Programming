class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int N = score.size();
        
        vector<pair<int, int>> scoreIdx(N);
        for(int i = 0; i < N; ++i){
            scoreIdx[i] = {score[i], i};
        }
        
        sort(scoreIdx.rbegin(), scoreIdx.rend());
        
        vector<string> answer(N);
        for(int i = 0; i < N; ++i){
            int idx = scoreIdx[i].second;
            if(i == 0){
                answer[idx] = "Gold Medal";
            }else if(i == 1){
                answer[idx] = "Silver Medal";
            }else if(i == 2){
                answer[idx] = "Bronze Medal";
            }else{
                answer[idx] = to_string(i + 1);
            }
        }
        
        return answer;
    }
};