class Solution {
private:
    bool match(const string& S, const string& P){
        const int N = S.length();
        const int M = P.length();
        
        const string PS = P + "$" + S;
        const int L = PS.length();
        
        static vector<int> p;
        p.assign(L, 0);
        for(int i = 1; i < L; ++i){
            int k = p[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = p[k - 1];
            }
            if(PS[k] == PS[i]){
                p[i] = k + 1;
            }
            if(p[i] == M){
                return true;
            }
        }
        
        return false;
    }
    
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string p;
        do{
            k += 1;
            p += word;
        }while(match(sequence, p));
        return k - 1;
    }
};