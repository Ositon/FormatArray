/*
	Things to do:
  1). Add in the ability to open files in different directories
  2). Check over code to see if it can be stated more elegantly
  3). Check if file is already formatted
*/
  
#include <iostream>
#include <fstream>
#include <string>
using namespace std ;

int main()
{
  string line ; int i ; string newLine = "[ " ; string newFileName ; string readFile ;
  cout << "Please type the name of which file you wish to read:" << endl ; // ask file to open
  getline( cin , readFile ) ;
  readFile += ".txt" ;
  ifstream read( readFile.c_str() ) ; // create input filestream object to read txt file.
  
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

  cout << "Please type the name of the file to be created:" << endl ; // ask file name to create
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
