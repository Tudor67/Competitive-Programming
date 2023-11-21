class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        const int N = arr.size();

        vector<int> freq(N + 1);
        for(int elem: arr){
            freq[min(elem, N)] += 1;
        }

        int res = 0;
        for(int elem = 1; elem <= N; ++elem){
            while(freq[elem] >= 1){
                if(res + 1 <= elem){
                    res += 1;
                }
                freq[elem] -= 1;
            }
        }

        return res;
    }
};