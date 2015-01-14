#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

int main()
{
  string line ; int i ; string newLine = "[ " ; int max ; string newFileName ;
  ifstream read( "list.txt" ) ; // create input filestream object to read txt file.
  
  if ( ! read )	// throw exception if unable to read file
  {
    cout << "Error Opening Input File" << endl ;	// error message
	return -1 ;
  }
  
  for ( i = 0 ; ! read.eof() ; i++)
  {
    getline( read , line ) ;
  }
  
  max = i ; // max = total numebr of lines on txt file
  cout << max << endl ;
  read.close() ; read.open( "list.txt" ) ;  // closes filestream and then reopens same file
  
  for ( i = 0 ; ! read.eof() ; i++ ) // .eof() function check to see if end of file.  Does loop while it is not the end of file.
  {
    if ( i < ( max - 1 ) ) // if not last line append ' ,  at end, if last line append ' instead.  Max -1 to account for i starting at 0 
	{
	  getline( read , line ) ;
	  newLine += "'" + line + "' , " ;  // appends lines from getline to newLine string
	}
	else
	{
	  getline( read , line ) ;
	  newLine += "'" + line + "'" ;
	}
  }
  newLine += " ]" ;
  cout << newLine << endl ;
  read.close() ; //close filestream
  cout << "Iterations: " << i << endl ;
/*  cout << "Please type the name of the file to be created:" << endl ;
  cin >> newFileName ;
  getline( std::cin , newFileName ) ;
  ofstream writer( newFileName ) ; // open filestream to write to new file name array.txt */
  
  if ( ! writer ) 
  {
    cout << "Error Opening File for Output" << endl ;
	return -1 ;
  }
  writer << newLine << endl ;  // write to file
  writer.close() ;  // close filestream
  return 0 ;
}
