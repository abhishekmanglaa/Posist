#include<stdio.h>
#include<iostream>
#include<ctime>
#include<boost/functional/hash.hpp>
#include<string>

using namespace std;

typedef struct Node{
    time_t timeStamp;
    string data;
    int nodeNumber;
    string nideId;
    string referenceNodeId;
    string childReferenceNodeId;
    string genesisRefereneNodeId;
    string hashValue;
	struct Node* next;
	int value;
	string owner;
} Node;

void add_front(Node** head, int value){
	Node* new_node = new Node;
	new_node->value = value;
	if(!(*head)){
		new_node->next = NULL;
		(*head) = new_node;
	}else{
		new_node->next = (*head);
		(*head) = new_node;
	}
	return;
}

void addNode(Node** head, int value, string owner)
{
    Node* temp = new Node;
    temp1 = head;
    while(temp1->next!=NULL){
        temp1 = temp1->next;

    }
    temp = temp->next;

    temp->value = value;
    temp->owner = owner;



}
void remove_link(Node** head, int value_to_remove){
	Node* temp_node = NULL;
	Node* current_node = (*head);
	if((*head)->value == value_to_remove){
		(*head) = (*head)->next;
	}else{
		while(current_node){
			if(current_node->value == value_to_remove){
				temp_node = current_node->next;
				current_node->next = NULL;
				current_node = temp_node;
			}
			current_node = current_node->next;
		}
	}
	return;
}

void remove_duplicates(Node** head){
	Node* current_node = (*head);
	Node* previous_node = NULL;

	while(current_node->next){
		previous_node = current_node;
		current_node = current_node->next;
		if(previous_node->value == current_node->value){
			previous_node->next = current_node->next;
			current_node->next = NULL;
			current_node = previous_node;
		}
	}
	return;
}

void display_list(Node* head){
	Node* current_node = head;
	cout<<"Linked List:\n";
	while(current_node){
		cout<<current_node->value;
		current_node = current_node->next;
	}
	cout<<"NULL\n";
}


int hashCode(string findHashValue)
{
    boost::hash<std::string> string_hash;
    return string_hash(findHashValue);
}



int main(int argc, char const *argv[])
{
	Node* head = NULL;

	int i;
	for(i = 0; i<=10; i++){
		add_front(&head, i);
	}
	add_front(&head, 10);
	add_front(&head, 10);
	display_list(head);
	remove_duplicates(&head);
	remove_link(&head, 10);
	display_list(head);
	return 0;
}
