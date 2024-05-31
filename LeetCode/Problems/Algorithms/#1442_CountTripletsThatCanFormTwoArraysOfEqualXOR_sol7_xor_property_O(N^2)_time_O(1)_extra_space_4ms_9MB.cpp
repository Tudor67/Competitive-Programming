class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int N = arr.size();

        int res = 0;
        for(int i = 0; i < N; ++i){
            int xorVal = arr[i];
            for(int j = i + 1; j < N; ++j){
                xorVal ^= arr[j];
                if(xorVal == 0){
                    res += j - i;
                }
            }
        }

        return res;
    }
};