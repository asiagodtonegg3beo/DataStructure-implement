#include<iostream>
#include<cstdlib>
using namespace std; //操作方式 insert/delete
                     //insert:預將1 node(t)插在node (x)之後，問algo?
					 //delete:在First串列中delete x，此一node令y為x的前一node
					 //系統可用process管理:OS會利用一條AV list的串列，將可用的node連接 AV->()->()
class Node {
public:
	int data;
	Node* link;
};
void insert(Node* x, Node* t);
void insert(Node* x, int item);
void del(Node* x, Node* y);
void del(Node* x);
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
	insert(t, new_node);
	del(t);
}
                                       //x↓         t↓       tmp↓
void insert(Node* x, Node* t) { //insert:(?,xlink)->(5,tlink)->(8,tmplink)
	t->link = x->link;          //t->node會插入在x->的node
	x->link = t;

}

void insert(Node* x, int item) {       //x↓         t↓
	Node* t = new Node();       //insert:(?,xlink)->(item,tlink)->(8,tmplink)
	t->data = item;
	t->link = x->link;
	x->link = t;

}

void del(Node* x, Node* y) {   //y為x的前一node，case1:x為第一節點，y->null / case2:else
	Node* first = new Node();
	if (y == NULL) //x為第一節點
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
		free(current);
		current=next;
	}
	headref = NULL;
}
/*
new(t):
//Node *new (Node *AV){
if (AV==null) "no free Node";
else
Node *t = AV
AV =AV->link; //往下一格走

}
ret(t)
//Node *new (Node *AV,Node *t) AV->link1->link2

t->link = AV; //!= AV->link:link1->link2
AV->t;
*/
