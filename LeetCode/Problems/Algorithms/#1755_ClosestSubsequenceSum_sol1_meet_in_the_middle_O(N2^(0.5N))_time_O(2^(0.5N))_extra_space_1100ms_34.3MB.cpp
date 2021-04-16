class Solution {
private:
    vector<int> generateAllSums(vector<int>& nums, const int& L, const int& R){
        const int M = R - L + 1;
        const int FULL_MASK = (1 << M) - 1;
        vector<int> sumValues(FULL_MASK + 1);
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            int sum = 0;
            for(int bit = 0; bit < M; ++bit){
                if((mask >> bit) & 1){
                    sum += nums[L + bit];
                }
            }
            sumValues[mask] = sum;
        }
        return sumValues;
    }
    
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        if(nums.size() == 1){
            return min(abs(0 - goal), abs(nums[0] - goal));
        }
        
        const int N = nums.size();
        vector<int> sumValues1 = generateAllSums(nums, 0, N / 2 - 1);
        vector<int> sumValues2 = generateAllSums(nums, N / 2, N - 1);
        
        sort(sumValues2.begin(), sumValues2.end());
        
        int answer = abs(goal);
        for(int sum1: sumValues1){
            int sum1Complement = goal - sum1;
            vector<int>::iterator it = lower_bound(sumValues2.begin(), sumValues2.end(), sum1Complement);
            if(it != sumValues2.end()){
                int sum2 = *it;
                answer = min(abs(sum1 + sum2 - goal), answer);
            }
            if(it != sumValues2.begin()){
                int sum2 = *prev(it);
                answer = min(abs(sum1 + sum2 - goal), answer);
            }
        }
        
        return answer;
    }
};