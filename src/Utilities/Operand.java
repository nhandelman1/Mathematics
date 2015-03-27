package Utilities;

/**
 * Null Strings and empty Strings are allowed for constructor argument. They are converted to value "0". It is the
 * responsibility of the instantiating class to ensure that arguments passed to the constructor are both non-null and
 * non-empty.
 *
 * TODO throw exception if null or empty String argument is passed to the constructor?
 * TODO implement imaginary operands
 * Created by Nick on 10/10/2014.
 */
public class Operand extends Term<String> {

    /**
     * A NUMBER is an operand consisting of any number of digits 0 through 9. It may contain no more than one period.
     * A VARIABLE is an operand that is not a number.
     *
     * Operand may be extended to classes Number and Variable, instead of using OperandType to differentiate between
     * operands of type NUMBER and type VARIABLE. If this change is made, the operand type will have to be determined
     * before instantiating the class.
     */
    private enum OperandType {
        NUMBER,
        VARIABLE
    }

    private final OperandType type;
    private final boolean isNegate;

    /**
     * @param operand String can be null, empty or non-empty. null or empty String are converted to "0".
     *                a leading '-' (indicating negative) is removed and a flag indicates that the number is negative
     */
    public Operand(String operand) {
        super(operand == null || operand.isEmpty() ? "0" : operand.charAt(0) == '-' ? operand.substring(1) : operand);
        this.isNegate = operand != null && operand.charAt(0) == '-';
        this.type = determineOperandType(getOperand());
    }

    /**
     * 46 - ASCII value for period (.)
     * 48 - ASCII value for zero (0)
     * 57 - ASCII value for nine (9)
     *
     * @param operand String
     * @return OperandType is operand a variable or number?
     */
    private static OperandType determineOperandType(String operand) {
        boolean periodFound = false;
        char c = ' ';

        for(int i = 0; i < operand.length(); i++) {
            c = operand.charAt(i);

            if(c == 46) { //is a period
                if(periodFound) { //a period has already been encountered
                    return OperandType.VARIABLE;
                } else {
                    periodFound = true;
                }
            } else if (c < 48 || c > 57) { //not a digit
                return OperandType.VARIABLE;
            }
        }

        return OperandType.NUMBER;
    }

    /**
     * @return operand without a '-' prepended (if isNegate is true)
     */
    public String getOperand() { return getTerm(); }

    public boolean isVariable() { return type == OperandType.VARIABLE; }

    public boolean isNumber() { return type == OperandType.NUMBER; }

    public boolean isNegate() { return isNegate; }

    /**
     * @return operand with a '-' prepended (if isNegate is true)
     */
    @Override
    public String toString() { return isNegate ? "-" + getOperand() : getOperand(); }

    /**
     * Assuming that obj and this are both instances of Operand:
     * If this is a number and obj is a number, then this and obj must have the same operand value and both this and obj
     * must have the same isNegate flag value. e.g. -5 == -5 but -5 != 5
     *
     * If this is a variable and obj is a variable, then this and obj must have the same operand value. They need not
     * have the same isNegate flag value. e.g. -x == -x and -x == x.
     *
     * @param obj some Object being compared against this
     * @return true if this and obj are equal, false otherwise
     */
    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Operand) {
            if(obj == this) {
                return true;
            }

            final Operand otherOp = (Operand) obj;

            if(otherOp.isVariable() && this.isVariable() && otherOp.getOperand().equals(this.getOperand())) {
                return true;
            } else if(otherOp.isNumber() && this.isNumber() && otherOp.isNegate && this.isNegate
                    && otherOp.getOperand().equals(this.getOperand())) {
                return true;
            }
        }

        return false;
    }
}
