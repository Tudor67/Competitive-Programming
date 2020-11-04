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
        int r = R - 1;
        while(l < r){
            if(nums[l] >= pivot){
                swap(nums[l], nums[r]);
                r -= 1;
            }else{
                l += 1;
            }
        }
        
        if(nums[r] < pivot){
            r += 1;
        }else{
            l -= 1;
        }
        
        swap(nums[r], nums[R]);
        
        if(r < K && r + 1 < R) kth_element(nums, r + 1, K, R);
        if(K < r && L < r - 1) kth_element(nums, L, K, r - 1);
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