class Solution {
private:
    int computeDistance(const string& A, const string& B){
        int dist = 0;
        for(int i = 0; i < (int)A.length(); ++i){
            if(A[i] != B[i]){
                dist += 1;
            }
        }
        return dist;
    }

public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        const int Q = queries.size();
        const int D = dictionary.size();

        vector<string> res;
        for(string& query: queries){
            for(string& dictWord: dictionary){
                if(computeDistance(query, dictWord) <= 2){
                    res.push_back(query);
                    break;
                }
            }
        }

        return res;
    }
};