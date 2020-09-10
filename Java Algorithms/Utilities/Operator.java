package Utilities;

/**
 * Created by Nick on 10/10/2014.
 */
public class Operator extends Term<String> {

    private final int levelOfPrecedence;
    private final int numOfArguments;

    public Operator(String operator, int levelOfPrecedence, int numOfArguments) {
        super(operator);
        this.levelOfPrecedence = levelOfPrecedence;
        this.numOfArguments = numOfArguments;
    }

    public String getOperator() {
        return getTerm();
    }

    public int getLevelOfPrecedence() {
        return levelOfPrecedence;
    }

    public int getNumOfArguments() { return numOfArguments; }

    @Override
    public String toString() { return getOperator(); }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof  Operator) {
            if(obj == this) {
                return true;
            }
            if(((Operator) obj).getOperator().equals(this.getOperator())) {
                return true;
            }
        }
        return false;
    }
}
