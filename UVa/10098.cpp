// 12549950 0.942
// 輸出一串字元不重複的 permutation
// 啊...就 next_permutation() 給他爽爽地用下去就好了XD

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
