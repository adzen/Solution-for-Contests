/* 1230219 1.142 */
/*
OS: Deadlock Detection Algorithm
http://www.csie.ntnu.edu.tw/~swanky/os/chap5.htm

TLE 的點：
(1) 暴搜（每次都看 pron 個）→ 使用 list 只保留 unfinish 的
(2) 先對 list 做排序，request 總和越小的要排越前面
*/

#include <cstdio>

#include <list>

using namespace std;

int allocation[50000][3], request[50000][3];
int available[3], work[3];
bool finish[50000];
int pron, resn; 

/* request 總和越小的要排越前面 */
bool request_sort(int pa, int pb){
   int asum = 0, bsum = 0;
   for(int i = 0; i < resn; ++i){
      asum += request[pa][i];
      bsum += request[pb][i];
   }
   return (asum < bsum);
}

int main(){
   while( scanf("%d%d", &pron, &resn) != EOF ){
      int res, pro;
      for(res = 0; res < resn; ++res){
      for(pro = 0; pro < pron; ++pro){
         scanf("%d", &allocation[pro][res]);
      }}
      
      for(res = 0; res < resn; ++res){
      for(pro = 0; pro < pron; ++pro){
         scanf("%d", &request[pro][res]);
      }}
      
      for(res = 0; res < resn; ++res){
         scanf("%d", &available[res]);
         work[res] = available[res];
      }
      
      list<int> unfinish;
      for(pro = 0; pro < pron; ++pro){
         finish[pro] = true;
         for(res = 0; res < resn; res++){
            /* 沒有 finish 的加進 list */
            if(allocation[pro][res] != 0){
               finish[pro] = false;
               unfinish.push_back(pro);
               break;
            }
         }
      }
      unfinish.sort(request_sort);  /* 先排序會比較快 */
      
      while(1){
         char found = false;
         
         for(list<int>::iterator it = unfinish.begin(); it != unfinish.end(); it++){
            pro = (*it);
            
            if(finish[pro] == false){
               /* 看有沒有比較小... */
               for(res = 0; res < resn; res++){
                  if(request[pro][res] > work[res]) break;
               }
               
               /* 如果找到... */
               if(res >= resn){
                  finish[pro] = true;
                  unfinish.erase(it);
                  for(res = 0; res < resn; res++){
                     work[res] += allocation[pro][res];
                  }
                  found = true;
                  break;
               }
            }
         }
         
         /* 最後看有沒有 deadlock */
         if(!found){
            puts( unfinish.size() == 0 ? "Yes" : "No" );
            break;
         }
      }
   }

   return 0;
}
