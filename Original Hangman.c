#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void generateWord(char guess[], char word[]);

void printLine(void);

void printAstrice(void);

char input(int life, int turn, char guessed[], int fault);

int check_letter(char first[], char last[], int sizeA, char character, int *counter);

void match(char character, char guess[], int counter);

void printGuess(char guess[]);

int checkIndicator(char last[], int size);

int mistake(int life, char guess[]);

void congratulate(char word[]);

void apologize(char word[], int life);

int main()
{
    int life=10; int turn=0; int fault=-1; int indicator=1; int endicator=4; int matching=0;
    char ch; int counter;
    char word[]="boxing"; int length=strlen(word);
    char guess[]="------";
    char guessed[26];


    printf("Guess the word.\nCategory=Sports\n");
    printLine();

    do
    {
        if(indicator==1)
        {
            turn++;
            ch=input(life, turn, guessed, fault);
            indicator=check_letter(word,guess,length,ch,&counter);
        }
        switch(indicator)
        {
            case 0:
                life=mistake(life, guess);
                fault+=1;
                guessed[fault]=ch;
                if(life<=0)
                    indicator=3;
                else
                    indicator=1;
                break;

            case 1:
                matching+=1;
                match(ch,guess,counter);
                printGuess(guess);
                indicator=checkIndicator(guess,strlen(word));
                break;

            case 2:
                congratulate(guess);
                indicator=4;
                break;

            case 3:
                apologize(word, life);
                indicator=4;
                break;

            default:
                printf("Sorry! There is a problem with the game. Technical Assistant is on the way.\n\n");
        }
    }while(indicator!=endicator);

    double efficiency=(double)matching/(double)turn;
    double eff=efficiency*100.0;

    printf("\nYour efficiency rate is %.2lf%%\n",eff);

    printLine();

    return(0);
}
int check_letter(char first[], char last[], int size, char character, int *counter)
{
    int count, counting;

    int indicator=0;

    for(count=0; count<size; count++)
    {
        if(character==first[count])
        {
            counting=count;
            first[count]='-';
            *counter=counting;
            indicator=1;
            break;
        }
    }
    return(indicator);
}
int checkIndicator(char last[], int size)
{
    int count; int indicatant=1;
    for(count=0; count<size; count++)
    {
        if(last[count]!='-')
            indicatant=2;
        else
        {
            indicatant=1;
            break;
        }
    }
    return(indicatant);
}
int mistake(int life, char guess[])
{
    int x;

    srand(time(NULL));
    x=(rand()%4);

    printf("%s", guess);
    switch(x)
    {
        case 0:
            printf("No luck, Keep going!\n");
            break;

        case 1:
            printf("\nOops, the letter did not match. Try again\n");
            break;

        case 2:
            printf("\nOuch! Come on. You can do better.\n");
            break;

        case 3:
            printf("\nSorry, Give it another shot.\n");
            break;

        default:
            printf("\nSomething went wrong in the gaming.\n");
    }
    printf("You lost a life.");

    printLine();
    printLine();

    life-=1;

    return(life);
}
char input(int life, int turn, char guessed[], int fault)
{
    char ch; int count;
    printAstrice();
    printf("    Life=%d     Turn=%d    ", life, turn);
    if(fault>=0)
    {
        printf("Guessed letters:");
        for(count=0; count<=fault; count++)
        {
            printf(" %c", guessed[count]);
        }
        printf("\n");
        printAstrice();
    }
    else
    {
        printf("Guessed Letters: None   \n");
        printAstrice();
    }

    printf("Guess a single letter: ");
    scanf(" %c", &ch);


    return(ch);
}
void congratulate(char guess[])
{
    printf("\nCongratulations! You have guessed the word correctly.\n\n");
    printf("%s\n",guess);
}
void apologize(char word[], int life)
{
    printf("Tough luck, friend. You were hanged!\nLife=%d\n", life);
}
void match(char character, char guess[], int counter)
{
    guess[counter]=character;
}
void printLine(void)
{
    printf("\n______________________________________________________________\n");
}
void printAstrice(void)
{
    printf("***************************************************************\n");
}
void printGuess(char guess[])
{
    printf("You have guessed the letter correctly!\n");
    printf("\n%s",guess);
    printLine();
    printLine();
}
