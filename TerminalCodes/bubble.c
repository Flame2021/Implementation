#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a[n],i=0,j=0,temp=0;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
for(i=0;i<n;i++)
printf("%d",a[i]);
return 0;
}
