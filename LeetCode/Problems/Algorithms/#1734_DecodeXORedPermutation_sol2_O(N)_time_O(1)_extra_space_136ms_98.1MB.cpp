class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        const int N = 1 + (int)encoded.size();
        
        int pXOR = 0;
        for(int i = 1; i <= N; ++i){
            pXOR ^= i;
        }
        
        int oddEncodedXOR = 0;
        for(int i = 1; i < (int)encoded.size(); i += 2){
            oddEncodedXOR ^= encoded[i];
        }
        
        vector<int> p(N);
        p[0] = pXOR ^ oddEncodedXOR;
        for(int i = 1; i < N; ++i){
            p[i] = p[i - 1] ^ encoded[i - 1];
        }
        
        return p;
    }
};