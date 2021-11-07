#include <stdio.h>
#include <stdlib.h>
#define PARAM 100000
#define BLANK -5

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
    int ari=0;
    int temp[PARAM];

    for(int i=0;i<PARAM;i++)
        temp[i]=0;

    for(int i=(PARAM-1);num1[i]>=0 && num1[i]<=9;i--)
        len++;

    //printf("\nLen: %d\n",len);


    for(int i=PARAM-1;i>=0;i--)
    {
        ari=0;
        if(num1[i]+num2[i]+temp[i]>9)
            ari=1;

        //printf("\n%d    %d+%d(+%d)=%d",i,num1[i],num2[i],temp[i],num1[i]+num2[i]+temp[i]);

        if(ari==0/* && num1[i]!=BLANK*/)
            num1[i]=num1[i]+num2[i]+temp[i];
        else if(ari==1)
        {
            num1[i]=num1[i]+num2[i]-10+temp[i];
            temp[i-1]=1;
        }

    }


    for(int i=0;num1[i]<1;i++)
    {
        if(num1[i]>-10)
        {
            num1[i]=1;
            len++;
        }
        else if(num1[i]==-10)
            num1[i]=BLANK;
    }

   // printf("\n");


   // for(int i=0;i<PARAM;i++)
     //   printf("%d",num1[i]);


    return len;
}

int main()
{

    char entered[PARAM];
    int num1[PARAM];
    int num2[PARAM];
    char g='1';

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

        for(int i=0;i<repetitions;i++)
        {
            int sameness=0;
            int len=0;
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
        }

        printf("\n\nNumber of palindromes found: %d\n\nWanna try again? 1-yes 0-no\n\n",paliCount);
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



//1848942894949849498419941988498464646436783848649846984
