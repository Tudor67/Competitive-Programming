class Solution {
private:
    pair<long long, long long> computeSumAndCountZeros(vector<int>& nums){
        long long sum = 0;
        long long zeros = 0;
        for(int num: nums){
            if(num == 0){
                zeros += 1;
            }else{
                sum += num;
            }
        }
        return {sum, zeros};
    }

public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        auto [sum1, zeros1] = computeSumAndCountZeros(nums1);
        auto [sum2, zeros2] = computeSumAndCountZeros(nums2);

        long long minValidSum = max(sum1 + zeros1, sum2 + zeros2);
        if((sum1 != minValidSum && zeros1 == 0) ||
           (sum2 != minValidSum && zeros2 == 0)){
            minValidSum = -1;
        }

        return minValidSum;
    }
};