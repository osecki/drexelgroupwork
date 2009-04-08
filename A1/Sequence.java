/*
 *  Program:  Sequence.java
 *  Authors:  Jordan Osecki, Joseph Conley, Geoff Oxholm, and Rich Price
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  Sequence Class which can be built from parser and can print
 */

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
        	if ( i != elements.size() - 1 )
        		s = s + elements.elementAt(i).toString() + ", ";
        	else
        		s = s + elements.elementAt(i).toString();
        }
        return s;
    }
}