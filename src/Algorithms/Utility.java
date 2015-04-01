package Algorithms;

/**
 * Created by Nick on 3/27/2015.
 */
public final class Utility {

    public static int getLengthOfLong(long dividend) {
        int len = 0;
        do {
            dividend /= 10;
            len++;
        } while(dividend != 0);
        return len;
    }

    public static long power(long base, int power) {
        long prod = base;
        if(power == 0) {
            prod = 1;
        } else if(base != 0 && base != 1) {
            while(power-- > 1) {
                prod *= base;
            }
        }
        return prod;
    }

}
