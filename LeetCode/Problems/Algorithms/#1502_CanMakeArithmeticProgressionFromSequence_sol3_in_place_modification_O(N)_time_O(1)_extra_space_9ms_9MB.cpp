class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        const int N = arr.size();

        // Step 1: compute minElem and maxElem
        int minElem = *min_element(arr.begin(), arr.end());
        int maxElem = *max_element(arr.begin(), arr.end());
        
        // Step 2: check special cases
        if(minElem == maxElem){
            return true;
        }

        if((maxElem - minElem) % (N - 1) != 0){
            return false;
        }

        // Step 3: fix the targetDiff and
        //         put each element in its correct position of the arithmetic progression (if possible)
        int targetDiff = (maxElem - minElem) / (N - 1);
        int i = 0;
        while(i < N){
            if(arr[i] == minElem + i * targetDiff){
                i += 1;
            }else{
                int j = (arr[i] - minElem) / targetDiff;
                if((arr[i] - minElem) % targetDiff != 0 || arr[i] == arr[j]){
                    return false;
                }else{
                    swap(arr[i], arr[j]);
                }
            }
        }

        return true;
    }
};