class Solution {
private:
    const string ALPHABET = string("0123456789") +
                            string("abcdefghijklmnopqrstuvwxyz") +
                            string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    const int CODE_SIZE = 7;
    const string SHORT_URL_PREFIX = "http://tinyurl.com";
    unordered_map<string, string> URL2Code;
    unordered_map<string, string> code2URL;
    
    string getRandomCode(){
        string code(CODE_SIZE, '.');
        for(int i = 0; i < CODE_SIZE; ++i){
            code[i] = ALPHABET[rand() % ALPHABET.size()];
        }
        return code;
    }
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longURL) {
        if(!URL2Code.count(longURL)){
            string code;
            do{
                code = getRandomCode();
            }while(code2URL.count(code));
            URL2Code[longURL] = code;
            code2URL[code] = longURL;
        }
        return SHORT_URL_PREFIX + "/" + URL2Code[longURL];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortURL) {
        string code = shortURL.substr(shortURL.find_last_of('/') + 1);
        return code2URL[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));