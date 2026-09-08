class Solution {
public:
    int findComplement(int num) {
        long long mask = (1LL << (32 - __builtin_clz(num))) - 1;
        return num ^ (int)mask;
    }
};