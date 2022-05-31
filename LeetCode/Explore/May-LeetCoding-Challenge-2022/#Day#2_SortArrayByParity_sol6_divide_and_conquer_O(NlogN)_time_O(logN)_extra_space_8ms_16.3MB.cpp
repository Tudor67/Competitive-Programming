class Solution {
private:
    void stable_partition(vector<int>& nums, const int& L, const int& R){
        if(L >= R){
            return;
        }
        
        int mid = (L + R) / 2;
        stable_partition(nums, L, mid);
        stable_partition(nums, mid + 1, R);
        
        int i = L;
        while(i <= mid && nums[i] % 2 == 0){
            i += 1;
        }
        
        int j = mid + 1;
        while(j + 1 <= R && nums[j + 1] % 2 == 0){
            j += 1;
        }
        
        reverse(nums.begin() + i, nums.begin() + mid + 1);
        reverse(nums.begin() + mid + 1, nums.begin() + j + 1);
        reverse(nums.begin() + i, nums.begin() + j + 1);
    }
    
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        const int N = nums.size();
        stable_partition(nums, 0, N - 1);
        return nums;
    }
};