class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        const int N = nums.size();

        long long majoritySubarrays = 0;

        vector<int> count(2 * N + 2);
        vector<int> acc(2 * N + 2);

        int prefBalance = N + 1;
        count[prefBalance] = 1;
        acc[prefBalance] = 1;

        for(int i = 0; i < N; ++i){
            if(nums[i] == target){
                prefBalance += 1;
            }else{
                prefBalance -= 1;
            }

            count[prefBalance] += 1;
            acc[prefBalance] = acc[prefBalance - 1] + count[prefBalance];

            majoritySubarrays += acc[prefBalance - 1];
        }

        return majoritySubarrays;
    }
};