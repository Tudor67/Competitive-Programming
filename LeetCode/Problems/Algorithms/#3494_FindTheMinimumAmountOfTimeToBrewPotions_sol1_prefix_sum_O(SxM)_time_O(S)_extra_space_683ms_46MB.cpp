class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        const int S = skill.size();
        const int M = mana.size();

        vector<vector<long long>> prefSum(2, vector<long long>(S));
        for(int i = 0; i < M; ++i){
            long long delta = 0;
            for(int j = 0; j < S; ++j){
                prefSum[i % 2][j] = mana[i] * skill[j] + (j == 0 ? 0 : prefSum[i % 2][j - 1]);
                delta = max(delta, prefSum[(i + 1) % 2][j] - (j == 0 ? 0 : prefSum[i % 2][j - 1]));
            }

            for(int j = 0; j < S; ++j){
                prefSum[i % 2][j] += delta;
            }
        }

        return prefSum[(M - 1) % 2].back();
    }
};