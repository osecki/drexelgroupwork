/*
 *  Program:  List_RDP.java
 *  Authors:  Jordan Osecki, Geoff Oxholm, and Rich Price
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  Uses a recursive-descent parser to parse a simple list (of numbers and of lists), store it, and print it back out
 */

/*
 * 1. List:  ( Sequence ) | ( )
 * 2. Sequence:  ListElement, Sequence | ListElement
 * 3. ListElement:  List | NUMBER 
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class List_RDP
{
	// Global variables for current line and current token
	private static String line = "";
	private static String token;

	// Recursive-descent parser functions
	
	private static List List()
	{
		// Match '('
		match("(");
	    	
	    List temp;
	    	
	    if ( ! token.equals(")") )
	    {
	    	// Means it is not an empty list
	    	temp = new List( Sequence() );
	    }
	    else
	    {
	    	// Means it is an empty list
	    	temp = new List ();
	    }
	    		
	    // Match ')'
	    if ( ! token.equals(")") )
	    	error();
	    
	    return temp;
	}

	private static Sequence Sequence ()
	{
		// Match ListElement
		ListElement tempLE = ListElement();
	    
		// Look for comma
	    if ( token.equals(",") )
	    {
	    	// Means more than one item in list
	    	grabChar();
	    	Sequence temp = new Sequence (tempLE, Sequence());
	    	return temp;
	    }
	    else
	    {
	    	// Means only one item in list
	    	Sequence temp = new Sequence (tempLE);
	    	return temp;
	    }
	}

	private static ListElement ListElement()
	{
    // Test if token is a number
		boolean isNum = true;

		try
		{
			Integer.parseInt(token);
		}
		catch (Exception e)
		{
			isNum = false;
		}

		// Match a number
		if ( isNum )
		{
			ListElement temp = new NumberListElement(Integer.parseInt(token));	
			grabChar();
			return temp;
		}
		// Match a list
		else if (token.equals("("))
		{
			ListElement temp = new ListListElement (List());
			grabChar();
			return temp;
		}
		// Matched neither, so there was an error
		else
		{
			error();
			return null;
		}
	}

	// Function which grabs next token (character) and shortens 'line'
	private static void grabChar () 
	{	
		// Error if line empty when a token is asked for
		if (line.length() == 0 )
			error();
		
		// Grab initial token
		token = line.substring(0, 1);
		line = line.substring(1);

		// Move it past white space to something real
		while ( token.equals(" ") ) //&& line.length() > 0 )
		{
			token = line.substring(0, 1);
			line = line.substring(1);
		}

		// Grab more if it is a number
		if ( Character.isDigit(token.charAt(0)) || ( token.charAt(0) == '-' && Character.isDigit(peakAtNext())) )
		{
			while ( Character.isDigit(peakAtNext()) )
			{
				token += Character.toString(peakAtNext());
				line = line.substring(1);
			}
		}
	}
	
	// Function which returns the next character, if one exists
	private static char peakAtNext()
	{
		if ( line.length() >= 1 )
			return line.charAt(0);
		else
			return '~';
	}
	
	// Function which takes a symbol, matches it if token equals it, otherwise throws error
	private static void match (String c)
	{
		if (token.equals(c))
		{
			grabChar();
		}
		else
			error();
	}

	// Error in parsing gets caught here
	private static void error() 
	{
	   System.out.println("Invalid list syntax used.");
	   System.exit(1);
	}
	
	// Main:  Reads from Stdin multiple regular expressions, sending them to parser
	public static void main ( String [] args )
	{
		// Read from Stdin and send it to the parser
		InputStreamReader sr = new InputStreamReader(System.in);
		BufferedReader br    = new BufferedReader(sr);

		while (true) 
		{
			try 
		    {
		      line = br.readLine();
		      grabChar();
		      List temp = List();
		      System.out.print("Output:  "); temp.print();
		     }
		    catch (Exception e) 
		    {
		    	System.out.println("Stdin exited. Please re-run the file to test more Regular expressions.");
		    	break;
		    }
		}
	}
}
