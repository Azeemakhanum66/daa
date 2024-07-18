// 
#include<stdio.h>
#include<stdlib.h>

int prims(int n, int a[10][10], int source){
    int d[100], s[10], i, j, u, v, minval, sum=0;
    for(i=1; i<=n; i++){
        s[i]=0;
        d[i]=a[source][i];
    }
    s[source]=1;
    for(i=1; i<=n-1; i++){
        minval=999;
        for(j=1; j<=n; j++)
            if(s[j]==0 && d[j]<minval){
                minval=d[j];
                u=j;
            }
        s[u]=1;
        sum=sum+d[u];
        for(v=1; v<=n; v++)
            if(s[v]==0 && d[v]>a[u][v])
                d[v]=a[u][v];
    }
    return sum;
}

void main(){
    int n, a[10][10], i,j, source, mstcost;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    printf("Enter the source node\n");
    scanf("%d", &source);
    printf("Enter the adjacency matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
    mstcost=prims(n,a,source);
    printf("The minimum cost of spanning tree is %d\n", mstcost);
}
