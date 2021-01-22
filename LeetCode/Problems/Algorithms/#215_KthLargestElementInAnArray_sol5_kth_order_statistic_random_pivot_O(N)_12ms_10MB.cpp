class Solution {
private:
    void kthOrderStatistic(vector<int>& nums, const int& L, const int& K, const int& R){
        if(L >= R){
            return;
        }
        // Step 1: fix pivot
        int pivotIdx = L + rand() % (R - L + 1);
        int pivot = nums[pivotIdx];
        swap(nums[pivotIdx], nums[R]);
        // Step 2: partition nums[L .. R] in nums[L .. l] and nums[r .. R],
        //         where nums[i] <  pivot for each i in [L .. l] and
        //               nums[j] >= pivot for each j in [r .. R] and
        //               l + 1 == r
        int l = L;
        int r = R;
        while(l < r){
            if(nums[l] <= pivot){
                l += 1;
            }else{
                swap(nums[l], nums[r - 1]);
                r -= 1;
            }
        }
        swap(nums[r], nums[R]);
        pivotIdx = r;
        // Step 3: partition nums[L .. pivotIdx - 1] if K <= pivotIdx - 1
        //                or nums[pivotIdx + 1 .. R] if K >= pivotIdx + 1
        if(K <= pivotIdx - 1){
            kthOrderStatistic(nums, L, K, pivotIdx - 1);
        }else if(K >= pivotIdx + 1){
            kthOrderStatistic(nums, pivotIdx + 1, K, R);
        }
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int N = nums.size();
        srand(time(NULL));
        kthOrderStatistic(nums, 0, N - k, N - 1);
        return nums[N - k];
    }
};