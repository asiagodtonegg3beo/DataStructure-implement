//可多加一個head node其data不存(NULL)，用以形成2個circular linked list
/*
任一node可告知上下node
delete不須告知前一node
可靠性佳
insert需更動4pointer，delete 2 pointer
從任何node皆可拜訪all node一次
較耗空間
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