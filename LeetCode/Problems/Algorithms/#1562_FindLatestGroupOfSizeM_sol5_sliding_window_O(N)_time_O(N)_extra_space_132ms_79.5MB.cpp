class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        const int N = arr.size();
        
        vector<int> lastStepBeingZeroFor(N + 2);
        for(int i = 0; i < N; ++i){
            lastStepBeingZeroFor[arr[i]] = i;
        }
        
        lastStepBeingZeroFor[0] = N;
        lastStepBeingZeroFor[N + 1] = N + 1;
        
        int answer = -1;
        for(int l = 0, r = l + m + 1; r <= N + 1; r = l + m + 1){
            bool isValid = true;
            for(int j = l + 1; j <= r - 1; ++j){
                if(min(lastStepBeingZeroFor[l], lastStepBeingZeroFor[r]) < lastStepBeingZeroFor[j]){
                    isValid = false;
                    l = j;
                    break;
                }
            }
            if(isValid){
                answer = max(min(lastStepBeingZeroFor[l], lastStepBeingZeroFor[r]), answer);
                l = r;
            }
        }
        
        return answer;
    }
};