class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int leftPartIdx = (N - 1) / 2;
        int rightPartIdx = N - 1;
        for(int i = 0; i < N; ++i){
            if(i % 2 == 0){
                nums[i] = sortedNums[leftPartIdx];
                leftPartIdx -= 1;
            }else{
                nums[i] = sortedNums[rightPartIdx];
                rightPartIdx -= 1;
            }
        }
    }
};