// Name - Harsh Dixit
// Roll no - 86691
// KD1-86691-Harsh

#include <stdio.h>
struct Date{
    // DATA MEMBERS
    int day;
    int month;
    int year;
};
    void acceptDate(struct Date *ptr)
    {
        printf("Enter day , month and year ");
        scanf("%d%d%d",&ptr->day,&ptr->month,&ptr->year);
    }

    void displayDate(struct Date *ptr)
    {
        printf("Time = %d  %d  %d",ptr->day,ptr->month,ptr->year);
    }
    
    void initDate(struct Date* ptr) 
	{
	    ptr->day = 1;
	    ptr->month = 1;
	    ptr->year = 2000;
    }

    int menu()
    {
        int choice;
        printf("\n0 for exit..\n");
        printf("1 for add date\n");
        printf("2 for display date\n");
        printf("3 for default date\n");
        printf("Enter your choice ");
        scanf("%d",&choice);
        return choice;
    }

int main()
{
    int choice;
    struct Date t1;
    while((choice = menu()) != 0)
    {
        switch (choice)
        {
            case 1:
                acceptDate(&t1);
                break;
            case 2:
                displayDate(&t1);
                break;
            case 3:
                initDate(&t1);
                displayDate(&t1);
                break;
            default:
                printf("Wrong choice...");
                break;
        }
    }  
    return 0;
}
