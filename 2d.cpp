#include <time.h>
#include <iostream>
using namespace std;
int main()
{
  cout<<"Random numbers generated between 0 and 1:"<<endl;
  srand( (unsigned)time( NULL ) );

  for (int i = 0; i < 5; i++) 
  {
      cout << (float) rand()/RAND_MAX << endl;
  }
  return 0;
}