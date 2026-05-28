class Solution {
private:
    int binarySearchIndexOfMin(vector<int>& nums){
        const int N = nums.size();
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] > nums.back()){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

    int binarySearchInCircularArray(vector<int>& nums, int indexOfMin, int target){
        const int N = nums.size();
        int l = indexOfMin;
        int r = indexOfMin + N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid % N] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if(nums[r % N] == target){
            return (r % N);
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int indexOfMin = binarySearchIndexOfMin(nums);
        return binarySearchInCircularArray(nums, indexOfMin, target);
    }
};