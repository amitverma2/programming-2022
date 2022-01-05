class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long int newNumber = 0;
        int savedX = x;
        while (x) {
            newNumber *= 10;
            newNumber += x % 10;
            x /= 10;
        }
        if (newNumber == savedX) return true;
        return false;
    }
};
