package Utilities;

/**
 * Created by Nick on 10/10/2014.
 */
public interface Stack<T> {
    /**
     * Push input onto the top of the stack. If input is null, it will not be pushed onto the stack.
     *
     * @param input value of type T to be pushed onto the stack
     * @return true if the value was pushed onto the stack. false if the value was not pushed onto the stack.
     */
    public boolean push(T input);

    /**
     * Get value of type T at the top of the stack and remove that value from the stack.
     *
     * @return value of Type T at the top of the stack if the stack is not null. null otherwise
     */
    public T pop();

    /**
     * Get value of type T at the top of the stack (Note: this is a shallow copy). The value is not removed from the stack.
     *
     * @return value of Type T at the top of the stack if the stack is not null. null otherwise
     */
    public T peek();

    /**
     * @return true if the stack is empty. false otherwise
     */
    public boolean isEmpty();

    /**
     * @return true if the stack is full. false otherwise
     */
    public boolean isFull();

    /**
     * restore the stack to its initial state
     */
    public void clearStack();
}
