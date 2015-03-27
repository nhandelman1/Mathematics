package Utilities;

import java.lang.reflect.Array;

/**
 * Created by Nick on 10/10/2014.
 */
public class ArrayStack<T> implements Stack<T> {
    private static final int DEFAULT_ARRAY_SIZE = 5;

    private final Class<T> classTypeParameter;

    private T stack[];
    private int top;

    public ArrayStack(Class<T> classTypeParameter) {
        this.classTypeParameter = classTypeParameter;
        clearStack();
    }

    @Override
    public boolean push(T input) {
        if(isFull()) {
            extendArray();
        }

        if(input == null) {
            return false;
        } else {
            stack[++top] = input;

            return true;
        }
    }

    @Override
    public T pop() {
        if(!isEmpty()) {
            return stack[top--];
        }

        return null;
    }

    @Override
    public T peek() {
        if(!isEmpty()) {
            return stack[top];
        }

        return null;
    }

    @Override
    public boolean isEmpty() {
        return top == -1;
    }

    @Override
    public boolean isFull() {
        return top == stack.length - 1;
    }

    @Override
    public void clearStack(){
        top = -1;
        stack = (T[]) Array.newInstance(classTypeParameter, DEFAULT_ARRAY_SIZE);
    }

    private void extendArray() {
        final T[] tempStack = stack;

        stack = (T[]) Array.newInstance(classTypeParameter, tempStack.length + DEFAULT_ARRAY_SIZE);

        System.arraycopy(tempStack, 0, stack, 0, tempStack.length);
    }
}
