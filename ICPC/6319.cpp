/* 1182353 0.038 */
/* string operations... */
/* Using C++ std::string is fun... XD */

#include <cstdio>

#include <iostream>
#include <string>

using namespace std;

int main(){
   int test;
   cin >> test;
   
   while( test-- ){
      string s;
      cin >> s;
      
      string cmd;
      cin >> cmd;
      while( cmd != "END" ){
         if( cmd == "I" ){
            string tok;
            int x;
            cin >> tok >> x;
            s.insert(x, tok);
         }else{
            int x, y;
            cin >> x >> y;
            cout << s.substr(x, y-x+1) << endl;
         }
         cin >> cmd;
      }
   }

   return 0;
}
