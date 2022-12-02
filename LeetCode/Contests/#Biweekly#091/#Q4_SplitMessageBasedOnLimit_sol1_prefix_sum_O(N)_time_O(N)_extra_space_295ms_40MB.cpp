class Solution {
private:
    int countDigits(int num){
        int digits = 0;    
        while(num > 0){
            num /= 10;
            digits += 1;
        }
        return max(1, digits);
    }
    
public:
    vector<string> splitMessage(string message, int limit) {
        const int N = message.length();
        vector<int> prefCostOfIndices(N + 1);
        for(int i = 1; i <= N; ++i){
            prefCostOfIndices[i] = prefCostOfIndices[i - 1] + countDigits(i);
        }
        
        int totalParts = 0;
        for(int parts = 1; parts <= N; ++parts){
            int maxMessageLength = (parts * limit) -
                                   (parts * (1 + 1 + countDigits(parts) + 1) + prefCostOfIndices[parts]);
            if(maxMessageLength >= N){
                totalParts = parts;
                break;
            }
        }
        
        vector<string> res;
        int i = 0;
        for(int part = 1; part <= totalParts; ++part){
            int suffixLen = 1 + countDigits(part) + 1 + countDigits(totalParts) + 1;
            int messageSublen = limit - suffixLen;
            string s = message.substr(i, messageSublen) +
                       "<" + to_string(part) + "/" + to_string(totalParts) + ">";
            res.push_back(s);
            i += messageSublen;
        }
        
        return res;
    }
};