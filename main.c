#include <stdio.h>
#include <stdlib.h>
#define PARAM 100000
#define BLANK -5
#define STATS 1

void atoiChar(char entered[PARAM],int enteredNumerical[PARAM])
{
    for(int i=0;i<PARAM;i++)
    {
        if(entered[i]=='0') enteredNumerical[i]=0;
        else if(entered[i]=='1') enteredNumerical[i]=1;
        else if(entered[i]=='2') enteredNumerical[i]=2;
        else if(entered[i]=='3') enteredNumerical[i]=3;
        else if(entered[i]=='4') enteredNumerical[i]=4;
        else if(entered[i]=='5') enteredNumerical[i]=5;
        else if(entered[i]=='6') enteredNumerical[i]=6;
        else if(entered[i]=='7') enteredNumerical[i]=7;
        else if(entered[i]=='8') enteredNumerical[i]=8;
        else if(entered[i]=='9') enteredNumerical[i]=9;
        else enteredNumerical[i]=BLANK;
    }

}

void clr()
{
    for(int clr=0;clr<200;clr++)
    printf("\n");
}


void entering(char entered[PARAM],int num1[PARAM])
{
    char c;
    int j=0;
    int numerical[PARAM];

    for(int i=0;i<PARAM;i++)
    {
        entered[i]=BLANK;
        num1[i]=BLANK;
    }

    while((c=getchar())!='\n')
    {
        entered[j]=c;
        j++;
    }
    //entered[j]='\0';

    atoiChar(entered,numerical);
/*
    for(int i=0;i<PARAM;i++)
    {
        printf("%d",numerical[i]);
    }


    printf("\n");*/

    for(int i=PARAM-1;i>=0;i--)
    {
        if(j>0)
        {
            num1[i]=numerical[j-1];
            j--;
        }
    }
/*
    for(int i=0;i<PARAM;i++)
    {
        printf("%d",num1[i]);
    }

    printf("\n");*/
}

void swValue(int num1[PARAM],int num2[PARAM])
{
    int j=0;
    for(int i=0;i<PARAM;i++)
    {
        if(num1[i]!=BLANK)
        {
            num2[PARAM-1-j]=num1[i];
            j++;
        }
    }

    /*printf("\n");
    for(int i=0;i<PARAM;i++)
        printf("%d",num2[i]);*/

}

int arithemtics(int num1[PARAM],int num2[PARAM])
{
    int len=0;



    for(int i=(PARAM-1);num1[i]>=0 && num1[i]<=9;i--)
        len++;

    //printf("\nLen: %d\n",len);


    for(int i=PARAM-1;i>=0;i--)
    {
        num1[i]=num1[i]+num2[i];

        if(num1[i]>9)
        {
            num1[i]-=10;
            if(num1[i-1]<0)
            {
                //printf(" %d->",num1[i-1]);
                num1[i-1]=1;
                num2[i-1]=0;
                len++;
                //printf("%d ",num1[i-1]);
            }
            else
            {
                //printf(" %d->",num1[i-1]);
                num1[i-1]+=1;
                //printf("%d ",num1[i-1]);
            }
        }

    }


    for(int i=0;num1[i]<1;i++)
    {
        num1[i]=BLANK;
    }

/* printf("\n");


    for(int i=0;i<PARAM;i++)
    if(num1[i]!=-5)
        printf("%d",num1[i]);*/



    return len;
}

int main()
{

    char entered[PARAM];
    int num1[PARAM];
    int num2[PARAM];
    char g='1';
    int len=0;
    int sameness=0;
    double percentage=0;
    double maxPercentage=0;
    int maxP[PARAM];

    for(int i=0;i<PARAM;i++)
        maxP[i]=BLANK;

    while(g=='1')
    {
        int repetitions=0;
        int paliCount=0;

        for(int i=0;i<PARAM;i++)
            num2[i]=BLANK;

        clr();
        printf("Type your number: ");
        entering(entered,num1);

        clr();
        printf("How many repetitions do you want to search: ");
        scanf("%d",&repetitions);

        clr();
        for(int m=0;m<PARAM;m++)
            if(num1[m]!=-5)
            {
                printf("%d",num1[m]);
                len++;
            }

        for(int j=0;j<len/2;j++)
            {
                if(num1[PARAM-len+j]==num1[PARAM-1-j])
                    sameness++;
            }
            if(sameness==len/2)
            {
                printf(" - YOUR ENTERED NUMBER IS ALREADY A PALINDROME\n");
                paliCount++;
            }
            else
                printf("\n");



        for(int i=0;i<repetitions;i++)
        {
            sameness=0;
            len=0;
            percentage=0;
            swValue(num1,num2);
            len=arithemtics(num1,num2);

            for(int j=0;j<PARAM;j++)
                if(num1[j]!=BLANK)
                {
                    printf("%d",num1[j]);
                }
            for(int j=0;j<len/2;j++)
            {
                if(num1[PARAM-len+j]==num1[PARAM-1-j])
                    sameness++;
            }
            if(sameness==len/2)
            {
                printf(" - palindrome\n");
                paliCount++;
            }
            else
                printf("\n");

            if(STATS==1)
            {
                if(len%2==0)
                {
                    percentage=(sameness/((float)len/2))*100;
                    printf("%.2f%% is similar\n\n",percentage);
                }
                else
                {
                    percentage=((sameness+1)/(((float)len+1)/2))*100;
                    printf("%.2f%% is similar\n\n",percentage);
                }

                if(percentage>=maxPercentage)
                {
                    maxPercentage=percentage;
                    for(int e=0;e<PARAM;e++)
                        maxP[e]=num1[e];
                }
            }
        }

        printf("\n\nNumber of palindromes found: %d",paliCount);
        if(STATS==1)
        {
            printf("\nThe longest palindrome or with most accuracy is:\n");
            for(int q=0;q<PARAM;q++)
                if(maxP[q]!=BLANK)
                    printf("%d",maxP[q]);
                printf("\n%.2f%% accuracy\n",maxPercentage);
        }
        printf("\n\nWanna try again? 1-yes 0-no\n\n");
        while((g=getchar())!='1' && g!='0')
        {}
        getchar();
        clr();
    }

    printf("Thank you for using my software ^^\n\nInspired by Vsauce2 video CHECK HIS CHANNEL OUT!\n\n\n\nMade byt RUKASU\n\n\n");
    system("start https://www.youtube.com/watch?v=7RSqBuZzthk");

    //for(int i=0;i<X;i++)

    //printf("%d",j);
    return 0;
}
