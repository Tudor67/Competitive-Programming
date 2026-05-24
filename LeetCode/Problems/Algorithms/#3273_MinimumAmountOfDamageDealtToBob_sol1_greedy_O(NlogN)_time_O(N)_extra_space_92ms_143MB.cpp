class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        const int N = damage.size();

        vector<int> t(N);
        for(int i = 0; i < N; ++i){
            t[i] = (health[i] + power - 1) / power;
        }

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (damage[lhs] * t[rhs] > damage[rhs] * t[lhs]);
             });

        long long res = 0;
        long long currDamageSum = accumulate(damage.begin(), damage.end(), (long long)0);
        for(int i: p){
            res += currDamageSum * t[i];
            currDamageSum -= damage[i];
        }

        return res;
    }
};