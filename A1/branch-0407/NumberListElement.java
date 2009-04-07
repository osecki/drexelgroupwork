public class NumberListElement extends ListElement {
    protected Number n;
    public NumberListElement(Number n) {
        this.n = n;
    }

    public String toString() {
        return n.toString();
    }
}