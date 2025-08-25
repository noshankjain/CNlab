/* bit stuffing*/
#include<stdio.h>
#include<string.h>
void main()
{
char c1[200]="",c2[200]="",c[100],d1[50]="01111110",d2[50]="01111110";
int m1=0,i,j=0,l=0,i1,m,n,k=0;
printf("enter binary value: ");
gets(c);
m=strlen(d1);
strcat(d1,c);
strcat(d1,d2);
printf("\n appending delimiter ");
puts(d1);
for(i=0;i<strlen(d1);i++)
{
 c1[1]=d1[i];
 if(l>=4)
 {
  if(c1[1]=='1' && c1[1-1]=='1' && c1[1-2]=='1' && c1[1-3]=='1' && c1[1-4]=='1')
  {
   strcat(c1,"0");
   l++;
  }
 }
l++;
}
printf("\n after stuffing ");
puts(c1);
printf("\n destuffing ");
for(i=0;i<strlen(c1);i++)
{
 printf("%c",c1[i]);
 c2[k]=c1[i];
 k++;
 if(c1[i]=='1')
   j++;
 else
   j=0;
 if(j==5)
 {
  while(c1[j+1]!=0)
   break;
  i++;
  j=0;
 }
}
for(i=0;i<m;i++)
 continue;
 printf("\n");
 for(i=m;i<strlen(c2);i++)
 {
  printf("%c",c2[i]);
  m1++;
  if(m1==strlen(c))
    break;
 }
}
