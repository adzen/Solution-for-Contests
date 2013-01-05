/* 11106642 0.004 */
/* 有點麻煩的題目。不過不難... */
/* 考驗 string 操作功力的好題目XD */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
   char key[100];  /* 關鍵字 */
   int num, list[500];  /* 行號個數、行號 */
} node;

node nodes[500];
node *nptrs[500];
int nodesn = 0;

void add(char *word, int line){
   int i;
   for(i = 0; i < nodesn; ++i){
      if( strcmp(word, nodes[i].key) == 0 ) break;
   }
   
   if(i >= nodesn){  /* 沒找到。新增一個 node */
      strcpy(nodes[nodesn].key, word);
      nodes[nodesn].num = 1;
      nodes[nodesn].list[0] = line;
      nodesn++;
   }else{
      if( nodes[i].list[ nodes[i].num-1 ] < line ){  /* 找到，但是新行號。新增行號 */
         nodes[i].list[ nodes[i].num ] = line;
         nodes[i].num++;
      }
   }
}

int cmp(node **a, node **b){  /* 使用 pointer 來排序 */
   return strcmp((*a)->key, (*b)->key);
}

void up(char *word){  /* 把那個字的大寫字母通通移到前面。12AB3C4 → ABC */
   int i = 0, j = 0;
   while( word[j] ){
      if( isupper(word[j]) ){
         word[i] = word[j];
         i++;
      }
      j++;
   }
   word[i] = 0;
}

int main(){
   char line[100], index[5];   /* 當作 index 的開頭字母 */
   gets(line);
   sscanf(line, "%s", index);
   
   int linen = 1;
   char word[100];
   while( gets(line) != NULL ){
      char *ptr = strtok(line, " ");
      while(ptr != NULL){
         strcpy(word, ptr);
         up(word);
         if(word[0] == index[0]) add(word, linen);  /* 開頭一樣，試著加入 */
         ptr = strtok(NULL, " ");
      }
      linen++;
   }
   
   int i, j;
   for(i = 0; i < nodesn; ++i) nptrs[i] = &nodes[i];  /* 先把 pointer 指到該指的 node */
   qsort(nptrs, nodesn, sizeof(node*), cmp);
   
   for(i = 0; i < nodesn; ++i){
      printf("%s", (nptrs[i])->key);
      for(j = 0; j < (nptrs[i])->num; ++j) printf(" %d", (nptrs[i])->list[j]);
      puts("");
   } 
   
   return 0;
}
