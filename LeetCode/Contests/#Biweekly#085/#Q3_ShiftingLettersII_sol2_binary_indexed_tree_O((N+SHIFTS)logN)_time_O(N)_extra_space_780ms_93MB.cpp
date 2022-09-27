class BinaryIndexedTree{
private:
    const int N;
    vector<int> tree;
    
    static int nonZeroLSB(int x){
        return x - (x & (x - 1));
    }
    
public:
    BinaryIndexedTree(const int& N): N(N){
        tree.resize(N + 1);
    }
    
    void add(int pos, int val){
        for(int i = pos; i <= N; i += nonZeroLSB(i)){
            tree[i] += val;
        }
    }
    
    int query(int pos){
        int sum = 0;
        for(int i = pos; i >= 1; i -= nonZeroLSB(i)){
            sum += tree[i];
        }
        return sum;
    }
};

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int N = s.length();
        const int A = 26;
        
        BinaryIndexedTree tree(N + 1);
        for(const vector<int>& SHIFT: shifts){
            int l = SHIFT[0];
            int r = SHIFT[1];
            int dir = (SHIFT[2] == 0 ? -1 : 1);
            tree.add(l + 1, dir);
            tree.add(r + 2, -dir);
        }
        
        for(int i = 0; i < N; ++i){
            int shift = ((tree.query(i + 1) % A) + A) % A;
            if(s[i] + shift > 'z'){
                s[i] = 'a' + (s[i] + shift - 'z' - 1);
            }else{
                s[i] = s[i] + shift;
            }
        }
        
        return s;
    }
};