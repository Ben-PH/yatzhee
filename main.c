#include <stdio.h>
#include <string.h>
#include<stdbool.h>

#define DICE_SIZE 20
char Dice[DICE_SIZE] = {0};
void selsort(char Dice[]);
int psmallStraight(char Dice[]);
int check;
void rollDice(char Dice[])
{
    printf("Please enter the dice values: \n> ");
    fgets(Dice, DICE_SIZE, stdin);
    Dice[strlen(Dice) - 1] = '\0';

}

bool errorCheck(const char Dice[])
{
    for (int i = 0, length = strlen(Dice); i < length; ++i)
    {
        if (i % 2 != 0 && Dice[i] != ' ')
        {
            printf("Incorrect Input Format.");
            return false;
        }
        else if (i % 2 == 0 && (Dice[i] < '0' || Dice[i] > '6'))
        {
            printf("Value Out of Range.");
            return false;
        }
        else if (i > 8)
        {
            printf("Incorrect Number of Values.");
            return false;
        }
    }

    return true;
}
void keepDice(char Dice[])
{
    int count_1=0;
    int count_2=0;
    int count_3=0;
    int count_4=0;
    int count_5=0;
    int count_6=0;

    for(int i = 0; i<strlen(Dice); i++)
    {
        if(Dice[i]=='1')
        {
            count_1++;
        }
        else if(Dice[i]=='2')
        {
            count_2++;
        }
        else if(Dice[i]=='3')
        {
            count_3++;
        }
        else if(Dice[i]=='4')
        {
            count_4++;
        }
        else if(Dice[i]=='5')
        {
            count_5++;
        }
        else if(Dice[i]=='6')
        {
            count_6++;
        }
    }

    int score;
    void threeOfAKind()
    {
        score=(Dice[0]-'0')+(Dice[2]-'0')+(Dice[4]-'0')+(Dice[6]-'0')+(Dice[8]-'0');
    }
    void fourOfAKind()
    {
        score=(Dice[0]-'0')+(Dice[2]-'0')+(Dice[4]-'0')+(Dice[6]-'0')+(Dice[8]-'0');
    }
    void fullHouse()
    {
        score=25;
    }
    void smallStraight()
    {
        score=30;
    }
    void straight()
    {
        score=40;
    }
    void yahtzee()
    {
        score=50;
    }
    void chance()
    {
        score=((Dice[0]-'0')+(Dice[2]-'0')+(Dice[4]-'0')+(Dice[6]-'0')+(Dice[8]-'0'));
        return score;
    }
    int input;
    if(count_1==5||count_2==5||count_3==5||count_4==5||count_5==5||count_6==5)
    {
        printf("you have the following options\n");
        printf("1 -> yahtzee\n2->chance\n3 -> three of a kind\n4->four of a kind\n");
        scanf("%d",&input);
        if(input==1)
        {
            yahtzee();
            printf("your score is %d",score);
        }
        if(input==2)
        {
            chance();
            printf("your score is %d",score);
        }
        if(input==3)
        {
            threeOfAKind();
            printf("your score is %d",score);
        }
        if(input==4)
        {
            fourOfAKind();
            printf("your score is %d",score);
        }
    }
    else if(count_1==1 && count_2==1 &&count_3==1 &&count_4==1 &&count_5==1 && count_6==1)
    {
        printf("you have the following options\n");
        printf("1 -> straight\n2->small straight\n3 -> chance\n");
        scanf("%d",&input);
        if(input==1)
        {
            straight();
            printf("your score is %d",score);
        }
        if(input==2)
        {
            smallStraight();
            printf("your score is %d",score);
        }
        if(input==3)
        {
            chance();
            printf("your score is %d",score);
        }
    }
    else if(check==0)
    {
        printf("you have the following options\n");
        printf("1->small straight\n2->chance\n");
        scanf("%d",&input);
        if(input==1)
        {
            smallStraight();
            printf("your score is %d",score);
        }

        if(input==2)
        {
            chance();
            printf("your score is %d",score);
        }




    }
}


































void displayOptions(char Dice[])
{
    float userInput = 0.0;
    printf("\n1 -> Reroll some dice\n");
    printf("2 -> Reroll all dice\n");
    printf("3 -> keep dice\n> ");
    scanf("%f",&userInput);
    if(userInput == 1 || userInput == 2 || userInput == 3)
    {
        switch((int)userInput)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            keepDice(Dice);
            break;
        }

    }
    else
    {
        printf("invalid choice");
    }

}

int main()
{
    char Dice[DICE_SIZE] = {0};
    rollDice(Dice);
    if(errorCheck(Dice))
    {
        displayOptions(Dice);
    }
}

void selsort(char Dice[])
{
    int i, j, min, temp;
    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i + 1; j < 5; j++)
        {
            if (Dice[j] < Dice[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = Dice[i];
            Dice[i] = Dice[min];
            Dice[min] = temp;
        }

    }
}
int psmallStraight(char Dice[])
{
    selsort(Dice);
    for(int i=0; i<5; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            if(Dice[j]=Dice[i]+1)
            {
                if(Dice[j]=Dice[i]+2)
                {
                    if(Dice[j]=Dice[i]+3)
                    {
                        check=1;
                        return check;
                        break;

                    }
                }



            }
        }
    }
    check=0;
    return check;
}











