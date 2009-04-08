/**
 *  Program:  Sequence.java
 *  Authors:  Jordan Osecki, Geoff Oxholm, and Rich Price
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  Sequence Class which can be built from parser and can print
 **/

import java.util.Vector;
import java.util.Iterator;

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

        for (Iterator<ListElement> iterator = elements.iterator (); iterator.hasNext (); ) {
            s = s + iterator.next();
            if(iterator.hasNext()) {
                s = s + ", ";
            }
        }

        return s;
    }
}
