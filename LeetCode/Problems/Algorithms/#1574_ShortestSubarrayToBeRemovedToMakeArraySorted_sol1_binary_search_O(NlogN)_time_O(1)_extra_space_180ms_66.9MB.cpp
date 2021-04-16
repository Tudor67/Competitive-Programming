class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int N = arr.size();
        
        // Step 1: fix arr[0 .. l], where arr[0] <= arr[1] <= arr[2] <= ... <= arr[l]
        int l = 0;
        while(l + 1 < N && arr[l] <= arr[l + 1]){
            l += 1;
        }
        
        // Step 2: fix arr[r .. N - 1], where arr[r] <= arr[r + 1] <= arr[r + 2] <= ... <= arr[N - 1]
        int r = N - 1;
        while(l < r - 1 && arr[r - 1] <= arr[r]){
            r -= 1;
        }
        
        int answer = N - 1;
        if(l == N - 1){
            // Step 3 (special case): non-decreasing array
            answer = 0;
        }else{
            // Step 4: for each element arr[i] in arr[0 .. l]:
            //             compute the cost of keeping arr[i] and merging arr[0 .. i] with the longest arr[k .. N - 1], r <= k
            //             such that arr[0 .. i] concatenated with arr[k .. N - 1] is non-decreasing
            //             update the answer 
            for(int i = l; i >= 0; --i){
                int keepCost = lower_bound(arr.begin() + r, arr.end(), arr[i]) - arr.begin() - i - 1;
                answer = min(keepCost, answer);
            }
            
            // Step 4' (special case): check the cost of removing arr[0 .. r - 1] and keeping arr[r .. N - 1]
            answer = min(r, answer);
        }
        
        return answer;
    }
};