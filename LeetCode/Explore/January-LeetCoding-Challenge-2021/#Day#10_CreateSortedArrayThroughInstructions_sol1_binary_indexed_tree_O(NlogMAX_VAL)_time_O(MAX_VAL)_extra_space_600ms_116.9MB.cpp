class BinaryIndexedTree{
private:
    const int N;
    vector<int> a;
    
public:
    BinaryIndexedTree(const int& N): N(N){
        a.resize(N + 1);
    }
    
    void add(int pos, int val){
        for(int i = pos; i <= N; i += i - (i & (i - 1))){
            a[i] += val;
        }
    }
    
    int query(int pos){
        int sum = 0;
        for(int i = pos; i >= 1; i = (i & (i - 1))){
            sum += a[i];
        }
        return sum;
    }
    
    int query(int startPos, int endPos){
        if(startPos > endPos){
            return 0;
        }
        if(startPos <= 1){
            return query(endPos);
        }
        return query(endPos) - query(startPos - 1);
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int MAX_VAL = *max_element(instructions.begin(), instructions.end());
        const int MODULO = 1e9 + 7;
        long long answer = 0;
        BinaryIndexedTree tree(MAX_VAL);
        for(int num: instructions){
            int l = tree.query(1, num - 1);
            int r = tree.query(num + 1, MAX_VAL);
            answer += min(l, r);
            answer %= MODULO;
            tree.add(num, 1);
        }
        return (int)answer;
    }
};