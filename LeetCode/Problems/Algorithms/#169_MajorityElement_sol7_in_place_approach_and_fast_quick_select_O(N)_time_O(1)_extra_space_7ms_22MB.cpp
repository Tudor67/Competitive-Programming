class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int N = nums.size();
        const int K = N / 2;

        srand(time(nullptr));

        int L = 0;
        int R = N - 1;
        while(L < R){
            int randIdx = L + rand() % (R - L + 1);
            swap(nums[randIdx], nums[R]);

            int pivot = nums[R];
            int i = L;
            int j = R - 1;
            while(i <= j){
                if(nums[i] < pivot){
                    i += 1;
                }else{
                    swap(nums[i], nums[j]);
                    j -= 1;
                }
            }

            swap(nums[i], nums[R]);
            int pivotFirstIdx = i;
            int pivotLastIdx = i;
            for(int idx = i + 1; idx <= R; ++idx){
                if(nums[idx] == pivot){
                    swap(nums[pivotLastIdx + 1], nums[idx]);
                    pivotLastIdx += 1;
                }
            }

            if(pivotFirstIdx <= K && K <= pivotLastIdx){
                L = K;
                R = K;
            }else if(pivotLastIdx < K){
                L = pivotLastIdx + 1;
            }else{
                R = pivotFirstIdx - 1;
            }
        }

        return nums[K];
    }
};