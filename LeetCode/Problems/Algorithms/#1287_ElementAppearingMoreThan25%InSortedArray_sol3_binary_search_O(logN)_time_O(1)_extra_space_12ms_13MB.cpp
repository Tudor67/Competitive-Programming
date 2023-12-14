class Solution {
private:
    int lowerBoundIndex(vector<int>& arr, int target){
        const int N = arr.size();

        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(arr[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }

public:
    int findSpecialInteger(vector<int>& arr) {
        const int N = arr.size();

        for(int i = 0; i < N; i += max(1, N / 4)){
            int freq = lowerBoundIndex(arr, arr[i] + 1) -
                       lowerBoundIndex(arr, arr[i]);
            if(freq > N / 4){
                return arr[i];
            }
        }

        return -1;
    }
};