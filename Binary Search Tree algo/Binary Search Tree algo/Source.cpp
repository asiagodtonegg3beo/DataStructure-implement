#include<stdio.h>
#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* llink;
	Node* rlink;
	
};

Node* root;															
void inorder(Node* root);
bool search(Node* a, int x);
Node* insert(Node* root,int x);
Node* copy(Node* root);
bool equal(Node* a, Node* b);
int count(Node* t);
int height(Node* t);
Node* del(Node*root, int x);
Node* minvalue(Node* root);
int countleaf(Node* root);
int main() {                              
	root = new Node();   
	Node* s = NULL;
	printf("s nodes:%d\n", count(s));
	root->data = 50;                    
	root->llink = new Node();
	root->llink->data = 40;
	root->rlink = new Node();
	root->rlink->data = 70;

	s = insert(s, 50); 
	insert(s, 40); 
	insert(s, 70);
	int find = 20;
	search(s, find) ? printf("find %d\n",find) : printf("%d not found\n",find);
	inorder(root); cout<<endl;
	inorder(s); cout << endl;
	printf("s leaf = %d", countleaf(s));
	(equal(root, s)) ? printf("equal\n") : printf("not equal\n");
	 del(s, 50);  
	 del(s, 40); 
	s= del(s, 70);
	//Node* p = copy(root);
	//p->llink->data = 30;
	//inorder(p); cout<<endl;
	//(equal(root, p)) ? printf("equal") : printf("not equal"); cout << endl;
	printf("s nodes:%d\n", count(s));
	printf("s height:%d\n", height(s));
}

void inorder(Node *root) {
	Node* t = root;

	if (t != NULL) {
		inorder(t->llink);
		printf("%d ", t->data);
		inorder(t->rlink);
	}
	else {
		return;
	}
}
//case 1:空樹=> 複製也是空樹
//case 2:t指向root data，遞迴拜訪左樹再拜訪右樹複製
Node* copy(Node* root) {
	Node* t;
	if (root == NULL) {
		t = NULL;
	}
	else {
		t = new Node();
		t->data = root->data;
		t->llink = copy(root->llink); //t左Link指向遞回左link
		t->rlink = copy(root->rlink); //t右Link指向遞回右link
	}
	return t;
}
//case1:a=null,b=null=>return true  
//case2:a!=null,b!=null =>if (a data==b data) if 呼叫遞迴equal(a左樹,b左樹) then 呼叫遞迴equal(a右樹,b右樹);
bool equal(Node* a, Node* b) {
	int result = 0;
	if (a == NULL && b == NULL)
		result = 1;
	else if (a != NULL && b != NULL)
		if (a->data == b->data) {
			if (equal(a->llink, b->llink)) {
				if (equal(a->rlink, b->rlink)) {
					result = 1;
				}
			}
		}
	return result;
}

int count(Node* root) {
	Node* t = root;
	int nL=0, nR=0;
	if (t == NULL) {
		return 0;
	}
	else if (t != NULL) {
		nL = count(t->llink);
		nR = count(t->rlink);
		return nL + nR + 1;
	}
}

int height(Node* root) {
	Node* t = root;
	int hl=0, hr=0;
	if (t==NULL) {
		return 0;
	}
	else if (t != NULL) {
		hl = height(t->llink);
		hr = height(t->rlink);
		return max(hl, hr) + 1;
	}
}

Node* insert(Node* a,int x) {
	Node* t = new Node();
	Node* current = a;
	Node* parent = NULL;
	t->data = x;
	t->llink = NULL;
	t->rlink = NULL;

	while (current != NULL) {
		parent = current; //current->NULL時，parent即是NULL的前一節點
		if (t->data > current->data) {
			current = current->rlink;
		}
		else {
			current = current->llink;
		}
	}
		if (parent==NULL) {
			parent = t;
		}
		else if (t->data < parent->data) {
			parent->llink = t;
		}
		else {
			parent->rlink = t;
		}

		return parent;
}

bool search(Node* x, int a) {
	Node* current = x;
	
	if (current == NULL) {
		return 0;
	}
	else if (current->data == a) {
			return 1;
	}
		if (a < current->data) {
			search(current->llink, a);
		}
		else {
			search(current->rlink, a);
		}
	
	return 0;
}

Node* del(Node* root, int x) {

	if (root == NULL) { //root==NULL，則回傳root
		return NULL;
	}
	else {
		if (root->data == x && root->rlink == NULL && root->llink == NULL) {
			delete(root);
			return NULL;
		}
		if (x < root->data) { //x < root往左走
			root->llink = del(root->llink, x);
		}
		else if (x > root->data) { //x > root往右走
			root->rlink = del(root->rlink, x);
		}
		if (root->llink == NULL && root->rlink == NULL) { //node底下無子樹
			return NULL;
		}
		else if (root->llink == NULL) {  //node只有左、右子樹其一
			Node* t = root->rlink;
			delete(root);
			return t;
		}
		else if (root->rlink == NULL) {
			Node* t = root->llink;
			delete(root);
			return t;
		}
		Node* t = minvalue(root->rlink);	//當左右各有兩子樹，取右子樹最小(替代者)
		root->data = t->data;				//root的值取代成中序(左右各有兩子樹)的替代者(t)
		root->rlink = del(root->rlink, t->data);	//刪除原本替代者的值
	}
	if (root == NULL) {
		root->data = 0;
		root->llink = NULL;
		root->rlink = NULL;
		return root;
	}
	return root;
}

Node* minvalue(Node* root) {
	Node* current = root;

	while (current != NULL && current->rlink != NULL) {
		current = current->llink;
	}
	return current;
}

int countleaf(Node *root) {
	int nL = 0, nR = 0;
	if (root == NULL)
		return 0;
	else {
		nL = countleaf(root->llink);
		nR = countleaf(root->rlink);
		if (nL + nR == 0)
			return 1;
		else
			return nL + nR;
	}
}