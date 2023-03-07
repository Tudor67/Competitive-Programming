class Solution {
public:
    int findKthPositive(vector<int>& arr, int K) {
        const int N = arr.size();

        // Special Case
        if(K < arr[0]){
            return K;
        }

        // Binary Search
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(arr[mid] - (mid + 1) < K){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return arr[r] + K - (arr[r] - (r + 1));
    }
};