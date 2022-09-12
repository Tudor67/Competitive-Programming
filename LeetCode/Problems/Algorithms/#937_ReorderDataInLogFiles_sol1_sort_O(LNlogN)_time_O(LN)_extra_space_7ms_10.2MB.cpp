class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        const int N = logs.size();
        
        vector<pair<string, string>> contentAndIdentifierOfLetterLogs;
        for(const string& LOG: logs){
            if(!isdigit(LOG.back())){
                int firstSpacePos = find(LOG.begin(), LOG.end(), ' ') - LOG.begin();
                string identifier = LOG.substr(0, firstSpacePos);
                string content = LOG.substr(firstSpacePos + 1);
                contentAndIdentifierOfLetterLogs.emplace_back(content, identifier);
            }
        }
        
        // 2. The letter-logs are sorted lexicographically by their contents.
        //    If their contents are the same, then sort them lexicographically by their identifiers.
        sort(contentAndIdentifierOfLetterLogs.begin(), contentAndIdentifierOfLetterLogs.end());
        
        vector<string> res;
        res.reserve(N);
        
        // 1. The letter-logs come before all digit-logs.
        for(int i = 0; i < (int)contentAndIdentifierOfLetterLogs.size(); ++i){
            res.push_back(contentAndIdentifierOfLetterLogs[i].second + " " + contentAndIdentifierOfLetterLogs[i].first);
        }
        
        // 3. The digit-logs maintain their relative ordering.
        for(const string& LOG: logs){
            if(isdigit(LOG.back())){
                res.push_back(LOG);
            }
        }
        
        return res;
    }
};