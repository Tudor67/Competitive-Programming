class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int N = arr.size();
        const int MAX_VAL = *max_element(arr.begin(), arr.end());
        const int MODULO = 1e9 + 7;
        
        int tuples = 0;
        vector<int> sumCount(2 * MAX_VAL + 1);
        for(int i = 1; i < N; ++i){
            if(0 <= target - arr[i] && target - arr[i] <= 2 * MAX_VAL){
                tuples += sumCount[target - arr[i]];
                tuples %= MODULO;
            }
            for(int j = 0; j < i; ++j){
                sumCount[arr[j] + arr[i]] += 1;
            }
        }
        
        return tuples;
    }
};