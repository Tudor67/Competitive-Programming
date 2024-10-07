class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        const int N = arr.size();

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        sortedArr.resize(unique(sortedArr.begin(), sortedArr.end()) - sortedArr.begin());

        vector<int> rank(N);
        for(int i = 0; i < N; ++i){
            rank[i] = upper_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin();
        }

        return rank;
    }
};