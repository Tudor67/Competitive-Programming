class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        const int N = nums.size();
        const int D = divisors.size();

        int maxScore = -1;
        int maxScoreDivisor = -1;
        for(int i = 0; i < D; ++i){
            int score = 0;
            for(int num: nums){
                if(num % divisors[i] == 0){
                    score += 1;
                }
            }
            if(score > maxScore || (score == maxScore && divisors[i] < maxScoreDivisor)){
                maxScore = score;
                maxScoreDivisor = divisors[i];
            }
        }

        return maxScoreDivisor;
    }
};