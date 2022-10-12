class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int N = names.size();
        
        map<int, int> indexOf;
        for(int i = 0; i < N; ++i){
            indexOf[heights[i]] = i;
        }
        
        vector<string> res;
        res.reserve(N);
        for(map<int, int>::reverse_iterator it = indexOf.rbegin(); it != indexOf.rend(); ++it){
            int index = it->second;
            res.push_back(names[index]);
        }
        
        return res;
    }
};