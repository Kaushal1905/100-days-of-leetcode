class Solution {
public:
    string reverseVowels(string s) {
        // Bitmask for vowels within ASCII 'A'-'Z' and 'a'-'z' ranges
        static constexpr uint32_t upperMask = 
            (1u << ('A'-'A')) | (1u << ('E'-'A')) | (1u << ('I'-'A')) | 
            (1u << ('O'-'A')) | (1u << ('U'-'A'));
        static constexpr uint32_t lowerMask = 
            (1u << ('a'-'a')) | (1u << ('e'-'a')) | (1u << ('i'-'a')) | 
            (1u << ('o'-'a')) | (1u << ('u'-'a'));
        
        auto isVowel = [](char c) -> bool {
            if (c >= 'A' && c <= 'Z') return (upperMask >> (c - 'A')) & 1;
            if (c >= 'a' && c <= 'z') return (lowerMask >> (c - 'a')) & 1;
            return false;
        };
        
        char* p = s.data();
        int left = 0, right = (int)s.size() - 1;
        
        while (left < right) {
            while (left < right && !isVowel(p[left])) left++;
            while (left < right && !isVowel(p[right])) right--;
            
            if (left < right) {
                char tmp = p[left];
                p[left] = p[right];
                p[right] = tmp;
                left++;
                right--;
            }
        }
        
        return s;
    }
};