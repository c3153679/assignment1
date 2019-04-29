/******************************************************************************************************************************************************************/
/*Name: Patrick Shaw        Student #c3153679                 Assignment 1 engg1003*/
/*Description: This program will encrypt and decrypt code in both ceaser and substitution styles. */
/* input message and key for caeser cypher will be taken from user via scan function */
/* input message for substitution cypher will be taken via scan function, key is hard coded in 'encryptsub' function and will require maniplulation in code.*/
/* program can input/output sentences, words or individual letters as required */
/******************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void encrypt (char*x, int key);
void unencrypt (char*x, int key);
void unencryptall (char*x);
void encryptsub (char*x);
void decryptsub (char*x);
int main()
{
   // declare char message for encoding//
   
   char message[100000];
   int key;      // rotation value cipher key//
   int i = 0;    //loop counter//
   int p = 0;    //switch case integer//
   
               
   printf("enter a message you want to have encrypted\n"); //prompt user for message to be (de)encrypted //
   scanf("%[^\n]", message);                               //stores message untill null values//
   for (i = 0; message[i]!='\0'; i++)                      //prior to any manipulation all values converted to uppercase via ascii numbers//
                    {
                    if(message[i] >= 'a' && message[i] <= 'z') {
                    message[i] = message[i] -32;
                    }else message[i] = message[i];
                    }
   printf("Please enter number associated with task you want completed.\n1-- encrypt using caeser cipher\n2-- decrypt using caeser cypher\n3-- encrypt using substitution\n4-- decrypt using subsitution\n\n"); //prompt user for switch case input-- function menu//
   scanf("%d",&p);   // scan switch case ineger//
   switch(p){        // switch case takes user input and initialises 1 of 4 functions with a default error if invalid input is made
   case 1:
            printf("please enter the encryption key\n""enter number between 0 & 25\n");   //prompt user for the code key//
            scanf("%d",&key);
    
            printf("input message: %s\n", message);       
            encrypt (message, key);                                                     // initialise encrypt caeser function//
            printf("encrypted message: %s\n", message);
            break;                                                                      //task completed, break program//
            
    case 2:
            printf("please enter the encryption key\n""enter number between 0 & 25\n");
            scanf("%d",&key);
            unencrypt(message, key);                                                     // initialise decrypt caeser function//
            printf("unncrypted message: %s\n", message);
            break;
            
            
    case 3:
            encryptsub(message);                                                         // initialise encrypt substitution function//
            printf("substitution encrypted message: %s\n", message);
            break;
    case 4:
            decryptsub(message);                                                        // initialise decrypt substitution function//
            printf("substitution decrypted message: %s\n", message);
            
    
            default: printf("invalid entry %d \n", p);                                      
            break;
            
}
    
}

void encrypt(char*x,int key)
{int i = 0;                            
while (x[i] != '\0')               //reads until no null value//
{ if(x[i] <'A' || x[i] >'Z') {     //all values are already uppercase therefore any other value (space, punctuation) will remain unaltered in code//
                    x[i] = x[i];
                    i++;
                    }
                    else{ if ((x[i]-65+key)>=27 ){x[i] = x[i] - 26;}       //if values are too high then this will 'wrap around' the alphabet. i.e x>y>z>a>b//
x[i] = ((x[i]-65 + key)%26) +65;                                           // encryption statement, takes  value and adds key value//
i++;

}}}


void unencrypt(char*x,int key)
{int i = 0;
while (x[i] != '\0')                        //reads until no null value//
{ if(x[i] < 'A' || x[i] > 'Z') {            //all values are already uppercase therefore any other value (space, punctuation) will remain unaltered in code//
                    x[i] = x[i];
                    i++;
                    }else{
                        if ((x[i]-key-65)<=0){x[i] = x[i] + 26;}        //if values are too low then this will 'wrap around' the alphabet. i.e x>y>z>a>b//
x[i] = ((x[i]-65 - key)%26) +65;                                        //decryption statement, takes  value and adds key value//
i++;

}
}
}



void encryptsub(char*x)
{int i = 0;
int j = 0; 
                    
                    
            //*******CHANGE CODE BELOW IF REQUIRED*****//
char* codealphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";           //code key for substitution//
    while (x[i] != '\0')
            {if(x[i] < 'A' || x[i] > 'Z') {
                    x[i] = x[i];
                    x++;}
                    else{
                            j = x[i]-65;         // converts letter to numerical value//
                            x[i] = codealphabet[j]; //assigns numerical value to place in code alphabet//
                            
                            }
i++;}}


void decryptsub(char*x)
{int i=0;
int j = 0;
            //*******CHANGE CODE BELOW IF REQUIRED*****//
char* codealphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";
char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (x[i] != '\0')
        {if(x[i] < 'A' || x[i] > 'Z') 
                        {
                            x[i] = x[i];
                        i++;
                        }
                            else
                                { j=0;   //
                                    while(j < 26)
                                        {  if (x[i] ==  codealphabet[j])       //checks each char value against code alphabet to find match//
                                                {
                                                x[i] = alphabet [j];          // if match is found then assigns numerical value to alphabet to decode//
                                                
                                                break;
                                                
                                                }
                                                else j++;
                                    
                                            
                                        }
          
                            i++; }
                             
        }

}





