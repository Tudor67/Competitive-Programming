class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> h = arr;

        auto comp = [](int lhs, int rhs) {
            return pair<int, int>{popcount((unsigned int)lhs), lhs} <
                   pair<int, int>{popcount((unsigned int)rhs), rhs};
        };
        make_heap(h.begin(), h.end(), comp);
        sort_heap(h.begin(), h.end(), comp);

        return h;
    }
};