import java.util.Vector;

/*
 *  Program:  ListObj.java
 *  Authors:  Jordan Osecki, Joseph Conley, Geoff Oxholm, and Rich Price
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  List Class which can be built from parser and can print
 */

public class ListObj
{
	// Structure to store the information about the list
	private Vector <Object> mainList;
	
	// Constructor
	public ListObj ()
	{
		mainList = new Vector <Object> ();
	}
	
	// Inspectors and Mutators
	
	/**
	 * @return the mainList
	 */
	public Vector<Object> getMainList() {
		return mainList;
	}

	/**
	 * @param mainList the mainList to set
	 */
	public void setMainList(Vector<Object> mainList) {
		this.mainList = mainList;
	}

	// add:  Will add a number or list to main list
	public void add ( Object o )
	{
		mainList.add(o);
	}
	
	// print:  Will print out the list
	public void print ()
	{
		for ( int i = 0; i < mainList.size(); i++ )
		{
			System.out.println("Item [" + i + "] = " + mainList.elementAt(i));
		}
	}
}