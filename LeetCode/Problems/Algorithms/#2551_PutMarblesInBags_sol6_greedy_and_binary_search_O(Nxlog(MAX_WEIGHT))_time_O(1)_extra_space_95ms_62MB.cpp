class Solution {
private:
    int countAdjSumsLessThanOrEqualToS(vector<int>& weights, const long long S){
        const int N = weights.size();
        int validAdjSums = 0;
        for(int i = 0; i + 1 < N; ++i){
            if(weights[i] + weights[i + 1] <= S){
                validAdjSums += 1;
            }
        }
        return validAdjSums;
    }

    long long computeMinSplitScore(vector<int>& weights, int k) {
        const int N = weights.size();
        const int MIN_WEIGHT = *min_element(weights.begin(), weights.end());
        const int MAX_WEIGHT = *max_element(weights.begin(), weights.end());

        long long l = MIN_WEIGHT;
        long long r = 2 * MAX_WEIGHT;
        while(l != r){
            long long mid = (l + r) / 2;
            if(countAdjSumsLessThanOrEqualToS(weights, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        const long long SUM_THRESHOLD = r;
        long long score = 0;
        long long splits = 0;
        for(int i = 0; i + 1 < N; ++i){
            int adjSum = weights[i] + weights[i + 1];
            if(adjSum <= SUM_THRESHOLD){
                score += adjSum;
                splits += 1;
            }
        }

        return (score - (splits - k) * SUM_THRESHOLD);
    }

public:
    long long putMarbles(vector<int>& weights, int k) {
        const int N = weights.size();

        long long totalAdjSum = 0;
        for(int i = 0; i + 1 < N; ++i){
            totalAdjSum += (weights[i] + weights[i + 1]);
        }

        long long minSplitScore = computeMinSplitScore(weights, k - 1);
        long long maxSplitScore = totalAdjSum - computeMinSplitScore(weights, (N - 1) - (k - 1));
        
        return (maxSplitScore - minSplitScore);
    }
};