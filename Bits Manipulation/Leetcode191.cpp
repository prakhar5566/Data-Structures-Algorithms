class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if (n % 2 == 1)
                count++;
            n /= 2;
        }
        return count;
    }
};

// bit manipulation : n & (n-1) will give the number which will have same bits as 'n' except the rightmost set bit
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n = n & (n-1);
            count++;
        }
        return count;
    }
};