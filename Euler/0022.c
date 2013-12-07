/* 字串字典排序+算字串分數的題目...算是秒殺題吧... */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num;
char allname[6000][30];

int cmp(const char *a, const char *b){
    return strcmp(a, b);
}

int main(){
    freopen("input.txt","r",stdin);
    
    /* 讀進所有名字並依字典排序 */
    while( scanf("\"%[A-Z]\",", &allname[num]) != EOF ) num++;
    qsort(allname, num, sizeof(char)*30, cmp);
    
    int i;
    long long ans = 0;
    for(i = 0; i < num; ++i){
        int j, score = 0;
        for(j = 0; allname[i][j]; ++j) score += allname[i][j]-'A'+1;  /* 算名字的分數 */    
        ans += (i+1) * score;   /* 用分數和排名算答案 */
    }
    printf("%lld\n", ans);

    return 0;
}
