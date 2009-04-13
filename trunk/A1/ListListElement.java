/**
 *  Program:  ListListElement.java
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor Reza
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  ListListElement Class which can be built from parser and can print
 **/

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
