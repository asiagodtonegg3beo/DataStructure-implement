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
	void add(Node *x,int item);
	void del(int item);
};
Node* head = new Node();

int main() {
	Node *t=new Node();
	t->add(head, 1);
	t->add(head, 2);
	t->add(head, 3);
}

void Node::add(Node *x,int item) {
	Node* t = new Node();
	t->data = item;

	while (x->rlink != x) {
		x = x->rlink;
	}
		x->rlink = t;
		x->llink = t;
		t->llink = x;
		t->rlink = x;
		

}