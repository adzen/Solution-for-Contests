/* 1230219 1.142 */
/*
OS: Deadlock Detection Algorithm
http://www.csie.ntnu.edu.tw/~swanky/os/chap5.htm

TLE ���I�G
(1) �ɷj�]�C������ pron �ӡ^�� �ϥ� list �u�O�d unfinish ��
(2) ���� list ���ƧǡArequest �`�M�V�p���n�ƶV�e��
*/

#include <cstdio>

#include <list>

using namespace std;

int allocation[50000][3], request[50000][3];
int available[3], work[3];
bool finish[50000];
int pron, resn; 

/* request �`�M�V�p���n�ƶV�e�� */
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
            /* �S�� finish ���[�i list */
            if(allocation[pro][res] != 0){
               finish[pro] = false;
               unfinish.push_back(pro);
               break;
            }
         }
      }
      unfinish.sort(request_sort);  /* ���ƧǷ|����� */
      
      while(1){
         char found = false;
         
         for(list<int>::iterator it = unfinish.begin(); it != unfinish.end(); it++){
            pro = (*it);
            
            if(finish[pro] == false){
               /* �ݦ��S������p... */
               for(res = 0; res < resn; res++){
                  if(request[pro][res] > work[res]) break;
               }
               
               /* �p�G���... */
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
         
         /* �̫�ݦ��S�� deadlock */
         if(!found){
            puts( unfinish.size() == 0 ? "Yes" : "No" );
            break;
         }
      }
   }

   return 0;
}
