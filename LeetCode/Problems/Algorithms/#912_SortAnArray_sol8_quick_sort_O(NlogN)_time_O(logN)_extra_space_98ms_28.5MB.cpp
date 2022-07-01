class Solution {
private:
    int partition(vector<int>& v, const int& L, const int& R){
        if(L > R){
            return -1;
        }
        
        int randIdx = L + rand() % (R - L + 1);
        int pivot = v[randIdx];
        swap(v[randIdx], v[R]);
        
        int i = L;     // v[L .. i - 1] < pivot
        int j = R - 1; // pivot <= v[j + 1 .. R]
        while(i <= j){
            if(v[i] < pivot){
                i += 1;
            }else{
                swap(v[i], v[j]);
                j -= 1;
            }
        }
        
        swap(v[i], v[R]);
        int pivotIdx = i;
        
        return pivotIdx;
    }
    
    void quickSort(vector<int>& v, const int& L, const int& R){
        int pivotIdx = partition(v, L, R);
        if(L <= pivotIdx && pivotIdx <= R){
            quickSort(v, L, pivotIdx - 1);
            quickSort(v, pivotIdx + 1, R);
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        srand(time(NULL));
        quickSort(sortedNums, 0, N - 1);
        
        return sortedNums;
    }
};