#include <stdio.h>
long long fibonacci(unsigned n)
{
  int i=0;
  long long fibOne,fibTwo,fibThree;
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  fibOne=0;
  fibTwo=1;
  for(i=2;i<=n;i++)
 {
    fibThree = fibOne+fibTwo;
    fibOne=fibTwo;
    fibTwo=fibThree;
  }
  return fibThree;
  
}
int main()
{
  int n;
  scanf("%d",&n);
  printf("%lld\n",fibonacci(n)); 
  return 0;
}


