package Main;

import Algorithms.MiddleSquareRNG;
import Algorithms.Utility;
import Utilities.ConvertInfixToPostfix;
import Utilities.EvaluatePostfix;
import Utilities.Operand;
import Utilities.Term;

import java.math.BigDecimal;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by Nick on 10/10/2014.
 */
public final class Main {
    private static final Scanner KEYBOARD = new Scanner(System.in);

    public static void main(String[] args) {
        MiddleSquareRNG middleSquareRNG = new MiddleSquareRNG();
        boolean success = false;
        int seed;
        int digits;

        while(!success) {
            try {
                System.out.print("Enter seed: ");
                seed = KEYBOARD.nextInt();
                System.out.print("Enter number of digits of random number to generate (odd is incremented to next even): ");
                digits = KEYBOARD.nextInt();
                middleSquareRNG.reset(seed, digits);
                success = true;
            } catch(Exception e) {
                System.out.println(e.getClass().getSimpleName() + ": " + e.getMessage());
            } finally{
                KEYBOARD.nextLine(); //flush remaining entry
            }
        }

        System.out.println("Press enter to get random number. Enter 'exit' to quit.");
        String s = null;
        while(!"exit".equals(s)) {
            s = KEYBOARD.nextLine();
            System.out.println(middleSquareRNG.getNext());
        }
    }

    /*
    public static void main(String[] args) {
        final ConvertInfixToPostfix citp = new ConvertInfixToPostfix();
        final EvaluatePostfix ep = new EvaluatePostfix();

        int selection;
        String expression;
        String delimiter;
        List<Term> postfixTermList;

        do {
            System.out.println("1) Evaluate infix expression");
            System.out.println("2) Evaluate postfix expression");
            System.out.println("0) Quit");
            selection = KEYBOARD.nextInt();
            KEYBOARD.nextLine();

            try {
                switch(selection) {
                    case 1:
                        System.out.print("Enter infix expression: ");
                        expression = KEYBOARD.nextLine();

                        postfixTermList = citp.convert(expression);
                        System.out.print("Converted postfix expression: ");
                        for(Term t : postfixTermList) {
                            System.out.print(t.toString() + " ");
                        }
                        System.out.println();
                        break;
                    case 2:
                        System.out.print("Enter postfix expression: ");
                        expression = KEYBOARD.nextLine();
                        System.out.print("Enter delimiter: ");
                        delimiter = KEYBOARD.nextLine();
                        postfixTermList = ep.convertStringToTermList(expression, delimiter);
                        break;
                    default: continue;
                }

                final List<Operand> variableList = EvaluatePostfix.getListOfVariables(postfixTermList);
                System.out.println("Answer: " + ep.evaluate(postfixTermList, buildVariableValueMap(variableList)));

            } catch(Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        } while(selection != 0);
    } */

    private static Map<Operand, BigDecimal> buildVariableValueMap(List<Operand> variableList) {
        final Map<Operand, BigDecimal> variableValueMap = new HashMap<>();

        for(Operand var : variableList) {
            boolean noSuccess = true;
            do {
                System.out.print("Enter value for variable " + var.getOperand() + ": ");
                try {
                    variableValueMap.put(var, KEYBOARD.nextBigDecimal());
                    noSuccess = false;
                } catch(Exception e) {
                    System.out.println("Error: Decimal value not entered.");
                    KEYBOARD.nextLine();
                }
            } while(noSuccess);
        }

        return variableValueMap;
    }

}