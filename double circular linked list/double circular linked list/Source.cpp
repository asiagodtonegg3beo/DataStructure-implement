//�i�h�[�@��head node��data���s(NULL)�A�ΥH�Φ�2��circular linked list
/*
���@node�i�i���W�Unode
delete�����i���e�@node
�i�a�ʨ�
insert�ݧ��4pointer�Adelete 2 pointer
�q����node�ҥi���Xall node�@��
���ӪŶ�
*/
#include<stdio.h>
class Node {
public:
	int data;
	Node* llink;
	Node* rlink;
	void add(Node* x, int item);
	void del(Node* x, int item);
};
Node* head = new Node();
Node* x = head;
int main() {
	Node* t = new Node();
	t->add(head, 1);
	t->add(head, 2);
	t->del(head, 2);
	t->del(head, 1);
}

void Node::add(Node* x, int item) {
	Node* t = new Node();
	t->data = item;
	if ((x->data == 0) && (x->rlink == NULL) && (x->llink == NULL)) {
		t->rlink = head;
		x->rlink = t;
		x->llink = t;
		t->llink = head;
	}
	else {
		while (x->rlink!=head) {
			x = x->rlink;
		}
		x->rlink = t;
		x->llink = t;
		t->llink = head;
		t->rlink = head;
	}
}

void Node::del(Node*x,int item) {
	Node* t = new Node();
	t->data = item;

	Node * current = x;

	printf("%d", current->data);
	while (current->data != item) {
		current = current->rlink;
	}
	
	(x->llink)->rlink = (x->rlink);
	(x->rlink)->llink = x->rlink;

	current->rlink = NULL;
	current->llink = NULL;
	delete current;


}



