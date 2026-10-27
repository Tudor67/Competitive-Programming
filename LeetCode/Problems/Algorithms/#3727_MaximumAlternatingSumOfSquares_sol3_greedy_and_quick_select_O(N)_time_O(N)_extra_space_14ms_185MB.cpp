class Solution {
private:
    void quickSelect(vector<int>& v, const int L, const int K, const int R){
        if(L >= R){
            return;
        }

        int pivot = v[L + rand() % (R - L + 1)];
        int lt = L - 1;
        int i = L;
        int gt = R + 1;
        while(i < gt){
            if(v[i] < pivot){
                lt += 1;
                swap(v[lt], v[i]);
                i += 1;
            }else if(v[i] > pivot){
                gt -= 1;
                swap(v[i], v[gt]);
            }else{
                i += 1;
            }
        }

        int firstPivotIndex = lt + 1;
        int lastPivotIndex = gt - 1;

        if(K < firstPivotIndex){
            quickSelect(v, L, K, firstPivotIndex - 1);
        }else if(lastPivotIndex < K){
            quickSelect(v, lastPivotIndex + 1, K, R);
        }
    }

public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int N = nums.size();

        vector<int> squaredNums(N);
        for(int i = 0; i < N; ++i){
            squaredNums[i] = nums[i] * nums[i];
        }

        srand(time(nullptr));
        quickSelect(squaredNums, 0, N / 2, N - 1);

        long long res = 0;
        for(int i = 0; i < N / 2; ++i){
            res -= squaredNums[i];
        }

        for(int i = N / 2; i < N; ++i){
            res += squaredNums[i];
        }

        return res;
    }
};