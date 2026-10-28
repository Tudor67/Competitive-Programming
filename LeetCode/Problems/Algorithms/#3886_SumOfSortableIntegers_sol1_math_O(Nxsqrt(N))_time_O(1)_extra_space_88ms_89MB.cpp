class Solution {
private:
    bool isSortable(vector<int>& nums, int k){
        const int N = nums.size();

        if(N % k != 0){
            return false;
        }

        int prevMax = INT_MIN;
        for(int startIndex = 0; startIndex < N; startIndex += k){
            int decAdjNeighbors = (int)(nums[startIndex + k - 1] > nums[startIndex]);
            int currMin = nums[startIndex + k - 1];
            int currMax = nums[startIndex + k - 1];
            for(int i = startIndex; i + 1 < startIndex + k; ++i){
                decAdjNeighbors += (int)(nums[i] > nums[i + 1]);
                currMin = min(currMin, nums[i]);
                currMax = max(currMax, nums[i]);
            }

            if(decAdjNeighbors <= 1 && prevMax <= currMin){
                prevMax = currMax;
            }else{
                return false;
            }
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        for(int i = 1; i * i <= N; ++i){
            if(N % i == 0){
                if(isSortable(nums, i)){
                    res += i;
                }
                if(N / i != i && isSortable(nums, N / i)){
                    res += (N / i);
                }
            }
        }

        return res;
    }
};