class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        const int N = arr.size();
        
        map<int, int> idxOf;
        vector<bool> isGoodOddStart(N, false);
        vector<bool> isGoodEvenStart(N, false);
        isGoodOddStart[N - 1] = true;
        isGoodEvenStart[N - 1] = true;
        idxOf[arr[N - 1]] = N - 1;
        
        for(int i = N - 2; i >= 0; --i){
            map<int, int>::iterator it = idxOf.lower_bound(arr[i]);
            if(it != idxOf.end()){
                isGoodOddStart[i] = isGoodEvenStart[it->second];
            }
            
            it = idxOf.upper_bound(arr[i]);
            if(it != idxOf.begin()){
                it = prev(it);
                isGoodEvenStart[i] = isGoodOddStart[it->second];
            }
            
            idxOf[arr[i]] = i;
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