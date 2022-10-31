#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
//δομή η οποία είναι κόμβος της συνδεμένης που  περιέχει τα δεδομένα
//και τον δείκτη που δείχνει στην διεύθυνση του επόμενου κόμβου της συνδεμένης λίστας
struct node
{
    int element;
    struct node *next;
};
//δείκτης ο οποίος δέιχνει την αρχή(κεφαλή) της συνδεμένης λίστας
struct node *head;

int main()
{
    int selected;
 //Φτιάχνω ένα μενoύ επιλογών για το χρήστη
    do
    {
        printf("1:Insert\n2:Display\n3:Delete\n4:Exit\n");
        printf("Enter your selection: \n");
        scanf("%d",&selected);

        switch (selected)


        {
            case 1:
                push();
                break;
            case 2:
                display();
                break;
            case 3:
                pop();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    }while (selected!=4);
    return 0;
}

//Φτιάχνω μία συνάρτηση που θα εισάγει στη συνδεμένη λίστα το στοιχείο που της δίνει ο χρήστης
void push(){
    int element;
    struct node *pointer=(struct node*)malloc(sizeof(struct node));
    
        printf("Enter element: \n");
        scanf("%d",&element);
        if (head==NULL)
        {
            pointer->element=element;
            pointer->next=NULL;
            head=pointer;
        }
        else{
            pointer->element=element;
            pointer->next=head;
            head=pointer;
        }
}
//Φτιάχνω μία συνάρτηση που θα διαγράφει το στοιχείο της κορυφής της συνδεμένης λίστας
void pop(){
    int item;
    struct node *pointer;
    if (head==NULL)
    {
        printf("stack underflow\n");
    }
    else{
        item=head->element;
        pointer=head;
        head=head->next;
        free(pointer);
        printf("the deleted element is %d\n",item);
    }
}
//Φτιάχνω μία συνάρτηση που τυπώνει όλα τα στοιχέια της συνδεμένης λίστας
void display(){

    struct node *pointer;
    pointer=head;
    if(pointer==NULL)
    {
        printf("stack underflow\n");
    }
    else{
        printf("The elements are:\n ");
        while(pointer!=NULL)
        {
            printf("%d\n",pointer->element);
            pointer=pointer->next;
        }
    }
}