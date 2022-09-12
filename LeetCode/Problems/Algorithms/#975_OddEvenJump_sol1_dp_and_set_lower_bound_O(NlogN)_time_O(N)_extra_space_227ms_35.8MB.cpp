class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        const int N = arr.size();
        
        vector<bool> isGoodOddStart(N, false);
        vector<bool> isGoodEvenStart(N, false);
        isGoodOddStart[N - 1] = true;
        isGoodEvenStart[N - 1] = true;
        
        set<pair<int, int>> suffValuesAndPositiveIndices;
        suffValuesAndPositiveIndices.emplace(arr[N - 1], N - 1);
        set<pair<int, int>> suffValuesAndNegativeIndices;
        suffValuesAndNegativeIndices.emplace(arr[N - 1], -(N - 1));
        
        for(int i = N - 2; i >= 0; --i){
            set<pair<int, int>>::iterator it = suffValuesAndPositiveIndices.lower_bound({arr[i], i});
            if(it != suffValuesAndPositiveIndices.end()){
                isGoodOddStart[i] = isGoodEvenStart[it->second];
            }
            
            it = suffValuesAndNegativeIndices.upper_bound({arr[i], -i});
            if(it != suffValuesAndNegativeIndices.begin()){
                it = prev(it);
                isGoodEvenStart[i] = isGoodOddStart[-it->second];
            }
            
            suffValuesAndPositiveIndices.emplace(arr[i], i);
            suffValuesAndNegativeIndices.emplace(arr[i], -i);
        }
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            if(isGoodOddStart[i]){
                res += 1;
            }
        }
        
        return res;
    }
};