class Solution {
private:
    const string NUCLEOTIDES = "ACGT";
    
    int nucleotideToInt(char c){
        return NUCLEOTIDES.find(c);
    }
    
    char intToNucleotide(int num){
        return NUCLEOTIDES[num];
    }
    
    string intToDNASeq(int num){
        string seq(10, 'A');
        for(int i = 9; i >= 0; --i){
            seq[i] = NUCLEOTIDES[num % 4];
            num /= 4;
        }
        return seq;
    }
    
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int MSB = (1 << 18);
        vector<int> cnt((1 << 20), false);
        
        int w = 0;
        for(int i = 0; i < s.length(); ++i){
            if(i >= 10){
                w -= MSB * nucleotideToInt(s[i - 10]);
            }
            w = 4 * w + nucleotideToInt(s[i]);
            if(i >= 9){
                cnt[w] += 1;
            }
        }
        
        vector<string> answer;
        for(int w = 0; w < cnt.size(); ++w){
            if(cnt[w] >= 2){
                answer.push_back(intToDNASeq(w));
            }
        }
        
        return answer;
    }
};