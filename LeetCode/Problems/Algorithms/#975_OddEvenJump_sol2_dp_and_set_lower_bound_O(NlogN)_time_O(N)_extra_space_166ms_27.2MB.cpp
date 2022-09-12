class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        const int N = arr.size();
        
        vector<bool> isGoodOddStart(N, false);
        vector<bool> isGoodEvenStart(N, false);
        isGoodOddStart[N - 1] = true;
        isGoodEvenStart[N - 1] = true;
        
        set<pair<int, int>> suffValuesAndIndices;
        suffValuesAndIndices.emplace(arr[N - 1], N - 1);
        
        for(int i = N - 2; i >= 0; --i){
            set<pair<int, int>>::iterator it = suffValuesAndIndices.lower_bound({arr[i], i});
            if(it != suffValuesAndIndices.end()){
                isGoodOddStart[i] = isGoodEvenStart[it->second];
            }
            
            it = suffValuesAndIndices.upper_bound({arr[i], N});
            if(it != suffValuesAndIndices.begin()){
                it = prev(it);
                isGoodEvenStart[i] = isGoodOddStart[it->second];
            }
            
            it = suffValuesAndIndices.lower_bound({arr[i], i});
            if(it != suffValuesAndIndices.end() && it->first == arr[i]){
                suffValuesAndIndices.erase(it);
            }
            
            suffValuesAndIndices.emplace(arr[i], i);
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