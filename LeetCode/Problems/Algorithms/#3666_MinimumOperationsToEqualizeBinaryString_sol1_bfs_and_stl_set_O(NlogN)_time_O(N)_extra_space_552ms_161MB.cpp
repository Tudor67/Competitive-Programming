class Solution {
private:
    pair<int, int> computeIntersection(const pair<int, int>& A, const pair<int, int>& B){
        return {max(A.first, B.first), min(A.second, B.second)};
    }

public:
    int minOperations(string str, int k) {
        const int N = str.length();
        const int INITIAL_ONES = count(str.begin(), str.end(), '1');

        vector<set<int>> s(2);
        for(int i = 0; i <= N; ++i){
            s[i % 2].insert(i);
        }

        queue<int> q;
        q.push(INITIAL_ONES);
        s[INITIAL_ONES % 2].erase(INITIAL_ONES);

        int totalOps = 0;
        while(!q.empty()){
            for(int x = q.size(); x >= 1; --x){
                int ones = q.front(); q.pop();
                int zeros = N - ones;

                if(ones == N){
                    return totalOps;
                }

                pair<int, int> validRange = computeIntersection({k - min(k, zeros), k}, {0, min(k, ones)});
                int l = ones + k - 2 * validRange.second;
                int r = ones + k - 2 * validRange.first;
                int parity = (ones + k) % 2;

                auto it = s[parity].lower_bound(l);
                while(it != s[parity].end() && *it <= r){
                    q.push(*it);
                    it = s[parity].erase(it);
                }
            }
            totalOps += 1;
        }

        return -1;
    }
};