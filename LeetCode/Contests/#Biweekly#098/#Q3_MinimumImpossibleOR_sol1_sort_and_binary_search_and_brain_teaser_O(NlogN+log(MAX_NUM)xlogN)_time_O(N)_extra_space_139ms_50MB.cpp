class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for(int p = 1; p <= 2 * sortedNums.back(); p *= 2){
            if(!binary_search(sortedNums.begin(), sortedNums.end(), p)){
                return p;
            }
        }

        return -1;
    }
};