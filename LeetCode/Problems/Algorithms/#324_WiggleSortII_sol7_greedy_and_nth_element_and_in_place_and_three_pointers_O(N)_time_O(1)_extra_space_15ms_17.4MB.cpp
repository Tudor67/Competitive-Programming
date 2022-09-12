class Solution {
private:
    int getIndex(int i, const int& N){
        if(2 * i + 1 < N){
            // odd indices
            return 2 * i + 1;
        }
        // even indices
        return 2 * i + 1 - N - ((N + 1) % 2);
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
        int leftPartSize = (N + 1) / 2;       // [elements less than median, possible elements equal to median]
        int rightPartSize = N - leftPartSize; // [median, possible elements equal to median, elements greater than median]
        
        int medianIdx = leftPartSize;
        nth_element(nums.begin(), nums.begin() + medianIdx, nums.end());
        int median = nums[medianIdx];
        
        // * at this point vector nums consists of two parts: [elements <= median, elements >= median]
        // * modify nums such that:
        //   - even indices (0, 2, 4, ..) contain: [elements == median, elements < median]
        //   - odd indices (1, 3, 5, ..) contain:  [elements > median, elements == median]
        // * in other words, the modified vector (formed by odd and even indices) should contain
        //   the following elements at their corresponding indices:
        //   indices:    1, 3, 5, 7, 9, 11, 13, 15, ......, 0, 2, 4, 6, 8, 10, 12, 14, ....
        //   elements:   [elements > median]   [elements == median]   [elements < median]
        // * the above vector looks like a sorted vector with 3 types of elements:
        //   - type A (elements > median)
        //   - type B (elements == median)
        //   - type C (elements < median)
        //   - type A > type B > type C
        // * we can use three pointers to sort (in one pass) a vector with 3 types of elements
        // * pay attention to the index mapping
        int l = 0;
        int r = N - 1;
        int i = 0;
        while(i <= r){
            if(nums[getIndex(i, N)] < median){
                swap(nums[getIndex(i, N)], nums[getIndex(r, N)]);
                r -= 1;
            }else if(nums[getIndex(i, N)] > median){
                swap(nums[getIndex(i, N)], nums[getIndex(l, N)]);
                l += 1;
                i += 1;
            }else{
                i += 1;
            }
        }
    }
};