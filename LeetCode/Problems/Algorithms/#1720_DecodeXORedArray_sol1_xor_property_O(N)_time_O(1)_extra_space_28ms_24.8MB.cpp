class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        const int N = 1 + encoded.size();
        vector<int> arr(N);
        arr[0] = first;
        for(int i = 1; i < N; ++i){
            arr[i] = arr[i - 1] ^ encoded[i - 1];
        }
        return arr;
    }
};