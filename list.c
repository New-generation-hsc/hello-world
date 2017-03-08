#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30
#define BOOL int

struct node
{
	char username[SIZE];
	char password[SIZE];

	struct node *next;
};

/*
struct list{
	struct node element;
	struct list *next;
}
 */
//void create(char []username[])
struct node* create(struct node* head, char *username, char *password){

	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	strcpy(new_node->username, username); //copy from username
	strcpy(new_node->password, password);
	new_node->next = NULL;

	if(head == NULL){
		head = new_node;
	}
	else{
		struct node *temp = head;
		while(temp->next!=NULL) // stop in the last node
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
	return head;
}


struct node* search(struct node* head, char *username){

	if(head == NULL) return NULL;
	struct node *temp = head;
	while(temp!=NULL)
	{
		if(strcmp(temp->username, username) == 0)
			return temp;
		temp = temp->next;
	}
	return NULL; // search fail
}


struct node* update(struct node* head, char *username){

	char password[SIZE];
	struct node *temp = head;
	while(temp!=NULL)
	{
		if(strcmp(temp->username, username) == 0)
		{
			printf("please enter your new password: ");
			scanf("%s", password);
			strcpy(temp->password, password);
		}
		temp = temp->next;
	}


	return head;
}

struct node* destroy(struct node *head, char *username){

	struct node *temp = head;
	struct node *previous = NULL;
	struct node *current = head;

	if(head == NULL) return head;

	if(strcmp(head->username, username) == 0){
		struct node *temp = head->next;
		free(head);
		head = temp;
		return head;
	}

	
	while(current!=NULL){
		if(strcmp(current->username, username) == 0)
		{
			temp = current;
			previous->next = current->next;//link
			free(temp);
			break;
		}
		previous = current;
		current = current->next;
	}
	return head;
}


struct node* test(struct node* head){

	char username[SIZE];
	char password[SIZE];
	printf("Enter your name: ");
	scanf("%s", username);
	printf("Enter your password: ");
	scanf("%s", password);
	head = create(head, username, password);
	return head;
}

void display(struct node *head){

	struct node *temp = head;
	while(temp!=NULL){
		printf("username: %s\npassword: %s\n", temp->username, temp->password);
		temp = temp->next;
	}
	
}

void output(struct node *head){

	FILE *fp;
	fp = fopen("input.txt", "w");
	if(fp == NULL){
		printf("Cannot open file. Exit\n");
		exit(1);
	}
	struct node *temp = head;
	while(temp!= NULL){
		fprintf(fp, "%s %s\n", temp->username, temp->password);
		temp = temp->next;
	}
	fclose(fp);
}

struct node* input(struct node *head){

	char username[30];
	char password[30];
	FILE *fp;
	fp = fopen("input.txt", "r");
	if(fp == NULL){
		printf("Cannot open file. Exit\n");
		exit(1);
	}

	while(!feof(fp)){
		fscanf(fp, "%s %s", username, password);
		head = create(head, username, password);
	}
	fclose(fp);
	return head;
}

void login(struct node* head){

	char username[30];
	char password[30];
	int flag = 0; // judge wether login successfully
	int exist = 0; // juge wether username exist
	struct node* temp = head;
	while(flag != 1){
		exist = 0;
		printf("Please enter your username: ");
		scanf("%s", username);
		printf("Please enter your password: ");
		scanf("%s", password);
		while(temp != NULL) {
		    if(strcmp(temp->username, username) == 0){
		    	exist = 1;
		    	if(strcmp(temp->password, password) == 0){
		    		printf("%s login successfully\n", username);
		    		flag = 1;
		    		break;
		    	}
		    	else
		    		printf("password is not correct.\n");
		    }
		    else
		    	exist = 0;
		    temp = temp->next;
		}
		if(exist == 0)
			printf("your username is not exist.\n");
	}

}

struct node* Register(struct node* head){

	char username[30];
	char password[30];
	struct node* temp = head;

	int flag = 0; //judge wether register successfully
	int repeat = 0; // judget wether username repeat
	while(flag != 1){
		repeat = 0;
		printf("Please enter your username: ");
		scanf("%s", username);
		printf("Please enter your password: ");
		scanf("%s", password);
		while(temp != NULL) {
		    if(strcmp(temp->username, username) == 0){
		    	printf("username can't repeat.\n");
		    	repeat = 1;
		    }
		    temp = temp->next;
		}
		if(repeat == 0){
			head = create(head, username, password);
			printf("Congratulation. %s  successfully register.\n", username);
			flag = 1;
		}

	}
	return head;
}

int main()
{
	struct node *head = NULL;
	int choice;
	head = input(head);

	printf("\t\t****************************************\n");
	printf("\t\t*           1 login                    *\n");
	printf("\t\t*           2 register                 *\n");
	printf("\t\t****************************************\n");

	printf("Please enter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1: login(head);
		break;
		case 2: head = Register(head);
		break;
		default:
		break;
	}
	display(head);
	output(head);

	return 0;
}