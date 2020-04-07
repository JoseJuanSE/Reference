#include<stdbool.h>
typedef int Elem;
void PrintElemF(Elem x,FILE *out){
	fprintf(out,"%d\n",x);
}
void PrintElem(Elem e){
   PrintElemF(e,stdout);
}
