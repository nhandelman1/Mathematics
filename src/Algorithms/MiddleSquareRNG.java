package Algorithms;

/**
 * Created by Nick on 3/26/2015.
 */
public class MiddleSquareRNG {
    private long seed;
    private long nextRN;
    private int digits; //the length of the random number to be generated, odd values will be incremented
    private int nextRNSqLen; //max length of the squared number
    private int halfDigitsLen;

    public MiddleSquareRNG(long seed, int digits) {
        reset(seed, digits);
    }

    public long getNext() {
        //square number
        nextRN = nextRN*nextRN;

        //TODO look into minimizing this step, can bypass add leading zeros
        //add leading zeros to make number have length nextRNSqLen
        String s = String.valueOf(nextRN);
        if(s.length() != nextRNSqLen) {
            for(int i = 0; i < nextRNSqLen - s.length(); i++) {
                s = "0" + s;
            }
        }

        //get middle numbers
        nextRN = Long.valueOf(s.substring(halfDigitsLen, nextRNSqLen - halfDigitsLen));

        return nextRN;
    }

    public long[] getNext(int howMany) {
        final long[] array = new long[]{};
        for(int i = 0; i < howMany; i++) {
            array[i] = getNext();
        }
        return array;
    }

    public void reset(long seed, int digits) {
        this.digits = digits % 2 != 0 ? digits + 1 : digits;
        this.seed = seed;
        this.nextRNSqLen = digits*2;
        this.halfDigitsLen = digits/2;
        this.nextRN = seed;
    }

    public long getSeed() {
        return seed;
    }
}
