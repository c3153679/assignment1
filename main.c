/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void encrypt (char*x, int key);
void unencrypt (char*x, int key);
void encryptsub (char*x);
void decryptsub (char*x);
int main()
{
   // declare char message for encoding//
   
   char message[100000];
   int key; // rotation value cipher key//
   int i = 0; //loop counter//
   
   // make function to ascii convert lower to upper case.//
   
               
   printf("enter a message you want to have encrypted\n");
   scanf("%[^\n]", message);
   printf("please enter the encryption key\n""enter number between 0 & 25\n");
   scanf("%d",&key);
    for (i = 0; message[i]!='\0'; i++) 
                    {
                    if(message[i] >= 'a' && message[i] <= 'z') {
                    message[i] = message[i] -32;
                    }else message[i] = message[i];
                    }
printf("input message/key: %s   %d\n", message , key);       //test case change//
encrypt (message, key);
 printf("encrypted message: %s\n", message);
unencrypt(message, key);
printf("unncrypted message: %s\n", message);
encryptsub(message);
 printf("substitution encrypted message: %s\n", message);
decryptsub(message);
printf("substitution decrypted message: %s\n", message);
}

void encrypt(char*x,int key)
{int i = 0;
while (x[i] != '\0')
{ if(x[i] <'A' || x[i] >'Z') {
                    x[i] = x[i];
                    i++;
                    }
                    else{ if ((x[i]-65+key)>=27 ){x[i] = x[i] - 26;}
x[i] = ((x[i]-65 + key)%26) +65;
i++;

}}}


void unencrypt(char*x,int key)
{int i = 0;
while (x[i] != '\0')
{ if(x[i] < 'A' || x[i] > 'Z') {
                    x[i] = x[i];
                    i++;
                    }else{
                        if ((x[i]-key-65)<=0){x[i] = x[i] + 26;}
x[i] = ((x[i]-65 - key)%26) +65;
i++;

}
}
}

/* #[^\n]S 

*/

void encryptsub(char*x)
{int i = 0;
int j = 0;
char* codealphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";
    while (x[i] != '\0')
            {if(x[i] < 'A' || x[i] > 'Z') {
                    x[i] = x[i];
                    x++;}
                    else{
                            j = x[i]-65;
                            x[i] = codealphabet[j];
                            
                            }
i++;}}


void decryptsub(char*x)
{int i=0;
int j = 0;
char* codealphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";
char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (x[i] != '\0')
        {if(x[i] < 'A' || x[i] > 'Z') 
                        {
                            x[i] = x[i];
                        i++;
                        }
                            else
                                { j=0;
                                    while(j < 26)
                                        {  if (x[i] ==  codealphabet[j])
                                                {
                                                x[i] = alphabet [j];
                                                
                                                break;
                                                
                                                }
                                                else j++;
                                    
                                            
                                        }
          
                            i++; }
                             
        }

}




