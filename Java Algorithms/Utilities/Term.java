package Utilities;

/**
 * Created by Nick on 10/12/2014.
 *
 * A term is an element (Operand or Operator) of a mathematical expression. This class represents a term.
 */
public class Term<T> {

    private T term;

    public Term(T term) { this.term = term; }

    public T getTerm() { return term; }

    @Override
    public String toString() {
        return getTerm().toString();
    }
}
