class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int N = arr.size();
        
        int triplets = 0;
        for(int i = 0; i < N; ++i){
            int rangeXOR = arr[i];
            for(int k = i + 1; k < N; ++k){
                rangeXOR ^= arr[k];
                if(rangeXOR == 0){
                    triplets += k - i;
                }
            }
        }
        
        return triplets;
    }
};