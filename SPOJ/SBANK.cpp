/* 9304653  Sorting Bank Accounts  5.69 7.3M */
/* 並不需要真的做 sort，只需要用 map 計算次數即可 */

#include <cstdio>

#include <map>
#include <algorithm>

using namespace std;

class account{
   public:
      char control;
      int bank;
      int owner[4];
};

bool acccmp(const account &a, const account &b){
   if(a.control != b.control) return (a.control < b.control);
   if(a.bank != b.bank) return (a.bank < b.bank);
   for(int i = 0; i < 4; ++i){
      if(a.owner[i] != b.owner[i]) return (a.owner[i] < b.owner[i]);
   }
   return false;   /* 這裡不能寫 true，否則同樣的會被誤判成不一樣 */
}

int main(){
   int test, num;
   scanf("%d", &test);
   
   while( test-- > 0 && scanf("%d", &num) ){
      bool(*cmp)(const account&, const account&) = acccmp;
      map<account,int,bool(*)(const account&, const account&)> diction(cmp);
      
      /* 讀取帳號資訊 */
      for(int i = 0; i < num; ++i){
         account newacc;
         int t1, t2;
         scanf("%d%d", &t1, &t2);
         newacc.control = t1;
         newacc.bank = t2;
         
         for(int j = 0; j < 4; ++j){
            int t;
            scanf("%d", &t);
            newacc.owner[j] = t;
         }
         
         /* 看看有沒有插過 */
         map<account,int,bool(*)(const account&, const account&)>::iterator it = diction.find(newacc);
         if(it != diction.end()){
            it->second++;
         }else{
            diction.insert( pair<account,int>(newacc, 1) );
         }
      }
      
      /* 後面的輸出 */
      for(map<account,int>::iterator it = diction.begin(); it != diction.end(); ++it){
         printf("%02d %08d ", it->first.control, it->first.bank);
         for(int i = 0; i < 4; ++i) printf("%04d ", it->first.owner[i]);
         printf("%d\n", it->second);
      }
      
      if(test) putchar('\n');
   }

   return 0;
}
