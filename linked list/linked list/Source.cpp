#include<iostream>
#include<cstdlib>
using namespace std; //�ާ@�覡 insert/delete
                     //insert:�w�N1 node(t)���bnode (x)����A��algo?
					 //delete:�bFirst��C��delete x�A���@node�Oy��x���e�@node
					 //�t�Υi��process�޲z:OS�|�Q�Τ@��AV list����C�A�N�i�Ϊ�node�s�� AV->()->()
class Node {
public:
	int data;
	Node* link;
};
void printlist(Node* x);
void insert(Node* x, Node* t);
void insert(Node* x, int item);
void Push_front(int item,Node *x);
void del(Node* x, Node* y);
void del(Node* x);
void del(Node* x, int item);

int main() {
	Node *t = new Node();			//(t,5)->(tmp,8)
	Node* tmp = new Node();
	Node* new_node = new(Node);
	new_node->data = 7;
	new_node->link = NULL;
	t->data = 5;
	t->link = tmp;
	tmp->data = 8;
	tmp->link = NULL;
	//Push_front(1, t);
	insert(t, 10);
	del(t,10);
	//del(t);
	printlist(t);
}
                                       //x��         t��       tmp��
void insert(Node* x, Node* t) { //insert:(?,xlink)->(5,tlink)->(8,tmplink)
	t->link = x->link;          //t->node�|���J�bx->��node
	x->link = x;
}

void insert(Node* x, int item) {       //x��         t��
	Node* t = new Node();       //insert:(?,xlink)->(item,tlink)->(8,tmplink)
	t->data = item;

	t->link = x->link;
	x->link = t;


}


void del(Node* x, Node* y) {   //y��x���e�@node�Acase1:x���Ĥ@�`�I�Ay->null / case2:else
	Node* first = new Node();
	if (y == NULL) //x���Ĥ@�`�I
		first = x->link;
	else {
		y->link = x->link; //delete x
		free(x);
	}


}


void del(Node* headref) {
	Node* current = headref;
	Node* next = NULL;
	while (current != NULL) {
		next = current->link;
		delete current;
		current=next;
	}
	headref = NULL;
}

void printlist(Node* x) {
	Node* current = x;
	Node* next = NULL;
	if (current != NULL)
		while (current != NULL) {
			next = current->link; //next���V�U�@�Ӹ`�I
			printf("%d ", current->data);
			current = next;
		}
	else {
		printf("This current has been delete");
	}
}
/*
new(t):
//Node *new (Node *AV){
if (AV==null) "no free Node";
else
Node *t = AV
AV =AV->link; //���U�@�樫

}
ret(t)
//Node *new (Node *AV,Node *t) AV->link1->link2

t->link = AV; //!= AV->link:link1->link2
AV->t;
*/