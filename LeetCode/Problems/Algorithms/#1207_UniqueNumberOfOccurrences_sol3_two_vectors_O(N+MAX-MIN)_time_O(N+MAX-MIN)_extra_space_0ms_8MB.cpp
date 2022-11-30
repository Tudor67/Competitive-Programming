class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        const int N = arr.size();
        const int MIN_ELEM = *min_element(arr.begin(), arr.end());
        const int MAX_ELEM = *max_element(arr.begin(), arr.end());
        const int SHIFT = -MIN_ELEM;
        
        vector<int> countOf(MAX_ELEM + SHIFT + 1);
        for(int elem: arr){
            countOf[elem + SHIFT] += 1;
        }
        
        vector<bool> vis(N + 1, false);
        for(int elem = MIN_ELEM; elem <= MAX_ELEM; ++elem){
            if(countOf[elem + SHIFT] >= 1){
                if(vis[countOf[elem + SHIFT]]){
                    return false;
                }
                vis[countOf[elem + SHIFT]] = true;
            }
        }
        
        return true;
    }
};