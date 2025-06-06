class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int N = s.length();
        const int ALPHABET_SIZE = 26;
        const int MODULO = 1'000'000'007;

        vector<int> contrib(ALPHABET_SIZE);
        vector<int> currFreq(ALPHABET_SIZE);
        vector<int> nextFreq(ALPHABET_SIZE);

        auto add = [&](int& a, int b) -> void {
            a = (a + b) % MODULO;
        };

        auto applyTransformation = [&]() -> void {
            fill(nextFreq.begin(), nextFreq.end(), 0);
            for(char c = 'b'; c <= 'z'; ++c){
                add(nextFreq[c - 'a'], currFreq[c - 'a' - 1]);
            }
            add(nextFreq['a' - 'a'], currFreq['z' - 'a']);
            add(nextFreq['b' - 'a'], currFreq['z' - 'a']);
            copy(nextFreq.begin(), nextFreq.end(), currFreq.begin());
        };

        currFreq['a' - 'a'] = 1;
        for(int step = 1; step <= t - 1; ++step){
            applyTransformation();
        }

        for(char startChar = 'a'; startChar <= 'z'; ++startChar){
            applyTransformation();
            for(char c = 'a'; c <= 'z'; ++c){
                add(contrib[startChar - 'a'], currFreq[c - 'a']);
            }
        }

        int res = 0;
        for(char c: s){
            add(res, contrib[c - 'a']);
        }

        return res;
    }
};