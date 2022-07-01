class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int N = score.size();
        const int MAX_SCORE = *max_element(score.begin(), score.end());
        
        vector<int> suffCount(MAX_SCORE + 1);
        for(int currentScore: score){
            suffCount[currentScore] += 1;
        }
        
        for(int currentScore = MAX_SCORE - 1; currentScore >= 0; --currentScore){
            suffCount[currentScore] += suffCount[currentScore + 1];
        }
        
        vector<string> answer(N);
        for(int idx = 0; idx < N; ++idx){
            int place = suffCount[score[idx]] - 1;
            if(place == 0){
                answer[idx] = "Gold Medal";
            }else if(place == 1){
                answer[idx] = "Silver Medal";
            }else if(place == 2){
                answer[idx] = "Bronze Medal";
            }else{
                answer[idx] = to_string(place + 1);
            }
        }
        
        return answer;
    }
};