class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int N = arr.size();
        const int INF = 1e9;
        
        // minLen[j]: min length of a subarray with (sum == target) that ends at position j
        vector<int> minLen(N, INF);
        int sum = 0;
        int i = 0;
        for(int j = 0; j < N; ++j){
            sum += arr[j];
            while(sum > target){
                sum -= arr[i];
                i += 1;
            }
            if(sum == target){
                minLen[j] = j - i + 1;
            }
        }
        
        // prefMinLen[j]: min(minLen[0], minLen[1], ..., minLen[j])
        vector<int> prefMinLen(N, INF);
        prefMinLen[0] = minLen[0];
        for(int i = 1; i < N; ++i){
            prefMinLen[i] = min(prefMinLen[i - 1], minLen[i]);
        }
        
        int answer = INF;
        for(int j = 1; j < N; ++j){
            if(minLen[j] != INF){
                int i = j - minLen[j];
                if(i >= 0 && prefMinLen[i] != INF){
                    answer = min(answer, prefMinLen[i] + minLen[j]);
                }
            }
        }
        
        if(answer == INF){
            answer = -1;
        }
        
        return answer;
    }
};