class Solution {
private:
    bool isGreater(const string& A, const string& B, unordered_map<char, int>& indexOf){
        const int A_LEN = A.length();
        const int B_LEN = B.length();

        int i = 0;
        while(i < min(A_LEN, B_LEN) && indexOf[A[i]] == indexOf[B[i]]){
            i += 1;
        }

        return (i < min(A_LEN, B_LEN) && indexOf[A[i]] > indexOf[B[i]]) ||
               (i == min(A_LEN, B_LEN) && A_LEN > B_LEN);
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> indexOf;
        for(int i = 0; i < (int)order.length(); ++i){
            indexOf[order[i]] = i;
        }

        for(int i = 1; i < (int)words.size(); ++i){
            if(isGreater(words[i - 1], words[i], indexOf)){
                return false;
            }
        }

        return true;
    }
};