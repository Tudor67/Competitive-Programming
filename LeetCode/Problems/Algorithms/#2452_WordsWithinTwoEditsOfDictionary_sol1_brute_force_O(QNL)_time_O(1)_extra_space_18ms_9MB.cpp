class Solution {
private:
    int computeDistance(const string& S1, const string& S2){
        const int L = S1.length();
        int dist = 0;
        for(int i = 0; i < L; ++i){
            dist += (int)(S1[i] != S2[i]);
        }
        return dist;
    }
    
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        const int N = dictionary.size();
        const int Q = queries.size();
        
        vector<string> res;
        for(const string& S1: queries){
            for(const string& S2: dictionary){
                if(computeDistance(S1, S2) <= 2){
                    res.push_back(S1);
                    break;
                }
            }
        }
        
        return res;
    }
};