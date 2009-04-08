/**
 *  Program:  ListElement.java
 *  Authors:  Jordan Osecki, Joseph Conley, Geoff Oxholm, and Rich Price
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  ListElement Class which can be built from parser and can print
 **/

public abstract class ListElement{
    public void print() {
        System.out.println(toString());
    }

    /// Every ListElement sub-class must have this method
    public abstract String toString();
}