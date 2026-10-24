class Solution {
private:
    int computeDigitsSum(int num){
        int sum = 0;
        while(num > 0){
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    
public:
    int smallestIndex(vector<int>& nums) {
        const int N = nums.size();
        for(int i = 0; i < N; ++i){
            if(computeDigitsSum(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};