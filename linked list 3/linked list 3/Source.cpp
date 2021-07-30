#include<stdio.h>
class Node {

public:
	int data;
	Node* next;
};
void printList(Node* node);              //印出list
void pushfront(Node** x, int item);      //插在前端
void pushback(Node** x, int item);       //插在尾端
void insert(Node** x, int item , int n); //插入在指定值的後面
void reverse(Node** x);
int main() {

	Node* a = new Node;
	a->data = 10;
	a->next = NULL;
	pushfront(&a,7);
	pushback(&a, 6);
	insert(&a, 5, 10);
	printList(a);
	reverse(&a);
	printf("\nreverse:\n");
	printList(a);
}

void pushfront(Node** head, int item) {
	Node* current = new Node();
	current->data = item;
	current->next = *head; //current的next指向head
	*head = current;		//將x的頭指向新節點
}
void pushback(Node** x, int item) {
	Node* current = new Node();
	Node* last = *x;
	current->data = item;
	current->next = NULL;
	if (*x == NULL)				//如果傳入的node為空，則設新加入的節點為頭
		*x = current;
	while (last->next != NULL) { //traserval:找到最後NULL的位置
		last = last->next;
	}
	last->next = current;		//將x接上新節點

	
	
}
void insert(Node** x, int item , int num) {
	Node* current = new Node();
	Node* find = *x;
	current->data = item;
	while (find->data != num) {
		find = find->next;
	}
	current->next = find->next;
	find->next = current;
}

void reverse(Node** head) { //current指向head，previous/next指向同一處(null)，依序向後移動
	Node* previous = NULL;
	Node* current = *head;
	Node* next = previous;
	while (current != NULL) {
		next = current->next;		//next向後挪
		current->next = previous;	//current的指向previous
		previous = current;			//previous向後挪
		current = next;				//current向後挪
	}
	*head = previous;				//head改成頭
	
}
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

