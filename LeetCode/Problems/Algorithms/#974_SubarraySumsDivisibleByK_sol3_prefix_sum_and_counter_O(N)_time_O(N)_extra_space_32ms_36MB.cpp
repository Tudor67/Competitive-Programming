class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        const int N = nums.size();

        int res = 0;
        int prefSum = 0;
        unordered_map<int, int> freq = {{0, 1}};

        for(int num: nums){
            prefSum = (prefSum + num % k + k) % k;
            res += freq[prefSum];
            freq[prefSum] += 1;
        }

        return res;
    }
};