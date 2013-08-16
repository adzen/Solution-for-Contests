/* 12209272 0.032 */

/* 先暴力求解列表後，找到 DP 的規則即可。 */

#include <stdio.h>

unsigned long long int mid[1000001];
unsigned long long int ans[1000001];

int main(){
   /* 中間過程 */
   int i, j = 0;
   for(i = 4; i <= 1000000; ++i){
      if(i % 2 == 0) j++;
      mid[i] = mid[i-1] + j;
   }
   
   /* 為答案建表 */
   for(i = 4; i <= 1000000; ++i){
      ans[i] = ans[i-1] + mid[i];
   }
   
   /* 小心結束條件 */
   int in;
   while( scanf("%d", &in) && in >= 3 ) printf("%llu\n", ans[in]);
   
   return 0;
}


/* 暴力求解的程式：O(N^3)

#include <stdio.h>

int cal(int in){
   int i, j, k, ans = 0;
   for(i = in; i >= 1; i--){
   for(j = i-1; j >= 1; j--){
   for(k = j-1; k >= 1; k--){
      if(j+k > i) ans++;
   }}}
   return ans;
}

int main(){
   int n;
   for(n = 1; n <= 100; n++){
      printf("%d\t%d\n", n, cal(n) );
   }
   while(1);
   return 0;
}

*/


/* 建出來的表：

1	0		
2	0	0	
3	0	0	0
4	1	1	1
5	3	2	1
6	7	4	2
7	13	6	2
8	22	9	3
9	34	12	3
10	50	16	4
11	70	20	4
12	95	25	5
13	125	30	5
14	161	36	6
15	203	42	6
16	252	49	7
17	308	56	7
18	372	64	8
19	444	72	8
20	525	81	9
21	615	90	9

*/
