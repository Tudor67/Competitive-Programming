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
        
        vector<string> answer(N);
        for(int i = 0; i < N; ++i){
            int idx = p[i];
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