//2447 : 별 찍기 - 10
#include <stdio.h>
int a[6561][6561];
void st(int x, int y, int s)
{
    if (s==1) a[x][y]=1;
    else {
        for (int i=0; i<s; i+=s/3){
            for (int j=0; j<s; j+=s/3){
                if (i==s/3&&j==s/3) continue;
                st(x+i,y+j,s/3);
            }
        }
    }
}
int main()
{
    int x=0,y=0, s;
    scanf("%d",&s);
    st(x,y,s);
    for(int i=x; i<s; i++){
        for (int j=y; j<s; j++){
            if (a[i][j]) printf("*");
            else printf(" ");
        }
        if (i==s-1) break;
        printf("\n");
    }
}