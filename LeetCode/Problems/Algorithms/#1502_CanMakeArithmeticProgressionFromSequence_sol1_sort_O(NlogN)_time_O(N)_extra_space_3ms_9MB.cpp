class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        const int N = arr.size();

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        for(int i = 1; i < N; ++i){
            if(sortedArr[i] - sortedArr[i - 1] != sortedArr[1] - sortedArr[0]){
                return false;
            }
        }

        return true;
    }
};