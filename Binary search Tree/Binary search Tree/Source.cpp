#include<stdio.h>
#include<iostream>
#include<queue>
#include<deque>
#include<stdlib.h>
using namespace std;

class Node {
public:
	Node* lchild;
	char data;
	Node* rchild;
};
deque <int> traserval;
Node* createnode(char ch);				/*�غc�禡*/
Node* insertnode(Node* root, char ch); /*���J�禡*/
void inorder(Node* root);			   /*����*/
void preorder(Node* root);			   /*�e��*/
void postorder(Node* root);			   /*���*/
bool search(Node* root, char t);
void trase();
int main() {
	Node* root = createnode('A');
	cout << "�s�� " << "A ";
	char c[] = "BCDEF";
	for (int i = 0; i < strlen(c); i++) {
		cout << c[i] << " ";
		insertnode(root, c[i]);
	}
	cout << endl;
	cout << "���� "; inorder(root); cout << endl;
	//cout << "�e�� "; postorder(root); cout << endl;
	//cout << "��� "; preorder(root); cout << endl;
	//(search(root, 'F')) ? printf("find") : printf("None");
	//trase();


}

Node* createnode(char ch) {
	Node* t = new Node(); /*�ͦ�newnode�Ŷ�*/
	if (!t) {
		cout << "Memory error\n";
		return NULL;
	}
	t->data = ch;
	t->lchild = t->rchild = NULL;
	return t;
}

Node* insertnode(Node* root, char ch)
{

	if (root == NULL) { /*�p�G��ڬONULL�A�hcreate�@��node�A�ñNroot�]����node*/
		root = createnode(ch);
		return root;
	}


	queue<Node*> q; /*queue�ΨӬ����U�@�`�I���S�������A�p�G���Npush�A�S���N�s��Ȩõ����j��*/
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->lchild != NULL) {
			q.push(temp->lchild);
		}
		else {
			temp->lchild = createnode(ch);
			return root;
		}

		if (temp->rchild != NULL) {
			q.push(temp->rchild);
		}
		else {
			temp->rchild = createnode(ch);
			return root;
		}
	}
}

void inorder(Node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->lchild);
	cout << root->data << " ";
	inorder(root->rchild);

}

void preorder(Node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->lchild);
	preorder(root->rchild);
}

void postorder(Node* root) {
	if (root == NULL)
		return;
	postorder(root->lchild);
	postorder(root->rchild);
	cout << root->data << " ";
}

bool search(Node* root, char t) {

	if (root==NULL) {
		return false;
	}
	else
		if (t == root->data) {
			printf("find %c in root\n",root->data);
			traserval.push_back(root->data);
			return true;
		}
		else if (t < root->data) {
			traserval.push_back(root->data);
			search(root->lchild, t);
		}
		else if (t > root->data) {
			traserval.push_back(root->data);
			search(root->rchild, t);
		}
}

void trase() {
	for (auto it = traserval.begin(); it != traserval.end(); it++) {
		printf("%c ", *it);
	}
}


