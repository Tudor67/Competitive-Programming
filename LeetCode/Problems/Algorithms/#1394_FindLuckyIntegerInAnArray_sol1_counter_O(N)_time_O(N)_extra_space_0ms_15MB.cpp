class Solution {
public:
    int findLucky(vector<int>& arr) {
        const int N = arr.size();

        vector<int> freqOf(N + 1);
        for(int elem: arr){
            if(elem <= N){
                freqOf[elem] += 1;
            }
        }

        for(int elem = N; elem >= 1; --elem){
            if(elem == freqOf[elem]){
                return elem;
            }
        }

        return -1;
    }
};