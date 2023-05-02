class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        int r = 0;
        for(int l = 0; l < N; ++l){
            r = max(r, l + 1);
            while(r < N && sortedNums[l] == sortedNums[r]){
                r += 1;
            }

            if(r < N){
                r += 1;
                res += 1;
            }
        }

        return res;
    }
};