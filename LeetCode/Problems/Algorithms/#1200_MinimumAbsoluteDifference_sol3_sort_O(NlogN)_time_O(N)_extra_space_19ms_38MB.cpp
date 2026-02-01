class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        const int N = arr.size();

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int minDiff = sortedArr[1] - sortedArr[0];
        for(int i = 1; i < N; ++i){
            minDiff = min(minDiff, sortedArr[i] - sortedArr[i - 1]);
        }

        vector<vector<int>> res;
        for(int i = 1; i < N; ++i){
            if(sortedArr[i] - sortedArr[i - 1] == minDiff){
                res.push_back({sortedArr[i - 1], sortedArr[i]});
            }
        }

        return res;
    }
};