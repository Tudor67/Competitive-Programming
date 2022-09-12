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
        int i = 0;
        int idx = medianIdx - 1;
        while(i < idx){
            if(v[i] == median){
                swap(v[i], v[idx]);
                idx -= 1;
            }else{
                i += 1;
            }
        }
        
        // v[medianIdx .. N - 1]: [median, possible nums equal to median, nums greater than median]
        // make sure that nums equal to median are the first elements of v[medianIdx .. N - 1]
        i = N - 1;
        idx = medianIdx;
        while(idx < i){
            if(v[i] == median){
                swap(v[idx], v[i]);
                idx += 1;
            }else{
                i -= 1;
            }
        }
        
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