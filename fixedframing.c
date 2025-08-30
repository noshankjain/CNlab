#include<stdio.h>
#include<string.h>
int main()
{
 char str[100];
 int n,i,j,c=0,count=0,s; 
 printf("Enter the string: ");
 scanf("%s",str);
 printf("enter no of frames: ");
 scanf("%d",&n);
 int frames[n];
 printf("enter the frame size\n");
 scanf("%d",&s);
 int l=strlen(str);
 int r=l%s;
 printf("r=%d\n",r);
 if(r==0)
    n=r/s;
 else
    n=(l/s)+1;
 printf("n=%d\n",n);
 for(i=0;i<n;i++)
 {
  printf("frame %d: ",i);
  scanf("%d",&frames[i]);
  frames[i]=s;
 }
 printf("\nthe no of frames: %d\n",n);
 for(i=0;i<n;i++)
 {
  printf("the content of frame %d: ",i);
  j=0;
  while(c<strlen(str) && j<frames[i])
  {   
   printf("%c",str[c]);
   if(str[c]!='\0')
   {
    count++;
   }
    c=c+1;
    j=j+1;
  }
   printf("\nsize of frame %d: %d\n\n",i,count);
   count=0;
 }
}
