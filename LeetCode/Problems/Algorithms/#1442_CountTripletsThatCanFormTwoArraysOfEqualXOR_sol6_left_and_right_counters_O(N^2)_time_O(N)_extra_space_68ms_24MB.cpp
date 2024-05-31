class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int N = arr.size();

        int res = 0;
        unordered_map<int, int> leftFreq;
        unordered_map<int, int> rightFreq;

        for(int i = 0; i < N; ++i){
            int leftXOR = 0;
            leftFreq.clear();
            for(int l = i; l >= 0; --l){
                leftXOR ^= arr[l];
                leftFreq[leftXOR] += 1;
            }

            int rightXOR = 0;
            rightFreq.clear();
            for(int r = i + 1; r < N; ++r){
                rightXOR ^= arr[r];
                rightFreq[rightXOR] += 1;
            }

            for(const pair<const int, int>& P: leftFreq){
                int xorVal = P.first;
                if(rightFreq.count(xorVal)){
                    res += leftFreq[xorVal] * rightFreq[xorVal];
                }
            }
        }

        return res;
    }
};