class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MODULO = 1e9 + 7;
        const int N = arr.size();
        const int MAX_ELEM = *max_element(arr.begin(), arr.end());
        
        int answer = 0;
        vector<int> countOfPairSum(2 * MAX_ELEM + 1, 0);
        for(int i = 2; i <= N - 1; ++i){
            for(int j = 0; j <= i - 2; ++j){
                countOfPairSum[arr[j] + arr[i - 1]] += 1;
            }
            if(0 <= target - arr[i] && target - arr[i] <= 2 * MAX_ELEM){
                answer += countOfPairSum[target - arr[i]];
                answer %= MODULO;
            }
        }
        
        return answer;
    }
};