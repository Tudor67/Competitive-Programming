class Solution {
private:
    void kth_element(vector<int>& nums, const int& L, const int& K, const int& R){
        if(L >= R){
            return;
        }
        
        int pivotIdx = L + rand() % (R - L + 1);
        int pivot = nums[pivotIdx];
        
        swap(nums[pivotIdx], nums[R]);
        
        int l = L;
        for(int r = L; r < R; ++r){
            if(nums[r] < pivot){
                swap(nums[l], nums[r]);
                l += 1;
            }
        }
        
        swap(nums[l], nums[R]);
        pivotIdx = l;
        
        if(pivotIdx < K && pivotIdx + 1 < R) kth_element(nums, pivotIdx + 1, K, R);
        if(K < pivotIdx && L < pivotIdx - 1) kth_element(nums, L, K, pivotIdx - 1);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int N = nums.size();
        k = N - k;
        
        srand(time(NULL));
        kth_element(nums, 0, k, N - 1);
        
        return nums[k];
    }
};