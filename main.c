/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void encrypt (char*x, int key);
int main()
{
   // declare char message for encoding//
   
   char message[10000];
   int key; // rotation value cipher key//
   int i = 0; //loop counter//
   
   // make function to ascii convert lower to upper case.//
   
               
   printf("enter a message you want to have encrypted\n");
   scanf("%[^\n]", message);
   printf("please enter the encryption key\n""enter number between 1 & 26\n");
   scanf("%d",&key);
    for (i = 0; message[i]!='\0'; i++) 
                    {
                    if(message[i] >= 'a' && message[i] <= 'z') {
                    message[i] = message[i] -32;
                    }
                    }
printf("un-encrypted message: %s\n", message);       //test case change//
encrypt (message, key);
printf("encrypted message: %s\n", message);

}

void encrypt(char*x,int key)
{int i = 0;
while (x[i]!='\0')
{ 
x[i] = (x[i]-65 + key)%26 +65;
i = i++;
}
}


















