package Utilities;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Created by Nick on 10/13/2014.
 *
 * This class is designed to be declared and initialized once. Successive calls to evaluate() and
 * convertStringToTermList() will reset the class to its initial state as necessary.
 *
 * This class evaluates postfix expressions in the form of List<Term>.
 * The utility method convertStringToTermList() can do this conversion to a delimited postfix String.
 * Class ConvertInfixToPostfix can convert an infix String to a postfix term list.
 *
 * Only a few checks are performed throughout this class, so it is the caller's responsibility to ensure that arguments
 * passed to evaluate() and convertStringToTermList() are populated correctly and are grammatically correct.
 *
 */
public class EvaluatePostfix {
    private final Stack<Operand> stack = new ArrayStack<>(Operand.class);

    private int position;

    public BigDecimal evaluate(final List<Term> postfixTermList, final Map<Operand, BigDecimal> variableValueMap) throws EvaluatePostfixException {
        if(variableValueMap == null) {
            throw new EvaluatePostfixException("variableValueMap can't be null.");
        }

        stack.clearStack();
        position = 0;
        Operand operand;
        BigDecimal variableValue;

        for(Term t : postfixTermList) {
            if(t instanceof Operand) {
                operand = (Operand) t;

                if(operand.isVariable()) {
                    variableValue = variableValueMap.get(operand);

                    if(variableValue == null) {
                        throw new EvaluatePostfixException("No value found for variable: " + operand.toString());
                    }

                    final Operand op;
                    if(operand.isNegate()) {
                        op = new Operand(variableValue.negate().toString());
                    } else {
                        op = new Operand(variableValue.toString());
                    }

                    stack.push(op);
                } else {
                    stack.push(operand);
                }
            } else if(t instanceof Operator) {
                final List<Operand> opList = new ArrayList<>();
                final Operator operator = (Operator) t;

                for(int x = operator.getNumOfArguments(); x > 0; x--) {
                    opList.add(stack.pop());
                }

                stack.push(processOperator(operator.getOperator(), opList));
            }
            position++;
        }

        return new BigDecimal(stack.pop().toString());
    }

    private Operand processOperator(String operatorStr, List<Operand> opList) throws EvaluatePostfixException {
        final List<BigDecimal> opValueList = new ArrayList<>();
        for(Operand op : opList) {
            BigDecimal opVal = new BigDecimal(op.getOperand());
            if(op.isNegate()) {
                opVal = opVal.negate();
            }

            opValueList.add(opVal);
        }

        //operand of an unary function is at position 0
        //right operand of a binary function is at position 0 in the list, left operand is at position 1
        final BigDecimal answer;
        if("+".equals(operatorStr)) {
            answer = opValueList.get(1).add(opValueList.get(0));
        } else if("-".equals(operatorStr)) {
            answer = opValueList.get(1).subtract(opValueList.get(0));
        } else if("*".equals(operatorStr)) {
            answer = opValueList.get(1).multiply(opValueList.get(0));
        } else if("/".equals(operatorStr)) {
            answer = opValueList.get(1).divide(opValueList.get(0));
        } else if("^".equals(operatorStr)) {
            answer = evaluateFractionalPower(opValueList.get(1), opValueList.get(0));
        } else if("!".equals(operatorStr)) {
            answer = evaluateFactorial(opValueList.get(0));
        } else {
            throw new EvaluatePostfixException("Unknown operator at position " + position);
        }

        return new Operand(answer.toString());
    }

    /**
     * This class is static except for the @throws. It doesn't need to remain this way, but doing so renders the reset
     * of class variables to their initial state unnecessary.
     *
     * Notes about correct postfix grammar:
     *  1. Postfix String must be delimited. If it is not delimited, it is impossible to distinguish consecutive operands.
     *      Correct: 5 5 +
     *      Incorrect: 55+
     *  2. Negative Numbers: negative numbers (i.e. -5) must be rewritten in the form: 0 5 -. This change helps to
     *      reduce the complexity of the postfix String to postfix term list conversion.
     *      for example: the postfix expression -5 4 + must be rewritten as: 0 5 - 4 +
     *      TODO modify algorithm to accept negative numbers as part of the postfix input
     *
     * @param postfixString
     * @param delimiter space (' ') is recommended
     * @return List<Term> postfixTermList
     * @throws EvaluatePostfixException - thrown for certain cases of incorrect postfix grammar in postfixString
     */
    public List<Term> convertStringToTermList(String postfixString, String delimiter) throws EvaluatePostfixException {
        final List<Term> postfixTermList = new ArrayList<>();
        final String postfixTermArray[] = postfixString.split(delimiter);
        int operandCount = 0;
        int operatorCount = 0;

        for(String term : postfixTermArray) {
            if(isOperator(term.charAt(0))) {
                postfixTermList.add(new Operator(term, 0, 2)); //levelOfPrecedence is not used when evaluating a
                operatorCount++;                               //postfix expression
            } else {
                postfixTermList.add(new Operand(term));
                operandCount++;
            }
        }

        //TODO modify to work with n-ary operators
        if(operandCount > operatorCount + 1) {
            throw new EvaluatePostfixException("Too many operands in postfix expression.");
        } else if(operatorCount >= operandCount) {
            throw new EvaluatePostfixException("Too many operators in postfix expression.");
        }

        return postfixTermList;
    }

    private static boolean isOperator(char operator) {
        boolean isOperator = false;

        switch(operator) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^': isOperator = true;
                break;
        }

        return isOperator;
    }

    public static List<Operand> getListOfVariables(final List<Term> postfixTermList) {
        final List<Operand> variableList = new ArrayList<>();

        for(Term t : postfixTermList) {
            if(t instanceof Operand && ((Operand) t).isVariable() && !variableList.contains(t)) {
                variableList.add((Operand) t);
            }
        }

        return variableList;
    }

    //TODO modify algorithm to evaluate fractional powers
    private static BigDecimal evaluateFractionalPower(final BigDecimal leftOp, final BigDecimal rightOp) {
        return leftOp.pow(rightOp.intValue());
    }

    //TODO implement gamma function to work with fractional factorials
    private BigDecimal evaluateFactorial(final BigDecimal leftOp) throws EvaluatePostfixException {
        if(leftOp.compareTo(BigDecimal.ZERO) < 0) {
            throw new EvaluatePostfixException("A factorial operation on a negative number is not allowed. " +
                    "Check near position: " + position);
        }

        int product = leftOp.intValue();
        if(product == 0) {
            return new BigDecimal(1);
        }

        for(int intVal = product - 1; intVal > 1; intVal--) {
            product = product * intVal;
        }

        return new BigDecimal(product);
    }

    public class EvaluatePostfixException extends Exception {
        public EvaluatePostfixException(String message) {
            super(message);
        }
    }
}
