class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        for(int i = N - 1; i >= 2; --i){
            int c = sortedNums[i];
            int b = sortedNums[i - 1];
            int a = sortedNums[i - 2];
            if(a + b > c){
                return a + b + c;
            }
        }
        
        return 0;
    }
};