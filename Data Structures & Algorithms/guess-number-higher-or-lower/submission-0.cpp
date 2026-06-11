/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while(l <= r) {
            int my_guess = (l + r)/2;
            int result = guess(my_guess);
            if(result == 0)
                return my_guess;
            else if (result == -1) {
                r = my_guess - 1;
            }
            else {
                l = my_guess + 1;
            }
        }
        return -1;
    }
};