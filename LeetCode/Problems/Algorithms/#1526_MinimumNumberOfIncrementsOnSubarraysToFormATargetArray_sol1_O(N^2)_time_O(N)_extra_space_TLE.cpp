class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<int> a = target;
        const int N = a.size();
        
        int answer = 0;
        int maxIdx = max_element(a.begin(), a.end()) - a.begin();
        while(a[maxIdx] != 0){
            answer += a[maxIdx];
            
            // range [maxIdx + 1, right]
            int limit = a[maxIdx];
            for(int i = maxIdx + 1; i < N && limit > 0; ++i){
                limit = min(a[i], limit);
                a[i] -= limit;
            }
            
            // range [left, maxIdx]
            limit = a[maxIdx];
            for(int i = maxIdx; i >= 0 && limit > 0; --i){
                limit = min(a[i], limit);
                a[i] -= limit;
            }
            
            maxIdx = max_element(a.begin(), a.end()) - a.begin();
        }
        
        return answer;
    }
};