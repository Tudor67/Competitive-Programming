class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        const int N = pref.size();

        vector<int> arr(N);
        arr[0] = pref[0];
        for(int i = 1; i < N; ++i){
            arr[i] = pref[i - 1] ^ pref[i];
        }

        return arr;
    }
};