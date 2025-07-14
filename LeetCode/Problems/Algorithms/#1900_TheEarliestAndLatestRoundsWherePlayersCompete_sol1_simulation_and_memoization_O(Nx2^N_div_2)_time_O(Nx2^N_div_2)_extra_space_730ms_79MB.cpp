class Solution {
private:
    int vec2bitmask(vector<int>& v){
        int mask = 0;
        for(int elem: v){
            mask |= (1 << elem);
        }
        return mask;
    }
    
    int solve(vector<int>& p, int firstPlayer, int secondPlayer,
              function<int(int, int)> f, int defaultElem, unordered_map<int, int>& memo){
        const int N = p.size();

        for(int i = 0, j = N - 1; i < j; ++i, --j){
            if(p[i] == firstPlayer && p[j] == secondPlayer){
                return 1;
            }
        }

        int state = vec2bitmask(p);
        if(memo.count(state)){
            return memo[state];
        }

        int res = defaultElem;
        vector<int> nextPlayers;
        for(int mask = (1 << (N / 2)) - 1; mask >= 0; --mask){
            nextPlayers.clear();
            for(int bit = 0; bit < N / 2; ++bit){
                if((mask >> bit) & 1){
                    nextPlayers.push_back(p[bit]);
                }
            }

            if(N % 2 == 1){
                nextPlayers.push_back(p[N / 2]);
            }

            for(int bit = N / 2 - 1; bit >= 0; --bit){
                if(((mask >> bit) & 1) == 0){
                    nextPlayers.push_back(p[N - 1 - bit]);
                }
            }

            if(find(nextPlayers.begin(), nextPlayers.end(), firstPlayer) != nextPlayers.end() &&
               find(nextPlayers.begin(), nextPlayers.end(), secondPlayer) != nextPlayers.end()){
                res = f(res, 1 + solve(nextPlayers, firstPlayer, secondPlayer, f, defaultElem, memo));
            }
        }

        memo[state] = res;
        return res;
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);

        unordered_map<int, int> minMemo;
        unordered_map<int, int> maxMemo;
        return {solve(p, firstPlayer, secondPlayer, [](int a, int b){ return min(a, b); }, n, minMemo),
                solve(p, firstPlayer, secondPlayer, [](int a, int b){ return max(a, b); }, 0, maxMemo)};
    }
};