class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        const int MAX_POSSIBLE_ELEM = arr.back() + k;
        const unordered_set<int> VISITED(arr.begin(), arr.end());
        for(int elem = 1; elem <= MAX_POSSIBLE_ELEM; ++elem){
            k -= !VISITED.count(elem);
            if(k == 0){
                return elem;
            }
        }
        return -1;
    }
};