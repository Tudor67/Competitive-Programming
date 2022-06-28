class Solution {
private:
    void partition(vector<int>& nums, const int& L, const int& K, const int& R){
        if(L >= R){
            return;
        }
        
        int randomIdx = L + rand() % (R - L + 1);
        int pivot = nums[randomIdx];
        swap(nums[randomIdx], nums[R]);
        
        int i = L;     // nums[0 .. i - 1] < pivot
        int j = R - 1; // pivot <= nums[j + 1 .. R]
        while(i <= j){
            if(nums[i] < pivot){
                i += 1;
            }else{
                swap(nums[i], nums[j]);
                j -= 1;
            }
        }
        
        int pivotIdx = i;
        swap(nums[pivotIdx], nums[R]);
        
        if(K == pivotIdx){
            return;
        }else if(K < pivotIdx){
            partition(nums, L, K, pivotIdx - 1);
        }else if(K > pivotIdx){
            partition(nums, pivotIdx + 1, K, R);
        }
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int N = nums.size();
        srand(time(NULL));
        partition(nums, 0, N - k, N - 1);
        return nums[N - k];
    }
};