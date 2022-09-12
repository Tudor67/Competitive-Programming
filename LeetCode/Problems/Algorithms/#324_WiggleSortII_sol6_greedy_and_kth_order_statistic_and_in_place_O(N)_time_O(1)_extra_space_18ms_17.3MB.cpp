class Solution {
private:
    void kthOrderStatistic(vector<int>& v, int l, int k, int r){
        while(l < r){
            int randomIdx = l + rand() % (r - l + 1);
            swap(v[randomIdx], v[r]);
            int pivot = v[r];
            
            int i = l; // v[l .. i] < pivot
            int j = r; // pivot <= v[j .. r]
            while(i < j){
                if(v[i] < pivot){
                    i += 1;
                }else{
                    j -= 1;
                    swap(v[i], v[j]);
                }
            }
            
            swap(v[j], v[r]);
            int pivotIdx = j;
            int pivotCount = count(v.begin() + l, v.begin() + r + 1, pivot);
            
            if(pivotIdx == k || pivotCount == r - l + 1){
                l = k;
                r = k;
            }else if(pivotIdx < k){
                l = pivotIdx + 1;
            }else if(k < pivotIdx){
                r = pivotIdx - 1;
            }
        }
    }
    
public:
    void wiggleSort(vector<int>& nums) {
        const int N = nums.size();
        
        if(N <= 1){
            return;
        }
        
        // * use nth_element to split the initial vector nums into two parts:
        //   - leftPart with elements <= median
        //   - rightPart with elements >= median
        int leftPartSize = (N + 1) / 2;       // [nums less than median, possible nums equal to median]
        int rightPartSize = N - leftPartSize; // [median, possible nums equal to median, nums greater than median]
        
        int medianIdx = leftPartSize;
        srand(time(NULL));
        kthOrderStatistic(nums, 0, medianIdx, N - 1);
        int median = nums[medianIdx];
        
        // * put nums from leftPart (i.e., nums[0 .. leftPartSize - 1]) on even indices 0, 2, 4, ..., 2 * (leftPartSize - 1)
        // * do this operation by moving backward (from right to left)
        // * after this step we have:
        //   - on even indices (0, 2, 4, ..): elements <= median
        //   - on odd indices (1, 3, 5, ..):  elements >= median
        for(int i = leftPartSize - 1; i >= 0; --i){
            swap(nums[i], nums[2 * i]);
        }
        
        // * To avoid equal neighbors in the final vector:
        //   1.) make sure that elements == median are the first elements on even indices
        int i = 0;
        int j = 0;
        while(j < N){
            if(nums[j] == median){
                swap(nums[i], nums[j]);
                i += 2;
            }
            j += 2;
        }
        
        // * To avoid equal neighbors in the final vector:
        //   2.) make sure that elements == median are the last elements on odd indices
        if(N % 2 == 0){
            i = N - 1;
            j = N - 1;
        }else{
            i = N - 2;
            j = N - 2;
        }
        while(i >= 0){
            if(nums[i] == median){
                swap(nums[i], nums[j]);
                j -= 2;
            }
            i -= 2;
        }
    }
};