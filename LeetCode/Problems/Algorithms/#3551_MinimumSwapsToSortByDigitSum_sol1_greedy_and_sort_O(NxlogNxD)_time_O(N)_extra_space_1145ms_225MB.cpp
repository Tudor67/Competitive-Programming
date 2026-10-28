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

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(),
             [](int lhs, int rhs){
                return (pair<int, int>{computeDigitsSum(lhs), lhs} <
                        pair<int, int>{computeDigitsSum(rhs), rhs});
             });
        
        vector<int> currNums = nums;
        map<int, int> indexOf;
        for(int i = 0; i < N; ++i){
            indexOf[nums[i]] = i;
        }

        int minSwapOps = 0;
        for(int i = 0; i < N; ++i){
            if(currNums[i] != sortedNums[i]){
                int j = indexOf[sortedNums[i]];
                swap(currNums[i], currNums[j]);
                swap(indexOf[currNums[i]], indexOf[currNums[j]]);
                minSwapOps += 1;
            }
        }

        return minSwapOps;
    }
};