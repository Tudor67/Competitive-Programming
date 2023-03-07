class Solution {
private:
    pair<int, int> partitionWithRandomPivot(vector<int>& nums, const int& L, const int& R){
        const int SIZE = R - L + 1;
        int randomIndex = L + (rand() % SIZE);
        swap(nums[randomIndex], nums[R]);

        int pivot = nums[R];
        int i = L;
        int p1 = R;
        int p2 = R;
        while(i < p1){
            if(nums[i] < pivot){
                i += 1;
            }else if(nums[i] == pivot){
                swap(nums[i], nums[p1 - 1]);
                p1 -= 1;
            }else{
                swap(nums[i], nums[p2]);
                p2 -= 1;
            }
        }

        // nums[L .. p1 - 1] < pivot
        // nums[p1 .. p2] == pivot
        // nums[p2 + 1 .. R] > pivot
        return {p1, p2};
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