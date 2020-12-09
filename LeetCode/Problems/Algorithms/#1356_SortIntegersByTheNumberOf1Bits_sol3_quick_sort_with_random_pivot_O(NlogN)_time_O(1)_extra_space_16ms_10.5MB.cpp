class Solution {
private:
    static int popcount(int num){
        int count = 0;
        while(num != 0){
            count += 1;
            num &= num - 1;
        }
        return count;
    }
    
    static bool compByBits(const int& LHS, const int& RHS){
        int leftPopCount = popcount(LHS);
        int rightPopCount = popcount(RHS);
        return (leftPopCount < rightPopCount || (leftPopCount == rightPopCount && LHS < RHS));
    }
    
    void quickSortByBits(vector<int>& arr, int L, int R){
        if(L >= R){
            return;
        }
        
        int pivotIdx = L + rand() % (R - L + 1);
        int pivotVal = arr[pivotIdx];
        swap(arr[pivotIdx], arr[R]);
        
        int l = L;
        int r = R - 1;
        while(l <= r){
            if(compByBits(arr[l], pivotVal)){
                l += 1;
            }else{
                swap(arr[l], arr[r]);
                r -= 1;
            }
        }
        
        swap(arr[l], arr[R]);
        pivotIdx = l;
        
        quickSortByBits(arr, L, pivotIdx - 1);
        quickSortByBits(arr, pivotIdx + 1, R);
    }
    
    void quickSortByBits(vector<int>& arr){
        const int N = arr.size();
        quickSortByBits(arr, 0, N - 1);
    }
    
public:
    vector<int> sortByBits(vector<int>& arr) {
        quickSortByBits(arr);
        return arr;
    }
};