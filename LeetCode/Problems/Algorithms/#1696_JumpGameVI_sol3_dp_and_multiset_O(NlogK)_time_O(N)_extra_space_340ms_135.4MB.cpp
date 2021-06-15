class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;
        vector<int> maxScore(N);
        maxScore[0] = nums[0];
        multiset<int> scores;
        scores.insert(maxScore[0]);
        for(int i = 1; i < N; ++i){
            maxScore[i] = nums[i] + *scores.rbegin();
            scores.insert(maxScore[i]);
            if(scores.size() > k){
                scores.erase(scores.find(maxScore[i - k]));
            }
        }
        return maxScore[N - 1];
    }
};