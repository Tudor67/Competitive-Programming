class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        const int N = arr.size();

        vector<int> h = arr;

        auto comp = [](int lhs, int rhs) {
            return pair<int, int>{popcount((unsigned int)lhs), lhs} <
                   pair<int, int>{popcount((unsigned int)rhs), rhs};
        };
        make_heap(h.begin(), h.end(), comp);

        for(int i = 0; i < N - 1; ++i){
            pop_heap(h.begin(), h.end() - i, comp);
        }

        return h;
    }
};