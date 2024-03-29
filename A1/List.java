/**
 *  Program:  List.java
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  List Class which can be built from parser and can print
 **/

public class List extends ListElement {
    private Sequence elements;

    public List() {
        elements = null;
    }

    public List(Sequence s) {
        elements = s;
    }

    public String toString() {
        String s = "(";
        if (elements != null) {
             s = s + elements.toString();
        }

        return s + ")";
    }

    public void print ()
    {
        System.out.println(toString());
    }
}
