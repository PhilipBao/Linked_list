#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>

using namespace std;

template <class T>
class linked_list
{
	private:
		struct list_node
		{
			T value;
			struct list_node *next;
		}

		list_node *head;

	public:
		linked_list(){
			head = NULL;
		}

		~linked_list();

		void addnode(T);
		void insertnode(T);
		void deletenode(T);
		void displaylist() const;
}

template <class T>
void linked_list<T>:: addnode(T num){
	list_node *newnode;
	list_node *nodeptr;

	newnode = new list_node;
	newnode->value = num;
	newnode->next = NULL;
	// if no head

	if(!head){
		head = newnode;
	}
	else
	{
		nodeptr = head;
		while(nodeptr->next){
			nodeptr = nodeptr->next;

		}

		nodeptr->next = newnode;
	}
}

template <class T>
void linked_list<T>::insertnode(T innum){
	list_node *newnode;
	list_node *nodeptr;
	list_node *prenode;

	newnode = new list_node;
	newnode->value = innum;

	if (! head){
		head = newnode;
		newnode->next = NULL;
	}
	else{
		nodeptr = head;

		prenode = NULL;

		while(nodeptr!=NULL && nodeptr->value < innum){
			prenode = nodeptr;
			nodeptr = nodeptr->next;
		}

		if (prenode == NULL){
			head = newnode;
			newnode->next = nodeptr;
		}else{
			prenode->next = newnode;
			newnode->next = nodeptr;
		}
	}

}

template <class T>
void linked_list<T> :: deletenode(T num){
	list_node *nodeptr;
	lidt_node *prenode;

	if(!head){
		return NULL;
	}
	if(head->value == num){
		nodeptr = head->next;;
		delete head;
		head = nodeptr;
		delete prenode, nodeptr;
	}else{
		nodeptr = head;
		while(nodeptr!=NULL&&nodeptr->value != num){
			prenode = nodeptr;
			nodeptr = nodeptr-> next;

		}
		if(nodeptr){
			pernode->next = nodeptr->next;
			delete nodeptr;
		}
	}
	}
template <class T>
void linked_list<T>::displaylist(){
	list_node *nodeptr;
	if(!head) {
		cout<<"No item in List..."
		delete nodeptr;
	}else{
		nodeptr = head;
		while(nodeptr){
			cout<< nodeptr->value<<endl;
			nodeptr = nodeptr->next;
		}
	}

}

template <class T>
LinkedList<T>::~LinkedList(){
	list_node *nodeptr;
	list_node *nextnode;

	nodeptr = head;
	while(nodeptr != NULL){
		nextnode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextnode;
	}
	delete nextnode;
}

#endif
