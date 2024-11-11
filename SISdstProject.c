#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create();
void display();
void deleted();
void update();
void searchfname();

struct node {
    char fname[100];
    char lname[100];
    char course[100];
    float grade;
    struct node *next;
} *start = NULL, *ptr, *newnode, *pre;

int main() {
    int ch;
    printf("**STUDENT INFORMATION SYSTEM**\n");
    while (1) {
        printf("\nEnter :\n\n1.To ADD     Student Details\n2.To DISPLAY and SAVE Student Details\n3.To DELETE  Student Details\n4.To UPDATE  Student Details \n5.To SEARCH  Student Details \n6.To EXIT \n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                deleted();
                break;
            case 4:
                update();
                break;
            case 5:
                searchfname();
                break;
            case 6:
                 exit(0);
            default:
                printf("\nEnter a valid choice\n");
                
        }
    }
    return 0;
}

void create() 
{
    newnode = malloc(sizeof(struct node));
    printf("\nEnter Student's first Name: ");
    scanf("%s", newnode->fname);
    printf("\nEnter Students's second Name: ");
    scanf("%s", newnode->lname);
    printf("\nEnter Course Code: ");
    scanf("%s", newnode->course);
    printf("\nEnter the Students Grade: ");
    scanf("%f", &newnode->grade);
    if (start == NULL) 
	{
        start = newnode;
        newnode->next = NULL;
        printf("\nStudent Data Entered Successfully\n");
    }
	else 
	{
        ptr = start;
        while (ptr->next != NULL) 
		{
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = NULL;
        printf("\nStudent Data Entered Successfully\n");
    }
}

void display() {
    FILE *file = fopen("student data.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    if (start == NULL) {
        printf("\nStudent's List is Empty\n");                                                                          //@isp
        fprintf(file, "Student's List is Empty\n");
    } else {
        ptr = start;
        printf("\nFIRST_NAME\tLAST_NAME\tCOURSE\t\tGRADE\n");
        fprintf(file, "FIRST_NAME,LAST_NAME,COURSE,GRADE\n");
        while (ptr != NULL) {
            printf("\n%s\t", ptr->fname);
            printf("\t%s\t", ptr->lname);
            printf("\t%s\t", ptr->course);
            printf("\t%f\t\n", ptr->grade);
            fprintf(file, "%s,%s,%s,%.2f\n", ptr->fname, ptr->lname, ptr->course, ptr->grade);
            ptr = ptr->next;
        }
    }

    fclose(file);
    printf("Data saved to student data.txt file.\n");
}

void deleted() {
    char findFname[100];
    int found = 0;
    if (start == NULL) {
        printf("\nNo data to delete\n");
        return;
    }
    printf("\nEnter First Name to Delete: ");
    scanf("%s", findFname);
    ptr = start;
    if (strcmp(ptr->fname, findFname) == 0) {
        start = start->next;
        free(ptr);
        printf("\nStudent Data Successfully Deleted\n");
        return;
    }
    while (ptr->next != NULL) {
        if (strcmp(ptr->next->fname, findFname) == 0) {
            found = 1;
            pre = ptr->next;
            ptr->next = ptr->next->next;
            free(pre);
            printf("\nStudent Data Successfully Deleted\n");
            return;
        }
        ptr = ptr->next;
    }
    if (found == 0) {
        printf("\nStudent Not Found\n");
    }
}
void update() {
    char findFname[100];
    int found = 0;
    if (start == NULL) {
        printf("\nNo data to update\n");
        return;
    }
    printf("\nEnter First Name to Update: ");
    scanf("%s", findFname);
    ptr = start;
    while (ptr != NULL) {
        if (strcmp(ptr->fname, findFname) == 0) {
            found = 1;
            newnode = malloc(sizeof(struct node));
            printf("\nEnter Data To UPDATE\n");
            printf("\nEnter Student's first Name: ");
            scanf("%s", newnode->fname);
            printf("\nEnter Students's second Name: ");
            scanf("%s", newnode->lname);
            printf("\nEnter Course Code: ");
            scanf("%s", newnode->course);
            printf("\nEnter the Students Grade: ");
            scanf("%f", &newnode->grade);
            newnode->next = ptr->next;
            if (ptr == start) {
                start = newnode;
            } else {
                pre->next = newnode;
            }
            free(ptr);
            printf("\nStudent Details UPDATED Successfully\n");
            return;
        }
        pre = ptr;
        ptr = ptr->next;
    }
    if (found == 0) {
        printf("\nStudent Not Found\n");
    }
}

void searchfname() {
    char findfname[100];
    int found = 0;
    if(start == NULL) {
        printf("\nNo data to search\n");
    }
    else{
	
    printf("Enter First Name To Search: ");
    scanf("%s", findfname);
    ptr = start;
    while (ptr != NULL) 
	{
        if (strcmp(ptr->fname, findfname) == 0) 
		{
            if (found == 0) 
			{
                printf("\nSTUDENTS DATA FOUND BY FIRST NAME\n");
                printf("\nFIRST_NAME\tLAST_NAME\tCOURSE\t\tGRADE\n");
                found = 1;
            }
            printf("\n%s\t", ptr->fname);
            printf("\t%s\t", ptr->lname);
            printf("\t%s\t", ptr->course);
            printf("\t%f\t\n", ptr->grade);
        }
        ptr = ptr->next;
    }
    if (found == 0) {
        printf("\nSTUDENT DATA NOT FOUND BY FIRST NAME\n");
    }
}
}