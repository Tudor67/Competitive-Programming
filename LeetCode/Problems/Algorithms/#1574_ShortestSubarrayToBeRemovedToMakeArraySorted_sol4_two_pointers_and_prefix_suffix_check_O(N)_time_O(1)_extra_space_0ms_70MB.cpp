class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int N = arr.size();

        int r = N - 1;
        while(0 <= r - 1 && arr[r - 1] <= arr[r]){
            r -= 1;
        }

        int minLenToRemove = r;
        for(int l = 0; l < N; ++l){
            if(l - 1 >= 0 && arr[l - 1] > arr[l]){
                break;
            }

            r = max(r, l + 1);
            while(r < N && arr[l] > arr[r]){
                r += 1;
            }

            minLenToRemove = min(minLenToRemove, N - (l + 1) - (N - r));
        }

        return minLenToRemove;
    }
};