#include <stdio.h>
#include <stdlib.h>


void create_an_account(int *accno, char name[], float *balance);
void credit_an_amount(float *alance);
void debit(float *balance);
void balance_check(float balance);
void display(int accno, char name[100], float balance)
{
    printf("\n\n\n ACCOUNT STATEMENT. .. . .");
    printf(" \n Account Number %d", accno);
    printf(" \n Name %s", name);
    printf(" \n Balance %f", balance);
}
void main()
{

    int accno;
    char name[100];
    float amt, balance;
    int opt;
    create_an_account(&accno, name, &balance);

    while (1)
    {
        printf("\nl.Credit an amount ");
        printf("\n2.Debit from an amount");
        printf("\n3. Balance Checking");
        printf(" \n4. Display the Statement");
        printf("\n5. Exit");
        printf(" \nEnter the option. ..");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            credit_an_amount(&balance);
            break;
        case 2:
            debit(&balance);
            break;
        case 3:
            balance_check(balance);
            break;
        case 4:
            display(accno, name, balance);
            break;
        case 5:
            exit(0);
        }
        printf("\n\nPress Enter to Continue. . ");
    }
}

void create_an_account(int *accno, char name[], float *balance)
{
    int ano;
    float amt;
    printf("\nCREATE AN ACCOUNT");
    printf(" \nAccount No. : ");
    scanf("%d", &ano);
    fflush(stdin);

    printf("Name");
    gets(name);
    printf("Initial deposit Value. e. (Minimum 500) ");
    scanf("%f", &amt);
    *accno = ano;
    *balance = amt;
}
void credit_an_amount(float *balance)
{

    float amt;
    printf("\n Enter the amount to  be credit");
    scanf("%f", &amt);
    *balance = *balance + amt;
    printf("\nCurrent Balance :%f", *balance);
}
void debit(float *balance)
{
    float amt;
    if (*balance <= 500)
    {
        printf(" \n Need to Maintain minimum Balance. .");
        printf(" \n nable to Process..");
        return;
    }
    printf(" \nEnter the Amount to be Debited. . .");
    scanf("%f", &amt);
    *balance = *balance - amt;
    printf(" \nCurrent Balance :f", *balance);
}
void balance_check(float balance)
{
    printf("Current Balance %f", balance);
}


