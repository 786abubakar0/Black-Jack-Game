#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));

    /*******************************************************--variables--*******************************************************/
    int p1,p2,ptotal;        //variables for player sides
    int d1,d2,dtotal;        //variables for dealer sides
    char* choice[20];       //to store input
    char* compare="hit";    //for comparing with input

    p1=2+(rand()%10);   //generating 1st random 2-11 for player
    p2=2+(rand()%10);   //generating 2nd random 2-11 for player
    ptotal=p1+p2;       //calculate player numbers
    d1=2+(rand()%10);   //generating 1st random 2-11 for dealer
    d2=2+(rand()%10);   ////generating 2nd random 2-11 for dealer
    dtotal=d1+d2;
    /*******************************************************--START--*******************************************************/
    printf("Welcome to simple blackjack program!\n");                   //display statement
    printf("You get a %d and a %d.\n",p1,p2);                           //display random numbers for player
    printf("Your total is %d.\n\n",ptotal);                             //display player total
    printf("The dealer has a %d showing, and a hidden card.\n",d1);     //display 1 card of dealer
    printf("His total is hidden, too.\n\n");                            //display statement
                /****************************************--Player--****************************************/
    while(ptotal<=21) //when total is less than 22 that is not bursting
    {
        printf("Would you like to \"hit\" or \"stay\"?");   //asking player for hit or stay
        scanf("%s",&choice);

        if(strcmp(choice,compare)==0)   //if choice is hit then executing
        {
            p1=2+(rand()%10);
            printf("\nYou drew a %d.\n",p1);
            ptotal=ptotal+p1;
            printf("Your total is %d.\n\n",ptotal);
        }
        else                                //if not hitting then going out of while loop
           break;
    }

    if(ptotal>21)                      //if player bursts then executing
    {
        printf("Burst\n\n");
        printf("YOU LOSS!\n");
        goto skip;                    //jump to end
    }
                /****************************************--Dealer--****************************************/

    else                                    //player does not burst then executing
    {
        printf("Okay, dealer's turn.\n");
        printf("His hidden card was a %d.\n",d2);    //showing hidden card
        printf("His total was %d.\n\n",dtotal);      //displaying total of dealer

        if(dtotal>21)       //dealer bursts in first drawing then executing
        {
            printf("Burst\n\n");
            printf("YOU WIN!");
            goto skip;      //jump to end
        }
        else                    //dealer does not burst in first drawing then executing
        {
            while(dtotal<16)        //dealer should probably hit on 16 or less
            {
                d1=2+(rand()%10);
                printf("\nDealer chooses to hit.\n");
                printf("He draws a %d.\n",d1);
                dtotal=dtotal+d1;
                printf("His total is %d.",dtotal);
                if(dtotal>21)   //if dealer bursts then executing
                {
                    printf("\nBurst\n\n");
                    printf("YOU WIN!\n");
                    goto skip;      //jump to end
                }
            }
             /****************************************--End of game--****************************************/
            printf("\nDealer stays.\n\n");
            printf("Dealer total is %d.\n",dtotal);
            printf("Your total is %d.\n",ptotal);

            if(dtotal>=ptotal)
                printf("YOU LOSS!\n");
            else
                printf("YOU WIN!\n");


        }
    }
    skip:;
   /*******************************************************--STOP--*******************************************************/
    system("pause");
    return 0;
}
