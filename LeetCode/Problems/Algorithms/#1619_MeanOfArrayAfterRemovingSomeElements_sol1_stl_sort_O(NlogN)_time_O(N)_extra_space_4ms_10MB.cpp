class Solution {
public:
    double trimMean(vector<int>& arr) {
        const int N = arr.size();

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int extraElements = N / 20;
        double sum = 0;
        for(int i = extraElements; i < N - extraElements; ++i){
            sum += sortedArr[i];
        }

        return sum / (N - 2 * extraElements);
    }
};