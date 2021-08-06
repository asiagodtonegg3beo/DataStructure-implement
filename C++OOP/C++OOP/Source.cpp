#include<stdio.h>
#include<iostream>
using namespace std;

class Animal{

public:
	Animal() { //initial
		leg = 0;
		sum = 0;
		animaltype = "none";
	}
	virtual void sound() { //多型，函數複寫
		printf("Animal:say?\n");
	}
	void setleg(int x) {  
		leg = x;
	}
	template <typename T>
	void set_animaltype(T ch) {
		animaltype = ch;
	}
	virtual void setleg(int x, int y);

	void show() {
		cout << animaltype << " have " << leg << "legs" << endl;
	}
	
private:  //封裝
	int leg;
	int sum;
	string animaltype;
};
void Animal::setleg(int x,int y) { //多型，多載
	sum = x + y;
	leg = sum;
}
class Dog :public Animal { //繼承
public:
	virtual void sound() override{
		printf("Dog:bark!\n");
	}
};

class Cat : public Animal {
public:
	virtual void sound() override{
		printf("Cat:meow!\n");
	}
	template <typename T>
	void set_animaltype(T ch) override{


	}
/*	virtual void setleg(int x) {
		cout << "Cat have " << x << " legs" << endl;
	}
*/
};

int main() {
	Animal a,fish;
	a.sound();
	Dog d;
	Dog* D=new Dog;
	Cat c;
	fish.setleg(0);
	d.sound();
	d.setleg(4);
	D->sound();
	c.sound();
	c.setleg(4);
	c.setleg(2, 3);
	c.set_animaltype("cat");
	c.show();
	c.show();
}

