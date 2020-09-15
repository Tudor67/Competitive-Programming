class Solution {
public:
    int compareVersion(string version1, string version2) {
        // split strings (with delim = '.') and change each component to integer
        stringstream ss1(version1);
        stringstream ss2(version2);
        vector<int> v1;
        vector<int> v2;
        string s;
        while(getline(ss1, s, '.')) v1.push_back(stoi(s));
        while(getline(ss2, s, '.')) v2.push_back(stoi(s));
        
        // append zeros to the end of the shortest vector
        const int MAX_SIZE = max(v1.size(), v2.size());
        v1.resize(MAX_SIZE, 0);
        v2.resize(MAX_SIZE, 0);
        
        // compare vectors
        return (v1 > v2) - (v1 < v2);
    }
};