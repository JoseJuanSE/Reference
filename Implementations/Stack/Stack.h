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
/*--Specs Stack
Empty:->Pila;
Push:elem,pila->pila;
IsEmpty:Pila->Bool;
Top:Pila->Elem;
Pop:Pila->Pila;

--Axioms: Elem e,Pila p;
[p1]	IsEmpty(empty())=Cierto;
[p2]	isEmpty(push(e,p))=false;
[p3]	Top(empty())->Error
[p4]	Top(push(e,p))=e;
[p5]	Pop(empty())->Error
[p6]	Pop(push(e,p))=p;*/
