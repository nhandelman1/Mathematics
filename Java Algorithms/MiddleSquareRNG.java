package Algorithms;

/**
 * Created by Nick on 3/26/2015.
 */
public class MiddleSquareRNG {
    private long seed; //negative is allowed
    private long nextRN; //next random number
    private long highPower; //10 to the power of max length of random number
    private long lowPower; //10 to the power of half max length of random number
    private boolean badState = true; //flag to ensure good state before algorithm is processed

    /**
     * Generate the next random number.
     * @return next random number
     * @throws IllegalStateException - do not process algorithm if state variables are in a bad state
     */
    public long getNext() throws IllegalStateException {
        if(badState) {
            throw new IllegalStateException("This instance of " + this.getClass().getSimpleName() + " is in a bad state.");
        }

        //square number
        nextRN = nextRN*nextRN;

        //remove rightmost maxDigitsInRN/2 digits (e.g. remove rightmost 2 digits)
        nextRN /= lowPower;

        //remove leftmost maxDigitsInRN/2 digits (e.g. remove leftmost 2 digits) if nextRN has more digits than the value
        //of maxDigitsInRN
        if(nextRN/highPower > 0) {
            long temp = nextRN;
            temp /= highPower;
            temp *= highPower;
            nextRN -= temp;
        }

        return nextRN;
    }

    public long[] getNext(int howMany) {
        final long[] array = new long[]{};
        for(int i = 0; i < howMany; i++) {
            array[i] = getNext();
        }
        return array;
    }

    /**
     *
     * @param seed
     * @param maxDigitsInRN the maximum length of the random number to be generated, odd values will be incremented by 1
     * @throws IllegalArgumentException if seed and/or digits are invalid
     */
    public void reset(long seed, int maxDigitsInRN) throws IllegalArgumentException {
        maxDigitsInRN += maxDigitsInRN % 2;
        this.highPower = Utility.power(10, maxDigitsInRN);

        if(maxDigitsInRN < 1) {
            badState = true;
            throw new IllegalArgumentException("Length of generated random number must be greater than 0");
        } else if(seed/this.highPower > 0) {
            badState = true;
            throw new IllegalArgumentException("Length of seed must be less than or equal to length of random number "
                    + "being generated");
        }

        this.seed = seed;
        this.nextRN = seed;
        //OR could use maxDigitsInRN = (maxDigitsInRN-1)/2*2+2;
        //OR could use maxDigitsInRN = maxDigitsInRN % 2 != 0 ? maxDigitsInRN + 1 : maxDigitsInRN;
        this.lowPower = Utility.power(10, maxDigitsInRN/2);
        badState = false;
    }

    public long getSeed() {
        return seed;
    }
}
