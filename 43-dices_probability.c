#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXVALUE    6
void probability(int number)
{
    if(number<1)
        return;
    int *prob[2];
    prob[0]=(int *)malloc(sizeof(int)*MAXVALUE*number+1);
    prob[1]=(int *)malloc(sizeof(int)*MAXVALUE*number+1);
    int i=0;
    for(i=0;i<MAXVALUE*number+1;i++)
    {
        prob[0][i]=0;
        prob[1][i]=0;
    }
    int flag=0;
    for(i=1;i<=MAXVALUE;i++)
        prob[flag][i]=1;
    int k=2;
    int j=0;
    for(k=2;k<=number;k++)
    {
        for(i=0;i<k;i++)
            prob[1-flag][i]=0;
        for(i=k;i<=MAXVALUE*k;i++)
        {
            prob[1-flag][i]=0;
            for(j=1;j<=i && j<=MAXVALUE;++j)
            {
                prob[1-flag][i]+=prob[flag][i-j];
            }
        }
        flag=1-flag;
    }
    //打印概率
    double total = pow((double)MAXVALUE,number);
    for(i=number;i<=MAXVALUE*number;i++)
    {
        double ratio = (double)prob[flag][i]/total;
        printf("sum:%d\tratio:%.5f\n",i,ratio);
    }
    free(prob[0]);
    free(prob[1]);
}

int main()
{
    int number;
    printf("input num of dices:");
    scanf("%d",&number);
    probability(number);
    return 0;
}
