class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        const int N = arr.size();
        
        if(N == 1){
            return 1;
        }
        
        vector<int> diffs(N);
        for(int i = 1; i < N; ++i){
            diffs[i] = arr[i] - arr[i - 1];
            if(diffs[i] < 0){
                diffs[i] = -1;
            }else if(diffs[i] > 0){
                diffs[i] = 1;
            }
        }
        
        diffs[0] = -diffs[1];
        
        int maxLength = 1;
        int length = 1;
        for(int i = 1; i < N; ++i){
            if(diffs[i - 1] * diffs[i] < 0){
                length += 1;
                maxLength = max(maxLength, length);
            }else{
                length = 2;
            }
        }
        
        return maxLength;
    }
};