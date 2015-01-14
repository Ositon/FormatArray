#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

int main()
{
  string line ; int i ; string newLine = "[ " ; string newFileName ;
  ifstream read( "list.txt" ) ; // create input filestream object to read txt file.
  
  if ( ! read )	// throw exception if unable to read file
  {
    cout << "Error Opening Input File" << endl ;	// error message
	return -1 ;
  }

  getline( read , line ) ; newLine += "'" + line + "'" ; // first line doesn't have comma prepend
  for ( i = 0 ; ! read.eof() ; i++ ) // .eof() function check to see if end of file.  Does loop while it is not the end of file.
  {
    getline( read , line ) ;
    newLine += " , '" + line + "'" ;  // appends lines from getline to newLine string
  }
  newLine += " ]" ;
  read.close() ; //close filestream

  cout << "Please type the name of the file to be created:" << endl ;
  getline( cin , newFileName ) ;
  newFileName += ".txt" ;
  ofstream writer( newFileName.c_str() ) ; // open filestream to write to new file name array.txt 
  
  if ( ! writer ) // throw exception if unable to write file
  {
    cout << "Error Opening File for Output" << endl ;
	return -1 ;
  }
  writer << newLine << endl ;  // write to file
  writer.close() ;  // close filestream
  return 0 ;
}
