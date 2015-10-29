//159201 Assignment5
//Haomin Liu 12109377

#include <stdio.h>
#include <stdlib.h>

#include <stack>
#include <iostream>
#include <fstream>

using namespace std;

/* implement the Tree class here, you can copy the one from week 4 slides */
/* the contents of the Tree nodes can be of type char, so they can store operators (+, *, / and -) as well as digits (0,1,2...9) */
/* all the RPN*.txt test files contain numbers with single digits */
class Tree {
private:
  char data;
  Tree *leftptr, *rightptr;
 
public:
  Tree(char newthing, Tree* L, Tree* R);  // constructor with paramters
  ~Tree() { }
  char RootData() { return data; }  // inline functions
  Tree* Left() { return leftptr; }
  Tree* Right() { return rightptr; }
};

Tree::Tree(char newthing, Tree* L, Tree* R) {
  data = newthing;
  leftptr = L;
  rightptr = R;
}

void inOrder(Tree *T) {
	if (T == NULL) { return; }
	if(T->Left()!=NULL){ printf("%c",'('); }
	inOrder(T->Left());
	printf("%c ", T->RootData());
	inOrder(T->Right());
	if(T->Right()!=NULL){ printf("%c",')');}
   return;
}

void PostOrder(Tree *T) {
	if (T == NULL) { return; }
	PostOrder(T->Left());
	PostOrder(T->Right());
	printf("%c ", T->RootData());
}




/* implement your stack here*/
// remember that the content of the stack is of type Tree 

	
//Declare your stack of Tree* here 
Tree *T1, *T2, *T; 

stack<Tree*> S; 

/* implement your recursive funtions for traversals */
/*
while (expression continues) {
 x = next item from the expression
 if (x is a number) { S.Push(new Tree(x, NULL, NULL)); }
 if (x is an operator) {
 T1 = S.Top(); S.Pop();
 T2 = S.Top(); S.Pop();
 S.Push(new Tree(x, T2, T1)); note order of T2 and T1
 }
}
T = S.Top();
*/
	
  main( int argc, char** argv ){//get filename from arguments
	char digit;
	char oper;
	char expression[100];
	ifstream input_file;
	if(argc==2) input_file.open(argv[1]);
	else {printf("The program needs a filename as argument \n");exit(0);}
	
	/* both operator and digits are of type char */
	while(input_file >> expression){
		if(isdigit(expression[0])){
			sscanf(expression,"%c",&digit);
			printf("reading a number: %c \n",digit);
			//modify here to deal with the Stack
			S.push(new Tree(digit, NULL, NULL)); 
		}
		else {
			sscanf(expression,"%c",&oper);
			printf("reading an operator: %c \n",oper);
			//modify here to deal with the Stack
			T1 = S.top(); S.pop();
			T2 = S.top(); S.pop();
			S.push(new Tree(oper, T2, T1)); 
		}
		
	}
	
	T = S.top();

	//Now we can traverse the tree in a certain way and print the expression
	//in-order with parenthesis

	printf("Inorder: ");
	inOrder(T);
	printf(" ");
	//post-order
	printf("Postorder: ");
	PostOrder(T);
	printf(" ");
	getchar();
}
  