class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        const int N = 1 + (int)encoded.size();
        
        int pXOR = 0;
        for(int i = 1; i <= N; ++i){
            pXOR ^= i;
        }
        
        int encodedXOR = 0;
        for(int i = 0; i < (int)encoded.size(); ++i){
            encodedXOR ^= encoded[i];
        }
        
        for(int i = 0; i < N / 2; ++i){
            pXOR ^= encodedXOR;
            encodedXOR ^= encoded[i] ^ encoded[N - 2 - i];
        }
        
        vector<int> p(N);
        p[N / 2] = pXOR;
        for(int i = N / 2 + 1; i < N; ++i){
            p[i] = p[i - 1] ^ encoded[i - 1];
        }
        
        for(int i = N / 2 - 1; i >= 0; --i){
            p[i] = p[i + 1] ^ encoded[i];
        }
        
        return p;
    }
};