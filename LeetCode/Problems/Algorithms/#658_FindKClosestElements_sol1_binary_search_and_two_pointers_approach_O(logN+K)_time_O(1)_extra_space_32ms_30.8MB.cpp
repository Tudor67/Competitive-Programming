class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int N = arr.size();
        
        // Step 1: binary search the (lower_bound) position of x in arr
        int xPos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        xPos = min(N - 1, xPos);
        if(xPos - 1 >= 0 && xPos <= N - 1 && abs(arr[xPos - 1] - x) <= abs(arr[xPos] - x)){
            xPos -= 1;
        }

        // Step 2 (two pointers approach):
        //        expand [startPos, endPos] range including closest integers to x
        int startPos = xPos;
        int endPos = xPos;
        while(endPos - startPos + 1 < k){
            if(startPos == 0){
                endPos += 1;
            }else if(endPos == N - 1){
                startPos -= 1;
            }else if(abs(arr[startPos - 1] - x) <= abs(arr[endPos + 1] - x)){
                startPos -= 1;
            }else{
                endPos += 1;
            }
        }
        
        return vector<int>(arr.begin() + startPos, arr.begin() + endPos + 1);
    }
};