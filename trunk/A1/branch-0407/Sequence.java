

import java.util.Vector;


public class Sequence {
    private Vector<ListElement> elements;

    public Sequence (ListElement e) {
        elements = new Vector<ListElement>();
        elements.add(0, e);
    }

    public Sequence (ListElement e, Sequence s) {
        elements = s.elements;
        elements.add(0, e);
    }

    public String toString() {
        String s = "";
        for ( int i = 0; i < elements.size(); i++ )
        {
            s = s + elements.elementAt(i).toString() + ", ";
        }
        return s;
    }
}
