class Solution {
public:
    int totalFruit(vector<int>& tree) {
        const int N = tree.size();
        
        int answer = 0;
        vector<int> cnt(N);
        int distinctTypes = 0;
        for(int i = 0, j = 0; j < N; ++j){
            distinctTypes += (cnt[tree[j]] == 0);
            cnt[tree[j]] += 1;
            while(distinctTypes > 2){
                cnt[tree[i]] -= 1;
                distinctTypes -= (cnt[tree[i]] == 0);
                i += 1;
            }
            answer = max(j - i + 1, answer);
        }
        
        return answer;
    }
};