class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        const int N = arr.size();

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int j = 0;
        for(int i = 0; i < N; ++i){
            while(j < N && sortedArr[j] < 2 * sortedArr[i]){
                j += 1;
            }
            if(j < N && j != i && sortedArr[j] == 2 * sortedArr[i]){
                return true;
            }
        }

        return false;
    }
};