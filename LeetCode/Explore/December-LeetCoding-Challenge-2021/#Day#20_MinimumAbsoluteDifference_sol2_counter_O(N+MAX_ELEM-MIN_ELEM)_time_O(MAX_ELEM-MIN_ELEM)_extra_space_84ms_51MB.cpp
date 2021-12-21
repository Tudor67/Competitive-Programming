class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        const int N = arr.size();
        const int MIN_ELEM = *min_element(arr.begin(), arr.end());
        const int MAX_ELEM = *max_element(arr.begin(), arr.end());
        const int SHIFT = -MIN_ELEM;
        const int M = MAX_ELEM - MIN_ELEM + 1;
        const int INF = 1e8;
        
        vector<int> count(M + 1);
        for(int elem: arr){
            count[elem + SHIFT] += 1;
        }
        
        int minDiff = INF;
        int prevElem = INF;
        for(int elem = MIN_ELEM; elem <= MAX_ELEM; ++elem){
            if(count[elem + SHIFT] > 0){
                if(prevElem != INF){
                    minDiff = min(minDiff, elem - prevElem);
                }
                prevElem = elem;
            }
        }
        
        vector<vector<int>> minPairs;
        prevElem = INF;
        for(int elem = MIN_ELEM; elem <= MAX_ELEM; ++elem){
            if(count[elem + SHIFT] > 0){
                if(prevElem != INF && elem - prevElem == minDiff){
                    minPairs.push_back({prevElem, elem});
                }
                prevElem = elem;
            }
        }
        
        return minPairs;
    }
};