class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int N = nums.size();
        
        if(N <= 1){
            return;
        }
        
        int leftPartSize = (N + 1) / 2;       // [nums less than median, possible nums equal to median]
        int rightPartSize = N - leftPartSize; // [median, possible nums equal to median, nums greater than median]
        
        vector<int> v = nums;
        int medianIdx = leftPartSize;
        nth_element(v.begin(), v.begin() + medianIdx, v.end());
        int median = v[medianIdx];
        
        // v[0 .. medianIdx - 1]: [nums less than median, possible nums equal to median]
        // make sure that nums equal to median are the last elements of v[0 .. medianIdx - 1]
        int leftPartMedianCount = count(v.begin(), v.begin() + leftPartSize, median);
        if(leftPartMedianCount >= 1){
            nth_element(v.begin(), v.begin() + leftPartSize - leftPartMedianCount, v.begin() + leftPartSize);
        }
        
        // v[medianIdx .. N - 1]: [median, possible nums equal to median, nums greater than median]
        // make sure that nums equal to median are the first elements of v[medianIdx .. N - 1]
        int rightPartMedianCount = count(v.begin() + medianIdx, v.end(), median);
        nth_element(v.begin() + medianIdx, v.begin() + medianIdx + rightPartMedianCount - 1, v.end());
        
        int leftPartIdx = (N - 1) / 2;
        int rightPartIdx = N - 1;
        for(int i = 0; i < N; ++i){
            if(i % 2 == 0){
                nums[i] = v[leftPartIdx];
                leftPartIdx -= 1;
            }else{
                nums[i] = v[rightPartIdx];
                rightPartIdx -= 1;
            }
        }
    }
};