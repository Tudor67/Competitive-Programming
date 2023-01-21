class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        const int N = nums.size();

        int res = 0;
        int prefSum = 0;
        vector<int> count(k);
        count[0] = 1;
        for(int num: nums){
            prefSum = ((prefSum + num) % k + k) % k;
            res += count[prefSum];
            count[prefSum] += 1;
        }

        return res;
    }
};