class Solution {
private:
    const int INF = 1e9;
    using State = int;
    
    bool solve(int len, int sides, int visMask, vector<int>& matchsticks, const int& N, const int& TARGET_LENGTH, vector<int>& memo){
        State state = visMask;
        bool isPossible = false;
        if(memo[state] != INF){
            isPossible = memo[state];
        }else if(len < 0){
            isPossible = false;
        }else if(len == 0){
            if(sides == 2){
                isPossible = true;
            }else{
                isPossible = solve(TARGET_LENGTH, sides - 1, visMask, matchsticks, N, TARGET_LENGTH, memo);
            }
        }else{
            for(int bit = 0; !isPossible && bit < N; ++bit){
                if(!((visMask >> bit) & 1)){
                    isPossible |= solve(len - matchsticks[bit], sides, visMask | (1 << bit), matchsticks, N, TARGET_LENGTH, memo);
                }
            }
        }
        memo[state] = isPossible;
        return isPossible;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        const int N = matchsticks.size();
        const int FULL_MASK = (1 << N) - 1;
        const long long TOTAL_LENGTH = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        const long long MAX_LENGTH = *max_element(matchsticks.begin(), matchsticks.end());
        const long long TARGET_LENGTH = TOTAL_LENGTH / 4;
        
        if(TOTAL_LENGTH % 4 == 0 && MAX_LENGTH <= TARGET_LENGTH){
            vector<int> memo(FULL_MASK + 1, INF);
            return solve(TARGET_LENGTH, 4, 0, matchsticks, N, TARGET_LENGTH, memo);
        }
        
        return false;
    }
};