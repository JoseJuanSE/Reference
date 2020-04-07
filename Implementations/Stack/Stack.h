typedef struct Nodo{
   Elem val;
   struct Nodo *next;
} *Stack;
Stack Empty(){return NULL;}
bool IsEmpty(Stack a){return a==NULL;}
Elem Top(Stack a){return a->val;} 
Stack Pop(Stack l){return l->next;}
Stack Push(Elem x,Stack res){
    Stack nuevo=(Stack)malloc(sizeof(struct Nodo));
    nuevo->val=x;
    nuevo->next=res;
    return nuevo;
}
/*--Espec Pila
empty:->Pila;
push:elem,pila->pila;
isempty:Pila->Bool;
top:Pila->Elem;
pop:Pila->Pila;

--Axiomas: Elem e,Pila p;
[p1]	isempty(empty())=Cierto;
[p2]	isempty(push(e,p))=false;
[p3]	top(empty())->Error
[p4]	top(push(e,p))=e;
[p5]	pop(empty())->Error
[p6]	pop(push(e,p))=p;*/
