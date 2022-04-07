class Solution {
private:
    void computeCount(vector<int>& arr, int startPos, int endPos, vector<int>& count){
        for(int i = startPos; i <= endPos; ++i){
            count[arr[i]] += 1;
        }
    }
    
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int N = arr.size();
        const int MAX_VAL = *max_element(arr.begin(), arr.end());
        const int MODULO = 1e9 + 7;
        
        int tuples = 0;
        vector<int> count(MAX_VAL + 1);
        for(int i = 0; i < N; ++i){
            computeCount(arr, i + 1, N - 1, count);
            for(int j = i + 1; j < N; ++j){
                count[arr[j]] -= 1;
                if(0 <= target - arr[i] - arr[j] && target - arr[i] - arr[j] <= MAX_VAL){
                    tuples += count[target - arr[i] - arr[j]];
                    tuples %= MODULO;
                }
            }
        }
        
        return tuples;
    }
};