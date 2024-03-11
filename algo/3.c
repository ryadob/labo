#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct clients
{
    int id;
    char name[30], first_name[30], address[100], tel[15];
    Date date_of_birth;
} clients;

typedef struct account
{
    int client_id, balance;
    char account_type;
    bool blocked;
} account;

typedef struct new_clients
{
    int new_id;
    int balance ;
} new_clients;

int the_Age(Date b) {
    time_t t = time(NULL);
    struct tm y = *localtime(&t);
    int age = y.tm_year + 1900;
    return age - b.year;
}

void create_account(clients *s, account *a)
{
    printf("please enter the next information : \n");

    printf("Enter your ID : ");
    scanf("%d", &s->id);
    getchar();
    printf("Enter your name : ");
    fgets(s->name, 30, stdin);
    printf("Enter your first name : ");
    fgets(s->first_name, 30, stdin);
    printf("Enter your address : ");
    fgets(s->address, 50, stdin);
    printf("Enter your phone number : ");
    scanf("%s", s->tel);
    printf("Enter your date of birth (dd mm yyyy) : ");
    scanf("%d %d %d", &s->date_of_birth.day, &s->date_of_birth.month, &s->date_of_birth.year);

    printf("Enter account type ( p / m / c) : ");
    scanf(" %c", &a->account_type);
    if (a->account_type == 'p' && the_Age(s->date_of_birth) < 18)
    {
        printf("The client must be 18 years or older\n");
        return;
    }
    else if (a->account_type == 'm' )
    {
        int answer;
        printf("Does your guardian have an account in this bank?\n1. yes\n2. no\n Please enter you answer: ");
        scanf("%d", &answer);
        if(answer == 2)
        {
            printf("You can't create account\n");
            return;
        }
    }
    else if (a->account_type == 'c')
    {
        return;
    }
    a->client_id = 20202020; // Fixed client ID
    a->balance = 10000; // Fixed balance
    a->blocked = false;
    printf("\nAccount created successfully!\n");
}

void deposit(account *a, new_clients *f) {
    int amount ;
    a->balance = 10000;
    printf("Enter your id: ");
    scanf("%d", &f->new_id) ;
    if (f->new_id == 20202020){
    printf ("Enter the amount you want to deposit : ");
    scanf("%d", &amount) ;
    a->balance += amount;
    printf("Deposit successful. Your new balance is %d.\n", a->balance);
}else{
    printf("The id is incorrect\n");
}
}

void transfer(account *a , new_clients *f) {
    int amount , new_acount ;
    a->balance = 10000;
    printf("Enter your id: ");
    scanf("%d", &f->new_id) ;
    if (f->new_id == 20202020){
        printf("Enter the ID of the account you want to transfer to: ");
        scanf("%d", &new_acount) ;
        printf("Enter the amount you want to transfer: ");
        scanf("%d", &amount) ;
        if (a->balance < amount) {
            printf("Insufficient balance.\n");
            return;
        }
    } else {    
        printf("The id is incorrect\n");
        return;
    }
    a->balance -= amount;
    f->balance += amount;
    printf("Transfer successful. Your new balance is %d.\n", a->balance);
}

void withdrawal(account *a , new_clients *f ) {
    int amount ; 
    printf("Enter your id: ");
    scanf("%d", &f->new_id) ;
    if (f->new_id == 20202020){
        printf("Enter the amount you want to withdraw: ");
        scanf("%d", &amount) ;
        if (a->balance < amount) {
            printf("Your account balance is insufficient.\n");
            return;
        }
        a->balance -= amount;
        printf("Withdrawal successful. Your new balance is %d.\n", a->balance);
    } else {
        printf("The id is incorrect\n");
        return;
    }
}

void modify_account_type(account *a , new_clients *f) {
    printf("Enter your id: ");
    scanf("%d", &f->new_id) ;
    if (f->new_id == 20202020){
        printf("Enter the type you want to convert your account to: ");
        scanf(" %c", &a->account_type);
        printf("Account type modified successfully.\n");
    } else {
        printf("The id is incorrect\n");
    }
}

void account_inquiry(account *a) {
    a->client_id = 20202020;
    a->account_type = 'p';
    a->balance =10000;
    printf("Account ID: %d\n", a->client_id);
    printf("Account Type: %c\n", a->account_type);
    printf("Balance: %d\n", a->balance);
    printf("Account Status: Active\n" );
}

int main()
{
    clients s;
    account a;
    new_clients f;
    account b = {0}; // Initialize 'b' to zero

    while (1)
    {
        int x;
        printf("1. Create account\n2. Deposit\n3. Transfer\n4. Withdrawal\n5. Modify Account Type\n6. Account Inquiry\n7. Exit\n Please enter you choice: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            create_account(&s, &a);
            break;
        case 2:
            deposit(&a, &f);
            break;
        case 3:
            transfer(&a, &f);
            break;
        case 4:
            withdrawal(&a, &f);
            break;
        case 5:
            modify_account_type(&a, &f);
            break;
        case 6:
            account_inquiry(&a);
            break;
        case 7:
            return 0;
        }
    }
}
