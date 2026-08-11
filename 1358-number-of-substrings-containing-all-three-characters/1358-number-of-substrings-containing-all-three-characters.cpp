class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0}; // counts for 'a', 'b', 'c'
        int left = 0;
        long long res = 0; // use long long to be safe, though int suffices here
        
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[left] - 'a']--;
                left++;
            }
            res += left;
        }
        
        return (int)res;
    }
};