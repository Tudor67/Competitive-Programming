class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int N = nums.size();

        int numFreq = 0;
        int numMaxFreq = 0;
        for(int i = 0; i < N; ++i){
            numFreq += 1;
            if(i == N - 1 || nums[i] != nums[i + 1]){
                numMaxFreq = max(numMaxFreq, numFreq);
                numFreq = 0;
            }
        }

        if(numMaxFreq <= N / 2){
            return N % 2;
        }
        return N - 2 * (N - numMaxFreq);
    }
};