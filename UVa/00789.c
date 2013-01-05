/* 11106642 0.004 */
/* ���I�·Ъ��D�ءC���L����... */
/* ���� string �ާ@�\�O���n�D��XD */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
   char key[100];  /* ����r */
   int num, list[500];  /* �渹�ӼơB�渹 */
} node;

node nodes[500];
node *nptrs[500];
int nodesn = 0;

void add(char *word, int line){
   int i;
   for(i = 0; i < nodesn; ++i){
      if( strcmp(word, nodes[i].key) == 0 ) break;
   }
   
   if(i >= nodesn){  /* �S���C�s�W�@�� node */
      strcpy(nodes[nodesn].key, word);
      nodes[nodesn].num = 1;
      nodes[nodesn].list[0] = line;
      nodesn++;
   }else{
      if( nodes[i].list[ nodes[i].num-1 ] < line ){  /* ���A���O�s�渹�C�s�W�渹 */
         nodes[i].list[ nodes[i].num ] = line;
         nodes[i].num++;
      }
   }
}

int cmp(node **a, node **b){  /* �ϥ� pointer �ӱƧ� */
   return strcmp((*a)->key, (*b)->key);
}

void up(char *word){  /* �⨺�Ӧr���j�g�r���q�q����e���C12AB3C4 �� ABC */
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
   char line[100], index[5];   /* ��@ index ���}�Y�r�� */
   gets(line);
   sscanf(line, "%s", index);
   
   int linen = 1;
   char word[100];
   while( gets(line) != NULL ){
      char *ptr = strtok(line, " ");
      while(ptr != NULL){
         strcpy(word, ptr);
         up(word);
         if(word[0] == index[0]) add(word, linen);  /* �}�Y�@�ˡA�յۥ[�J */
         ptr = strtok(NULL, " ");
      }
      linen++;
   }
   
   int i, j;
   for(i = 0; i < nodesn; ++i) nptrs[i] = &nodes[i];  /* ���� pointer ����ӫ��� node */
   qsort(nptrs, nodesn, sizeof(node*), cmp);
   
   for(i = 0; i < nodesn; ++i){
      printf("%s", (nptrs[i])->key);
      for(j = 0; j < (nptrs[i])->num; ++j) printf(" %d", (nptrs[i])->list[j]);
      puts("");
   } 
   
   return 0;
}
