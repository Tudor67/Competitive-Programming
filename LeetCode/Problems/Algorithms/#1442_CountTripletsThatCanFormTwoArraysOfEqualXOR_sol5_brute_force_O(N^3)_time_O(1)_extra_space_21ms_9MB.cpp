class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int N = arr.size();

        int res = 0;
        for(int i = 0; i < N; ++i){
            int a = 0;
            for(int j = i + 1; j < N; ++j){
                a ^= arr[j - 1];
                int b = 0;
                for(int k = j; k < N; ++k){
                    b ^= arr[k];
                    res += (int)(a == b);
                }
            }
        }

        return res;
    }
};