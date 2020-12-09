class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        const unordered_set<int> PRIMES = {2,3,5,7,11,13,17,19};
        int answer = 0;
        for(int num = L; num <= R; ++num){
            int setBitsCnt = __builtin_popcount(num);
            answer += (PRIMES.find(setBitsCnt) != PRIMES.end());
        }
        return answer;
    }
};