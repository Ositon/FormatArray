#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

int main()
{
  string line ; int i ; string newLine ;

  ifstream read( "list.txt" ) ; // create input filestream object to read txt file.
  if ( ! read )	// throw exception if unable to read file
  {
    cout << "Error Opening Input File" << endl ;	// error message
	return -1 ;
  }
  for ( i = 0 ; ! read.eof() ; i++ ) // .eof() function check to see if end of file.  Does loop while it is not the end of file.
  {
    getline( read , line ) ;
	newLine += line ;  // appends lines from getline to newLine string
  }
  cout << newLine << endl ;
  
  read.close() ; //close filestream
  cout << "Iterations: " << i << endl ;
  
  return 0 ;
}