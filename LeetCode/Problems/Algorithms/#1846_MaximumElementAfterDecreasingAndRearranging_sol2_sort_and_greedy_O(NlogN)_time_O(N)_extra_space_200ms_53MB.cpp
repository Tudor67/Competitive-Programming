class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        const int N = arr.size();

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int maxElem = 0;
        for(int elem: sortedArr){
            if(maxElem + 1 <= elem){
                maxElem += 1;
            }
        }

        return maxElem;
    }
};