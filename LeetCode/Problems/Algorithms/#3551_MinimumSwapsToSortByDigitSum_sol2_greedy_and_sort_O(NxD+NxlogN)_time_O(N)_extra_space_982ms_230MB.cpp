class Solution {
private:
    static int computeDigitsSum(int num){
        int digitsSum = 0;
        while(num > 0){
            digitsSum += (num % 10);
            num /= 10;
        }
        return digitsSum;
    }

public:
    int minSwaps(vector<int>& nums) {
        const int N = nums.size();

        vector<pair<int, int>> target(N);
        for(int i = 0; i < N; ++i){
            target[i] = {computeDigitsSum(nums[i]), nums[i]};
        }

        sort(target.begin(), target.end());
        
        vector<int> currNums = nums;
        map<int, int> indexOf;
        for(int i = 0; i < N; ++i){
            indexOf[nums[i]] = i;
        }

        int minSwapOps = 0;
        for(int i = 0; i < N; ++i){
            int targetNum = target[i].second;
            if(currNums[i] != targetNum){
                int j = indexOf[targetNum];
                swap(currNums[i], currNums[j]);
                indexOf[currNums[i]] = i;
                indexOf[currNums[j]] = j;
                minSwapOps += 1;
            }
        }

        return minSwapOps;
    }
};