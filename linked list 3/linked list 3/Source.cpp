#include<stdio.h>
class Node {

public:
	int data;
	Node* next;
};
void printList(Node* node);              //�L�Xlist
void pushfront(Node** x, int item);      //���b�e��
void pushback(Node** x, int item);       //���b����
void insert(Node** x, int item , int n); //���J�b���w�Ȫ��᭱
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
	current->next = *head; //current��next���Vhead
	*head = current;		//�Nx���Y���V�s�`�I
}
void pushback(Node** x, int item) {
	Node* current = new Node();
	Node* last = *x;
	current->data = item;
	current->next = NULL;
	if (*x == NULL)				//�p�G�ǤJ��node���šA�h�]�s�[�J���`�I���Y
		*x = current;
	while (last->next != NULL) { //traserval:���̫�NULL����m
		last = last->next;
	}
	last->next = current;		//�Nx���W�s�`�I

	
	
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

void reverse(Node** head) { //current���Vhead�Aprevious/next���V�P�@�B(null)�A�̧ǦV�Ჾ��
	Node* previous = NULL;
	Node* current = *head;
	Node* next = previous;
	while (current != NULL) {
		next = current->next;		//next�V�ᮿ
		current->next = previous;	//current�����Vprevious
		previous = current;			//previous�V�ᮿ
		current = next;				//current�V�ᮿ
	}
	*head = previous;				//head�令�Y
	
}
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

