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

int main()
{
	struct node *head = NULL;
	head = input(head);

	display(head);
	printf("---------------------------\n");

	struct node* result = search(head, "yang");
	printf("username: %s\npassword: %s\n", result->username, result->password);
	printf("---------------------------\n");


	head = update(head, "huang");
	display(head);
	printf("---------------------------\n");


	head = destroy(head, "yang");
	display(head);

	output(head);

	return 0;
}