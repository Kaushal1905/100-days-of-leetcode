class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string result;
        int count = 0;
        for (char a : s) {
            if (a == x) {
                count++;
            } 
            else {
                result += a;
            }
        }
        result += string(count, x);
        return result;
    }
};