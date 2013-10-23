#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
   int test;
   cin >> test;
   
   while(test-- > 0){
      string input;
      cin >> input;
      sort( input.begin(), input.end() );
      
      cout << input << endl;
      while( next_permutation( input.begin(), input.end() ) ) cout << input << endl;
      cout << endl;
   }

   return 0;
}
