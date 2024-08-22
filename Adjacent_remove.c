#include <stdio.h>
#include <string.h>
#define m 30

void rem(char *s) {
    int i,j;
    int l=strlen(s);
    int f;

    do {
        f=0; 
        j=0; 
		 for(i=0;i<l;i++)
		 {
            if(i<l-1&&s[i]==s[i+1])
			 {
			 f=1; 
              while (i<l-1&&s[i]==s[i+1])
				{
                    i++;
                }
            }else
			 {
                s[j++]=s[i];
            }
        }
        s[j]='\0'; 
        l=j; 
    }while(f);
	j=0; 
    for(i=0;i<l;i++){
        if ((i==0||s[i]!=s[i-1])&&(i==l-1||s[i]!=s[i+1])){
            s[j++]=s[i]; 
			}
    }
	s[j]='\0'; 
}

int main(){
    char s[m];
    printf("Input a string: ");
    scanf("%s",s);
	rem(s);
    printf("Output string: %s",s);
    return 0;
}
