class BinaryIndexedTree {
private:
    const int N;
    const int INIT_VAL;
    vector<int> tree;

    static int nonZeroLSB(int x){
        return x - (x & (x - 1));
    }

public:
    BinaryIndexedTree(const int N, const int INIT_VAL): N(N), INIT_VAL(INIT_VAL){
        tree.assign(N, INIT_VAL);
    }

    void maximize(int pos, int val){
        for(int i = pos; i < N; i += nonZeroLSB(i)){
            tree[i] = max(tree[i], val);
        }
    }

    int computePrefMax(int pos){
        int prefMax = INIT_VAL;
        for(int i = pos; i >= 1; i -= nonZeroLSB(i)){
            prefMax = max(prefMax, tree[i]);
        }
        return prefMax;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;

        vector<long long> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        vector<long long> sortedValues(2 * N + 1);
        for(int i = 0; i < N; ++i){
            sortedValues[i] = prefSum[i];
            sortedValues[i + N] = prefSum[i] - k;
        }
        sortedValues[2 * N] = 0;
        
        sort(sortedValues.begin(), sortedValues.end());
        sortedValues.resize(unique(sortedValues.begin(), sortedValues.end()) - sortedValues.begin());

        auto compress = [&](long long val) {
            return lower_bound(sortedValues.begin(), sortedValues.end(), val) - sortedValues.begin() + 1;
        };

        const int MAX_COMPRESSED_INDEX = compress(sortedValues.back());
        BinaryIndexedTree tree(MAX_COMPRESSED_INDEX + 1, -INF);
        tree.maximize(compress(0), -1);

        int minLen = INF;
        for(int i = 0; i < N; ++i){
            int len = i - tree.computePrefMax(compress(prefSum[i] - k));
            minLen = min(minLen, len);
            tree.maximize(compress(prefSum[i]), i);
        }

        if(minLen == INF){
            minLen = -1;
        }

        return minLen;
    }
};