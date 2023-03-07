class Solution {
private:
    pair<int, int> partitionWithRandomPivot(vector<int>& nums, const int& L, const int& R){
        const int SIZE = R - L + 1;
        int randomIndex = L + (rand() % SIZE);
        swap(nums[randomIndex], nums[R]);

        int pivot = nums[R];
        int l = L;
        int r = R - 1;
        while(l <= r){
            if(nums[l] < pivot){
                l += 1;
            }else{
                swap(nums[l], nums[r]);
                r -= 1;
            }
        }

        swap(nums[l], nums[R]);

        int pivotFirstIndex = l;
        int pivotLastIndex = l;
        for(int i = l + 1; i <= R; ++i){
            if(nums[i] == pivot){
                pivotLastIndex += 1;
                swap(nums[pivotLastIndex], nums[i]);
            }
        }

        // nums[L .. pivotFirstIndex - 1] < pivot
        // nums[pivotFirstIndex .. pivotLastIndex] == pivot
        // nums[pivotLastIndex + 1 .. R] > pivot
        return {pivotFirstIndex, pivotLastIndex};
    }

    void quickSort(vector<int>& nums, const int& L, const int& R){
        const int SIZE = R - L + 1;
        if(SIZE >= 2){
            pair<int, int> pivotIndices = partitionWithRandomPivot(nums, L, R);
            quickSort(nums, L, pivotIndices.first - 1);
            quickSort(nums, pivotIndices.second + 1, R);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        srand(time(nullptr));
        quickSort(nums, 0, N - 1);
        return nums;
    }
};