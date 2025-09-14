class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MODULO = 1'000'000'007;

        vector<int> delta(n + 2);
        add(delta[1], 1, MODULO);
        add(delta[min(1 + forget, n + 1)], MODULO - 1, MODULO);

        for(int i = 1; i <= n; ++i){
            add(delta[i], delta[i - 1], MODULO);
            add(delta[min(i + delay, n + 1)], delta[i], MODULO);
            add(delta[min(i + forget, n + 1)], MODULO - delta[i], MODULO);
        }

        return delta[n];
    }
};