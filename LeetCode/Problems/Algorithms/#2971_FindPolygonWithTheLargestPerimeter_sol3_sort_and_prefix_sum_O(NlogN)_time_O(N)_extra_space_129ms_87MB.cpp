class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long prefSum = accumulate(sortedNums.begin(), sortedNums.end(), (long long)0);
        for(int i = N - 1; i >= 2; --i){
            if(prefSum - sortedNums[i] > sortedNums[i]){
                return prefSum;
            }
            prefSum -= sortedNums[i];
        }

        return -1;
    }
};