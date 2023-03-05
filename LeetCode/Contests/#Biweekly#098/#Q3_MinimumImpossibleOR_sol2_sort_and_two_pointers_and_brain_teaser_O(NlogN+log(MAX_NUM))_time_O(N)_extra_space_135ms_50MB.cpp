class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int i = 0;
        for(int p = 1; p <= 2 * sortedNums.back(); p *= 2){
            while(i < N && sortedNums[i] < p){
                i += 1;
            }
            if(i == N || sortedNums[i] != p){
                return p;
            }
        }

        return -1;
    }
};