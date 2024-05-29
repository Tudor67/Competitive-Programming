class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int i = 0;
        for(int x = 0; x <= N; ++x){
            while(i < N && sortedNums[i] < x){
                i += 1;
            }
            if(x == N - i){
                return x;
            }
        }

        return -1;
    }
};