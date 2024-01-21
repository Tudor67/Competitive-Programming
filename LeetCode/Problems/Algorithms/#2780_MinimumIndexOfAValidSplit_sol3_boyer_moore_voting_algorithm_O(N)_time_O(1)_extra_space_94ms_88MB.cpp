class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int N = nums.size();

        int candidate = nums[0];
        int candidateBal = 0;
        for(int num: nums){
            if(candidate == num){
                candidateBal += 1;
            }else{
                candidateBal -= 1;
            }
            if(candidateBal == -1){
                candidate = num;
                candidateBal = 1;
            }
        }

        int dominant = candidate;
        int dominantLeftFreq = 0;
        int dominantRightFreq = count(nums.begin(), nums.end(), dominant);

        for(int i = 0; i < N - 1; ++i){
            if(nums[i] == dominant){
                dominantLeftFreq += 1;
                dominantRightFreq -= 1;
            }
            int leftSize = i + 1;
            int rightSize = N - leftSize;
            if(dominantLeftFreq * 2 > leftSize && dominantRightFreq * 2 > rightSize){
                return i;
            }
        }

        return -1;
    }
};