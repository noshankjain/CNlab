#include<string.h>
#include<stdio.h>
int main()
{
        char str[100];
        int n,i,j,c=0,count=0;
        printf("enter the string: ");
        scanf("%s",str);
        printf("enter no of frames: ");
        scanf("%d",&n);
        int frames[n];
        printf("enter the size of frames: ");
        for(i=0;i<n;i++)
        {
                printf("Frame %d: ",i);
                scanf("%d",&frames[i]);
        }
        printf("\n the no of frames is: %d\n",n);
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
                printf("\n size of frame %d: %d\n\n",i,count);
                count=0;
        }
}