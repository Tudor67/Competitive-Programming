class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int N = arr.size();
        
        vector<int> candidates;
        if(N <= 3){
            candidates = arr;
        }else{
            for(int i = N / 4; i < N; i += N / 4){
                if(arr[i - 1] == arr[i]){
                    candidates.push_back(arr[i]);
                }
            }
        }
        
        int answer = 0;
        for(int candidate: candidates){
            int l = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            int r = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin() - 1;
            if(r - l + 1 > N / 4){
                answer = candidate;
                break;
            }
        }
        
        return answer;
    }
};