class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int N = arr.size();
        const int INF = 1e9;

        // minLen[i]: min length of the target-sum subarray starting exactly at index i,
        //            or INF if none exists
        // suffMinLen[i] = min(minLen[i], minLen[i + 1], ..., minLen[N - 1])
        vector<int> minLen(N + 1, INF);
        vector<int> suffMinLen(N + 1, INF);

        int wSum = 0;
        for(int i = N - 1, j = N - 1; i >= 0; --i){
            wSum += arr[i];
            while(i <= j && wSum > target){
                wSum -= arr[j];
                j -= 1;
            }

            if(wSum == target){
                minLen[i] = j - i + 1;
            }

            suffMinLen[i] = min(minLen[i], suffMinLen[i + 1]);
        }

        int res = INF;
        for(int i = N - 1; i >= 0; --i){
            if(minLen[i] != INF){
                res = min(res, minLen[i] + suffMinLen[i + minLen[i]]);
            }
        }

        if(res != INF){
            return res;
        }

        return -1;
    }
};