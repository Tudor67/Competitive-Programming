class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        const int N = arr.size();

        if(count(arr.begin(), arr.end(), 0) >= 2){
            return true;
        }

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        for(int i = 0; i < N; ++i){
            if(sortedArr[i] != 0 && binary_search(sortedArr.begin(), sortedArr.end(), 2 * sortedArr[i])){
                return true;
            }
        }

        return false;
    }
};