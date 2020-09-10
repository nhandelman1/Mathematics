package Utilities;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Nick on 10/10/2014.
 *
 * This class is designed to be declared and initialized once. Successive calls to convert() will reset the class to
 * its initial state.
 *
 * Operators/Parentheses: + - * / ^ ( )
 * Order of Precedence of Operators/Parentheses (operators on the same line have equal precedence):
 * Highest: ( (when in the input)
 *          !
 *          ^
 *          * /
 *          + -
 * Lowest:  ) ( (when in the stack)
 * Note: the precedence of ) is unnecessary as it is never pushed onto the stack
 * Note: the algorithm only works for unary and binary operators TODO modify algorithm to work with n-ary operators
 *
 * Operands are any greater-than-zero sequence of characters (that aren't operators/parentheses) found in the following
 * locations (note that between implies the sequence of characters not including the operator/parenthesis):
 *  1. between the beginning of the infix expression and the first operator
 *  2. between two operators
 *  3. between the last operator and the end of the infix expression
 *  4. between a left parenthesis and an operator
 *  5. between an operator and right parenthesis
 *  for example: the infix expression 5 + 4 - 3 yields 3 operands: 5 4 3
 *               the infix expression 5 + (44 - 33) * 256 + 1 yields 5 operands: 5 44 33 256 1
 *
 * Notes about correct infix grammar:
 *  1. spacing between operands and operators is unnecessary. The expression 5+4 will be converted the same as 5 + 4 or
 *      or 5 +4 or 5+ 4.
 *  2. Multiplication: multiplication of the form 5(3+4) (implied multiplication) will cause the conversion to fail.
 *      This expression should instead be written as 5*(3+4).
 *      TODO modify algorithm to also accept implied multiplication
 *  3. Roots - roots must be input as fractional exponents.
 *      for example: square_root(2) must be written as 2 ^ 0.5 (or equivalent form within the confines of the grammar)
 *  4. Summation
 *      TODO implement summation S
 */
public class ConvertInfixToPostfix {
    private final Stack<Operator> stack = new ArrayStack<>(Operator.class);
    private final List<Term> postfixTermList = new ArrayList<>();

    private int positionInInfixStr = 0;
    private int operandCount = 0;
    private int binaryOperatorCount = 0;

    public List<Term> convert(final String infixString) throws ConvertInfixToPostfixException {
        stack.clearStack();
        postfixTermList.clear();
        operandCount = 0;
        binaryOperatorCount = 0;
        String operandStr = "";
        boolean previousCharIsBinaryOperatorOrLeftParen = true; //used to determine negative operand

        for(positionInInfixStr = 0; positionInInfixStr < infixString.length(); positionInInfixStr++) {
            final char infixChar = infixString.charAt(positionInInfixStr);

            if(infixChar == ' ') { //disregard spacing
                continue;
            }

            if(infixChar == '(') {
                operandStr = addOperandToPostfixTermList(operandStr);
                previousCharIsBinaryOperatorOrLeftParen = true;

                stack.push(new Operator(String.valueOf(infixChar), determineLevelOfPrecedence(infixChar), 0));
            } else if(infixChar == ')') {
                operandStr = addOperandToPostfixTermList(operandStr);
                previousCharIsBinaryOperatorOrLeftParen = false;

                processRightParenthesis();
            } else if(infixChar == '-' && previousCharIsBinaryOperatorOrLeftParen) { //check for negative character
                operandStr += infixChar;
                previousCharIsBinaryOperatorOrLeftParen = false;
            } else if(isUnaryOperator(infixChar)) { //unary operators (e.g. factorial) are already in postfix notation
                if(previousCharIsBinaryOperatorOrLeftParen) {
                    throw new ConvertInfixToPostfixException("A ! can not immediately follow a binary operator or a left" +
                            "paren. Check position: " + positionInInfixStr);
                }

                operandStr = addOperandToPostfixTermList(operandStr);

                final Operand lastOp = (Operand) postfixTermList.get(postfixTermList.size()-1);
                if(lastOp.isNegate() && lastOp.isNumber()) {
                    throw new ConvertInfixToPostfixException("A factorial operation on a negative number is not allowed. " +
                            "Check position: " + positionInInfixStr);
                }

                previousCharIsBinaryOperatorOrLeftParen = false;
                postfixTermList.add(new Operator(String.valueOf(infixChar), determineLevelOfPrecedence(infixChar),
                        determineNumOfArguments(infixChar)));
            } else if(isBinaryOperator(infixChar)) {
                operandStr = addOperandToPostfixTermList(operandStr);
                previousCharIsBinaryOperatorOrLeftParen = true;

                processBinaryOperator(infixChar);
            } else { //operand or part of operand
                operandStr += infixChar;
                previousCharIsBinaryOperatorOrLeftParen = false;
            }
        }

        addOperandToPostfixTermList(operandStr);

        while(!stack.isEmpty()) {
            if(stack.peek().getOperator().equals("(")) {
                throw new ConvertInfixToPostfixException("An unmatched left parenthesis is remaining in the stack "
                    + "after all operands have been added to the postfix term list.");
            }
            postfixTermList.add(stack.pop());
        }

        //TODO modify to work with n-ary operators
        if(binaryOperatorCount > 0) {
            if(operandCount > binaryOperatorCount + 1) {
                throw new ConvertInfixToPostfixException("Too many operands.");
            } else if(binaryOperatorCount >= operandCount) {
                throw new ConvertInfixToPostfixException("Too many operators.");
            }
        }

        return postfixTermList;
    }

    /**
     * Add operand to postfixTermList if operand is not empty and operand does not equal "-"
     *
     * @param operandStr
     * @return empty String
     * @throws ConvertInfixToPostfixException if operandStr equals "-"
     */
    private String addOperandToPostfixTermList(String operandStr) throws ConvertInfixToPostfixException {
        if(!operandStr.isEmpty()) {
            if(operandStr.equals("-")) { // an operand of only '-' is illegal
                throw new ConvertInfixToPostfixException("An operand consisting of only a '-' is illegal. Check near" +
                        "position: " + positionInInfixStr);
            }
            postfixTermList.add(new Operand(operandStr));
            operandCount++;
        }

        return "";
    }

    /**
     * Pop from the stack until a left parenthesis is found.
     *
     * @throws ConvertInfixToPostfixException if no left parenthesis is found in the stack
     */
    private void processRightParenthesis() throws ConvertInfixToPostfixException {
        Operator operator;
        boolean leftParenNotFound;

        do {
            if(stack.isEmpty()) {
                throw new ConvertInfixToPostfixException("Unmatched right parenthesis at position " + positionInInfixStr);
            }

            operator = stack.pop();
            leftParenNotFound = !"(".equals(operator.getOperator());

            if(leftParenNotFound) {
                postfixTermList.add(operator);
            }
        } while(leftParenNotFound);
    }

    /**
     * Pop from the stack until an operator of lesser precedence than infixOperator is found or until stack is empty,
     * then push infixOperator onto the stack
     *
     * @param infixOperator the operator to be pushed onto the stack
     */
    private void processBinaryOperator(char infixOperator) {
        final Operator newOperator = new Operator(String.valueOf(infixOperator), determineLevelOfPrecedence(infixOperator),
                                                  determineNumOfArguments(infixOperator));

        while(!stack.isEmpty() && stack.peek().getLevelOfPrecedence() >= newOperator.getLevelOfPrecedence()) {
            postfixTermList.add(stack.pop());
        }

        stack.push(newOperator);
    }

    private boolean isUnaryOperator(char infixTerm) {
        boolean isUnaryOperator = false;

        switch(infixTerm) {
            case '!': isUnaryOperator = true;
                break;
        }

        return isUnaryOperator;
    }

    private boolean isBinaryOperator(char infixTerm) {
        boolean isBinaryOperator = false;

        switch(infixTerm) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^': isBinaryOperator = true;
                binaryOperatorCount++;
                break;
        }

        return isBinaryOperator;
    }

    private int determineLevelOfPrecedence(char operator) {
        int levelOfPrecedence = 0;

        switch(operator) {
            case '!': levelOfPrecedence = 4;
                break;
            case '^': levelOfPrecedence = 3;
                break;
            case '*':
            case '/': levelOfPrecedence = 2;
                break;
            case '+':
            case '-': levelOfPrecedence = 1;
                break;
            case '(':
            case ')': levelOfPrecedence = 0;
                break;
        }

        return levelOfPrecedence;
    }

    private int determineNumOfArguments(char operator) {
        int numOfArguments = 0;

        switch(operator) {
            case '^':
            case '*':
            case '/':
            case '+':
            case '-': numOfArguments = 2;
                break;
            case '!': numOfArguments = 1;
                break;
        }

        return numOfArguments;
    }

    public class ConvertInfixToPostfixException extends Exception {
        public ConvertInfixToPostfixException(String message) { super(message); }
    }
}
