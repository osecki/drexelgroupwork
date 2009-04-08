public class ListListElement extends ListElement {
    List l;
    public ListListElement() {
        l = new List();
    }

    public ListListElement(List l) {
        this.l = l;
    }

    public String toString() {
        return l.toString();
    }
}