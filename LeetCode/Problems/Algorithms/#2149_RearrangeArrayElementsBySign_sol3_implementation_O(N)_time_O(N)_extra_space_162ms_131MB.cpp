class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> positiveNums;
        vector<int> negativeNums;
        positiveNums.reserve(N / 2);
        negativeNums.reserve(N / 2);

        for(int num: nums){
            if(num < 0){
                negativeNums.push_back(num);
            }else{
                positiveNums.push_back(num);
            }
        }

        for(int i = N - 1; i >= 0; --i){
            if(i % 2 == 0){
                nums[i] = positiveNums.back();
                positiveNums.pop_back();
            }else{
                nums[i] = negativeNums.back();
                negativeNums.pop_back();
            }
        }

        return nums;
    }
};