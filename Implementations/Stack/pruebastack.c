#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "Elem.h"
#include "Stack.h"
int main(){
	Stack st=Empty();
	int x=25;
	//Stack test with Collatz conjecture
	while(x!=1){
		if(x%2)x=x*3+1;
		else x/=2;
		st=Push(x,st);
	}
	while(!IsEmpty(st)){
		PrintElem(Top(st));
		st=Pop(st);
	}
}
