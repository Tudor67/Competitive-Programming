class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        const int N = pref.size();

        for(int i = N - 1; i >= 1; --i){
            pref[i] = pref[i - 1] ^ pref[i];
        }

        return pref;
    }
};