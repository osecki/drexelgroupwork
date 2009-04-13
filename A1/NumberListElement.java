/**
 *  Program:  NumberListElement.java
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  NumberListElement Class which can be built from parser and can print
 **/

public class NumberListElement extends ListElement {
    protected Number n;
    public NumberListElement(Number n) {
        this.n = n;
    }

    public String toString() {
        return n.toString();
    }
}
