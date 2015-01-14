// this is a proof of concept file that displays what the ascii character value of user input is.

#include <iostream>
using namespace std ;

int main()
{
  char input ;
  cin >> input ;
  int asci = input ;
  cout << "Key " << input << " is " << asci ;
  return 0 ;
}
