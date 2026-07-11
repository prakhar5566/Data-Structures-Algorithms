class Solution {
public:
    int minBitFlips(int start, int goal) {
        int Xor = start ^ goal;
        int count = 0;
        while (Xor) {
            count++;
            Xor = Xor & (Xor-1);
        }
        return count;
    }
};