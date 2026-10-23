class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        // When processing nums[i]:
        // prevCount[rem]: number of subarrays with (subarrayProduct % k == rem) ending at index (i - 1)
        // currCount[rem]: number of subarrays with (subarrayProduct % k == rem) ending at index (i)
        // res[rem]: number of subarrays with (subarrayProduct % k == rem) ending at indices (0, 1, ..., i)
        vector<long long> prevCount(k);
        vector<long long> currCount(k);
        vector<long long> res(k);

        for(int num: nums){
            int numRem = num % k;

            fill(currCount.begin(), currCount.end(), 0);
            currCount[numRem] = 1;

            for(int prevRem = 0; prevRem < k; ++prevRem){
                currCount[prevRem * numRem % k] += prevCount[prevRem];
            }

            for(int rem = 0; rem < k; ++rem){
                res[rem] += currCount[rem];
            }

            copy(currCount.begin(), currCount.end(), prevCount.begin());
        }

        return res;
    }
};