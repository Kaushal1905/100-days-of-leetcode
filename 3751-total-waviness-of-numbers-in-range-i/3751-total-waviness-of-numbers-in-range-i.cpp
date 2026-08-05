class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;

        for (int num = num1; num <= num2; num++) {
            string s = to_string(num);

            if (s.length() < 3) continue;

            for (int i = 1; i < s.length() - 1; i++) {
                int prev = s[i - 1] - '0';
                int curr = s[i] - '0';
                int next = s[i + 1] - '0';

                if (curr > prev && curr > next) {
                    total++;
                }
                else if (curr < prev && curr < next) {
                    total++;
                }
            }
        }

        return total;
    }
};