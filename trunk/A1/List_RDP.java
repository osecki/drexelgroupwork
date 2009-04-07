/*
 *  Program:  List_RDP.java
 *  Authors:  Jordan Osecki, Joseph Conley, Geoff Oxholm, and Rich Price
 *  Class:    CS550, Assignment 1, Spring 2009
 *  Description:  Uses a recursive-descent parser to parse a simple list (of numbers and of lists), store it, and print it back out
 */

/*
 * Regex:  Term UNION Regex | Term
 * Term:  Factor CONCAT Term | Factor
 * Factor:  Object CLOSURE | Object
 * Object:  CHAR | LParen Regex RPAREN
 * 
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
	private static char token;

	// Recursive-descent parser functions
	
	private static ListObj List()
	{
		// Match '('
	    if (token == '(')
	    {
	    	grabChar();
	    	
	    	ListObj temp;
	    	
	    	if (token == ')')
	    	{
	    		temp = new ListObj(); // Match an empty list
	    		return temp;
	    	}
	    	else
	    	{
	    		// Match Sequence
	    		temp = new ListObj ( Sequence() );
	    		
	    		grabChar();
	    		
	    		// Match ')'
	    		if (token == ')')
	    			return temp;
	    		else
	    			error();
	    	}
	    }
	    else
	    {
	    	error();
	    	return null;
	    }
	}

	private static ListObj Sequence ()
	{
		// Match ListElement
		ListObj temp = ListElement();
	    
		grabChar();
		
		// Look for comma
	    if ( token == ',' )
	    {
	    	grabChar();
	    	ListObj temp2 = Sequence();
	    	temp.add(temp2);
	    }
	    
	    return temp;
	}

	private static ListObj ListElement()
	{
		// Match a number
		if ( Character.isDigit(token))
		{
			ListObj temp = new ListObj();
			temp.add(token + "");			
			return temp;
		}
		// Match a list
		else if (peakAtNext() == '(')
		{
			grabChar();
			ListObj temp = List();
			
			return temp;
		}
		// Matched neither, so there was an error
		else
		{
			error();
			return new ListObj();
		}
	}

	// Function which grabs next token (character) and shortens 'line'
	private static void grabChar () 
	{	
		// Error if line empty when a token is asked for
		if (line.length() == 0 )
			error();
		
		token = line.charAt(0);
		line = line.substring(1);
	}
	
	// Function which returns the next character, if one exists
	private static char peakAtNext()
	{
		if ( line.length() >= 1 )
			return line.charAt(0);
		else
			return '~';
	}

	// Error in parsing gets caught here
	private static void error() 
	{
	   System.out.println("Invalid regular expression given.");
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
		      ListObj temp = List();
		      temp.print();
		     }
		    catch (Exception e) 
		    {
		    	System.out.println("Stdin exited. Please re-run the file to test more Regular expressions.");
		    	break;
		    }
		}
	}
}