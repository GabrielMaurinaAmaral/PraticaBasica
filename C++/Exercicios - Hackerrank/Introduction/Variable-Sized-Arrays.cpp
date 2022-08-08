#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int* find_ans (int** roads, int** new_roads, int n , int* out_n) {
   // Write your code here
}

int main() {
    int out_n;
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    int s;
    scanf("%d", &s);
    int i_roads, j_roads;
    int **roads = (int **)malloc(m*sizeof(int *));
    for(i_roads=0; i_roads<m; i_roads++)
    {
    	roads[i_roads] = (int *)malloc(s*sizeof(int));
    }
    for(i_roads=0; i_roads<m; i_roads++)
    {
    	for(j_roads=0; j_roads<s; j_roads++)
    	{
    		scanf("%d", &roads[i_roads][j_roads]);
    	}
    }
    int q;
    scanf("%d", &q);
    int s1;
    scanf("%d", &s1);
    int i_new_roads, j_new_roads;
    int **new_roads = (int **)malloc(q*sizeof(int *));
    for(i_new_roads=0; i_new_roads<q; i_new_roads++)
    {
    	new_roads[i_new_roads] = (int *)malloc(s1*sizeof(int));
    }
    for(i_new_roads=0; i_new_roads<q; i_new_roads++)
    {
    	for(j_new_roads=0; j_new_roads<s1; j_new_roads++)
    	{
    		scanf("%d", &new_roads[i_new_roads][j_new_roads]);
    	}
    }

    int* out_ = find_ans(roads, new_roads, n, &out_n);
    printf("%d", out_[0]);
    for(int i_out_=1; i_out_<out_n; i_out_++)
    	printf(" %d", out_[i_out_]);
}