class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        const int N = arr.size();
        
        int answer = 0;
        int sum = 0;
        for(int i = 0; i < N; ++i){
            sum += arr[i];
            if(i >= k){
                sum -= arr[i - k];
            }
            if(i >= k - 1 && sum / k >= threshold){
                answer += 1;
            }
        }
        
        return answer;
    }
};