class Solution {
private:
    void appendInGivenOrderAndUpdateCount(string& s, const string& ORDER, unordered_map<char, int>& count){
        for(char c: ORDER){
            s.append(count[c], c);
            count[c] = 0;
        }
    }
    
public:
    string customSortString(string order, string str) {
        unordered_map<char, int> count;
        for(char c: str){
            count[c] += 1;
        }
        
        string strSorted;
        appendInGivenOrderAndUpdateCount(strSorted, order, count);
        appendInGivenOrderAndUpdateCount(strSorted, str, count);
        
        return strSorted;
    }
};