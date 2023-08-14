class Solution {
private:
    void quickSelect(vector<int>& v, const int L, const int K, const int R){
        if(L >= R){
            return;
        }

        int randIndex = L + rand() % (R - L + 1);
        swap(v[randIndex], v[R]);

        int pivot = v[R];
        int l = L;
        int r = R - 1;
        while(l <= r){
            if(v[l] < pivot){
                l += 1;
            }else{
                swap(v[l], v[r]);
                r -= 1;
            }
        }

        int pivotFirstIndex = l;
        int pivotLastIndex = l - 1;
        for(int i = l; i <= R; ++i){
            if(v[i] == pivot){
                swap(v[pivotLastIndex + 1], v[i]);
                pivotLastIndex += 1;
            }
        }

        // Partition:
        // v[L .. pivotFirstIndex - 1] < pivot
        // v[pivotFirstIndex .. pivotLastIndex] == pivot
        // v[pivotLastIndex + 1 .. R] > pivot

        if(pivotFirstIndex <= K && K <= pivotLastIndex){
            return;
        }else if(pivotLastIndex < K){
            quickSelect(v, pivotLastIndex + 1, K, R);
        }else if(K < pivotFirstIndex){
            quickSelect(v, L, K, pivotFirstIndex - 1);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> v = nums;
        srand(time(nullptr));
        quickSelect(v, 0, N - k, N - 1);

        return v[N - k];
    }
};