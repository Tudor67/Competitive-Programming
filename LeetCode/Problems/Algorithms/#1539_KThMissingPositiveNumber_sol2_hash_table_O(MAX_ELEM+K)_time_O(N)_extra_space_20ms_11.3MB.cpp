class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> visited;
        for(int elem: arr){
            visited.insert(elem);
        }
        
        const int MAX_POSSIBLE_ELEM = arr.back() + k;
        int answer = 0;
        for(int elem = 1; elem <= MAX_POSSIBLE_ELEM; ++elem){
            k -= !visited.count(elem);
            if(k == 0){
                answer = elem;
                break;
            }
        }
        
        return answer;
    }
};