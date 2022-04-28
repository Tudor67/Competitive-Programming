class Solution {
private:
    static const int MODULO = 1e9 + 7;
    static const int BASE = 131;
    const string SHORT_URL_PREFIX = "http://tinyurl.com/";
    unordered_map<string, int> stringToHash;
    unordered_map<int, string> hashToString;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longURL) {
        if(!stringToHash.count(longURL)){
            int hashVal = 0;
            for(char c: longURL){
                hashVal = (hashVal * 1LL * BASE + c) % MODULO;
            }
            
            while(hashToString.count(hashVal)){
                hashVal += 1;
                if(hashVal == MODULO){
                    hashVal = 0;
                }
            }
            
            hashToString[hashVal] = longURL;
            stringToHash[longURL] = hashVal;
        }
        return SHORT_URL_PREFIX + "/" + to_string(stringToHash[longURL]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortURL) {
        int hashVal = stoi(shortURL.substr(SHORT_URL_PREFIX.length() + 1));
        return hashToString[hashVal];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));