class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        const int N = gain.size();
        partial_sum(gain.begin(), gain.end(), gain.begin());
        return max(0, *max_element(gain.begin(), gain.end()));
    }
};