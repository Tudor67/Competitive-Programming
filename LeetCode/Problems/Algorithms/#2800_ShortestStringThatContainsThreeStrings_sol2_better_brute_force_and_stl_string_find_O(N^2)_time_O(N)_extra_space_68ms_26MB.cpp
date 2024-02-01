class Solution {
public:
    string minimumString(string a, string b, string c) {
        string res = a + b + c;

        vector<string> v = {a, b, c};

        vector<int> p(3);
        iota(p.begin(), p.end(), 0);
        do{
            a = v[p[0]];
            b = v[p[1]];
            c = v[p[2]];

            // Step 1: initialize string s with string a
            //         if b is not a substring of s then:
            //            concatenate string s with the shortest suffix of b
            //            such that the resulting string s contains a suffix equal to b
            string s = a;
            if(s.find(b) == string::npos){
                for(int len = min(s.length(), b.length()); len >= 0; --len){
                    if(s.compare(s.length() - len, len, b, 0, len) == 0){
                        s += b.substr(len);
                        break;
                    }
                }
            }

            // Step 2: use string s from Step 1
            //         if c is not a substring of s then:
            //            concatenate it with the shortest suffix of c
            //            such that the resulting string s contains a suffix equal to c
            if(s.find(c) == string::npos){
                for(int len = min(s.length(), c.length()); len >= 0; --len){
                    if(s.compare(s.length() - len, len, c, 0, len) == 0){
                        s += c.substr(len);
                        break;
                    }
                }
            }

            // Step 3: update the result if s is lexicographically smaller than res
            if(s.size() < res.size() || (s.size() == res.size() && s < res)){
                res = s;
            }
        }while(next_permutation(p.begin(), p.end()));

        return res;
    }
};