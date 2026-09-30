class Solution {
private:
    int getMaxUniqueNum(vector<int>& nums){
        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
        }

        int maxUniqueNum = -1;
        for(auto& [num, numFreq]: freq){
            if(numFreq == 1){
                maxUniqueNum = max(maxUniqueNum, num);
            }
        }

        return maxUniqueNum;
    }

    int selectMaxUniqueNum(vector<int>& nums, int num1, int num2){
        int num1Freq = count(nums.begin(), nums.end(), num1);
        int num2Freq = count(nums.begin(), nums.end(), num2);

        if(num1Freq == 1 && num2Freq == 1){
            return max(num1, num2);
        }

        if(num1Freq == 1){
            return num1;
        }

        if(num2Freq == 1){
            return num2;
        }

        return -1;
    }

public:
    int largestInteger(vector<int>& nums, int k) {
        const int N = nums.size();

        if(k == 1){
            return getMaxUniqueNum(nums);
        }

        if(k == N){
            return *max_element(nums.begin(), nums.end());
        }

        return selectMaxUniqueNum(nums, nums[0], nums[N - 1]);
    }
};