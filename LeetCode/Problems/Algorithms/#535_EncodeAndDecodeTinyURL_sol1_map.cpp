class Solution {
private:
    map<string, string> URL2Code;
    map<string, string> code2URL;
    static const int CODE_SIZE = 8;
    static const int ALPHABET_SIZE = 26;
    static const char FIRST_CHAR = 'a';
    
    string getRandomCode(){
        string code(CODE_SIZE, '.');
        for(int i = 0; i < CODE_SIZE; ++i){
            code[i] = FIRST_CHAR + rand() % ALPHABET_SIZE;
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
        return "http://tinyurl.com/" + URL2Code[longURL];
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