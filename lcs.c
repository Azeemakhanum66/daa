// 
#include<stdio.h>
#include<string.h>

void lcs(char x[100], char y[100], int m, int n) {
    int len, i, j, L[100][100];
    char k[100];
    for(i=0; i<=m; i++){
        for(j=0; j<=n; j++)
            if(i==0 || j==0)
                L[i][j]=0;
            else
                if(x[i-1]==y[j-1])
                    L[i][j]=L[i-1][j-1] + 1;
                else
                    L[i][j]=L[i-1][j]>L[i][j-1]?L[i-1][j]:L[i][j-1];
    }
    printf("LCS length is %d\n", L[m][n]);
    len=L[m][n];
    k[len]='\0';
    i=m;
    j=n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            k[len-1]=x[i-1];
            i--;
            j--;
            len--;
        }
        else if(L[i-1][j]>L[i][j-1])
            i--;
        else
            j--;
    }
    printf("The LCS is %s\n", k);
}

int main(){
    char x[100], y[100];
    int m, n;
    printf("Enter the first string: ");
    fgets(x, sizeof(x), stdin);
    printf("Enter the second string: ");
    fgets(y, sizeof(y), stdin);
    x[strcspn(x, "\n")] = 0; // remove newline character
    y[strcspn(y, "\n")] = 0; // remove newline character
    m=strlen(x);
    n=strlen(y);
    lcs(x, y, m, n);
    return 0;
}
