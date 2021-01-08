class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        const int MAX_POSSIBLE_ELEM = arr.back() + k;
        
        vector<bool> vis(MAX_POSSIBLE_ELEM + 1, false);
        for(int elem: arr){
            vis[elem] = true;
        }
        
        int answer = 0;
        for(int elem = 1; elem <= MAX_POSSIBLE_ELEM; ++elem){
            k -= (!vis[elem]);
            if(k == 0){
                answer = elem;
                break;
            }
        }
        
        return answer;
    }
};