class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

    void applyTransformation(vector<int>& currFreq, vector<int>& nextFreq, const int MODULO){
        fill(nextFreq.begin(), nextFreq.end(), 0);
        for(char c = 'b'; c <= 'z'; ++c){
            add(nextFreq[c - 'a'], currFreq[c - 'a' - 1], MODULO);
        }
        add(nextFreq['a' - 'a'], currFreq['z' - 'a'], MODULO);
        add(nextFreq['b' - 'a'], currFreq['z' - 'a'], MODULO);
        copy(nextFreq.begin(), nextFreq.end(), currFreq.begin());
    }

public:
    int lengthAfterTransformations(string s, int t) {
        const int N = s.length();
        const int ALPHABET_SIZE = 26;
        const int MODULO = 1'000'000'007;

        vector<int> contrib(ALPHABET_SIZE);
        vector<int> currFreq(ALPHABET_SIZE);
        vector<int> nextFreq(ALPHABET_SIZE);

        currFreq['a' - 'a'] = 1;
        for(int step = 1; step <= t - 1; ++step){
            applyTransformation(currFreq, nextFreq, MODULO);
        }

        for(char startChar = 'a'; startChar <= 'z'; ++startChar){
            applyTransformation(currFreq, nextFreq, MODULO);
            for(char c = 'a'; c <= 'z'; ++c){
                add(contrib[startChar - 'a'], currFreq[c - 'a'], MODULO);
            }
        }

        int res = 0;
        for(char c: s){
            add(res, contrib[c - 'a'], MODULO);
        }

        return res;
    }
};