class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        long long iMax = 0;
        long long ijMax = 0;

        for(int num: nums){
            res = max(res, ijMax * num);
            ijMax = max(ijMax, iMax - num);
            iMax = max(iMax, (long long)num);
        }

        return res;
    }
};