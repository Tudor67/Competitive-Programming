class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int N = nums.size();

        // Step 1: Boyer Moore Voting algorithm
        int candidate = nums[0];
        int candidateVotes = 0;

        for(int num: nums){
            if(num == candidate){
                candidateVotes += 1;
            }else if(candidateVotes >= 1){
                candidateVotes -= 1;
            }else{
                candidate = num;
                candidateVotes = 1;
            }
        }

        int majorityElement = candidate;
        int majorityElementTotalFreq = count(nums.begin(), nums.end(), majorityElement);
        if(majorityElementTotalFreq * 2 <= N){
            return -1;
        }

        // Step 2: use the majority element to split nums
        int majorityElementPrefFreq = 0;
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] == majorityElement){
                majorityElementPrefFreq += 1;
            }
            if(majorityElementPrefFreq * 2 > i + 1 &&
               (majorityElementTotalFreq - majorityElementPrefFreq) * 2 > N - 1 - i){
                return i;
            }
        }

        return -1;
    }
};