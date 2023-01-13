class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        const int N = arr.size();

        vector<int> count(N + 2);
        for(int elem: arr){
            count[min(elem, N + 1)] += 1;
        }

        int maxElem = 0;
        for(int elem = 1; elem <= N + 1; ++elem){
            while(count[elem] > 0 && maxElem + 1 <= elem){
                count[elem] -= 1;
                maxElem += 1;
            }
        }

        return maxElem;
    }
};