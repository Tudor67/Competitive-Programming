class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int N = nums.size();

        int candidate = nums[N / 2];
        int candidateFreq = upper_bound(nums.begin(), nums.end(), candidate) -
                            lower_bound(nums.begin(), nums.end(), candidate);

        if(candidateFreq <= N / 2){
            return N % 2;
        }
        return N - 2 * (N - candidateFreq);
    }
};