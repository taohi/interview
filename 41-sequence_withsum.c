#include <stdio.h>
 
void print_sequence(int small,int big)
{
    int i=0;
    for(i=small;i<=big;i++)
        printf("%d  ",i);
    printf("\n");
}

void find_sequence(int sum)
{
    if(sum<3)
        return;
    int small=1;
    int big=2;
    int middle=(1+sum)/2;
    int cur_sum=small+big;
    while(small<middle)
    {
        while(cur_sum<=sum)
        {
            if(cur_sum == sum)
                print_sequence(small,big);
            big++;
            cur_sum+=big;
        }
        cur_sum-=small;
        small++;
    }
}

int main()
{
    int sum;
    scanf("%d",&sum);
    find_sequence(sum);
    return 0;
}
