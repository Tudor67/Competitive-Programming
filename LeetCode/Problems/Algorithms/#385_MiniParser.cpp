/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    NestedInteger deserialize(const string& s, int& p1){
        NestedInteger obj;
        for(int p2 = p1 + (s[p1] == '['); p2 < s.length(); p2 = max(p1, p2 + 1)){
            if(!isdigit(s[p2]) && s[p2] != '-'){
                int start_pos = p1 + (s[p1] == '[');
                int len = p2 - start_pos;
                if(len > 0){
                    int num = stoi(s.substr(start_pos, len));
                    obj.add(num);
                }
                p1 = p2 + 1;
                if(s[p2] == '['){
                    p1 = p2;
                    obj.add(deserialize(s, p1));
                }
                if(s[p2] == ']'){
                    return obj;
                }
            }
        }
        return obj;
    }
    
public:
    NestedInteger deserialize(string s) {
        NestedInteger answer;
        if(s[0] != '['){
            // single integer
            answer.setInteger(stoi(s));
        }else{
            // nested list
            int p1 = 0;
            answer = deserialize(s, p1);
        }
        return answer;
    }
};