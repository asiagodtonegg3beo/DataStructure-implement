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
Node* createnode(char ch);				/*建構函式*/
Node* insertnode(Node* root, char ch); /*插入函式*/
void inorder(Node* root);			   /*中序*/
void preorder(Node* root);			   /*前序*/
void postorder(Node* root);			   /*後序*/
bool search(Node* root, char t);
void trase();
int main() {
	Node* root = createnode('A');
	cout << "存放 " << "A ";
	char c[] = "BCDEF";
	for (int i = 0; i < strlen(c); i++) {
		cout << c[i] << " ";
		insertnode(root, c[i]);
	}
	cout << endl;
	cout << "中序 "; inorder(root); cout << endl;
	//cout << "前序 "; postorder(root); cout << endl;
	//cout << "後序 "; preorder(root); cout << endl;
	//(search(root, 'F')) ? printf("find") : printf("None");
	//trase();


}

Node* createnode(char ch) {
	Node* t = new Node(); /*生成newnode空間*/
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

	if (root == NULL) { /*如果樹根是NULL，則create一個node，並將root設為此node*/
		root = createnode(ch);
		return root;
	}


	queue<Node*> q; /*queue用來紀錄下一節點有沒有元素，如果有就push，沒有就存放值並結束迴圈*/
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->lchild != NULL)
			q.push(temp->lchild);
		else {
			temp->lchild = createnode(ch);
			return root;
		}

		if (temp->rchild != NULL)
			q.push(temp->rchild);
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


