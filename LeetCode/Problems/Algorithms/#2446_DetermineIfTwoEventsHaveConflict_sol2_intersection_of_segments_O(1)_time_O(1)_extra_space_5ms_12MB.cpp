class Solution {
private:
    int elapsedTime(const string& T){
        return stoi(T.substr(0, 2)) * 60 + stoi(T.substr(3));
    }
    
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return max(elapsedTime(event1[0]), elapsedTime(event2[0])) <=
               min(elapsedTime(event1[1]), elapsedTime(event2[1]));
    }
};