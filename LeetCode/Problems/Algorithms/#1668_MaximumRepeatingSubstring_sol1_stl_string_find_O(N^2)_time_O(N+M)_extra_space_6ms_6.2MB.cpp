class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string p;
        do{
            k += 1;
            p += word;
        }while(sequence.find(p) != string::npos);
        return k - 1;
    }
};