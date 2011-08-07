//Lista liniara dublu inlantuita nesortata
#include<stdio.h>

typedef int TypeVal; //tipul valorilor cheilor

struct nod           //un element din lista cu cele 3 campuri 
{
	TypeVal value;   //valoarea elementului
	nod *next,*back; //referintele next si back
};

nod *head;          //pastreaza capul listei

//afisam lista de la cap la coada
void showForward(nod* head)
{
	while(head != NULL)
	{
		printf("%d\n",head->value);
		head = head->next;
	}
}

//afisam lista de la coada la cap
void showBackward(nod* head)
{
	while(head->next != NULL)
	{
	    head = head->next; 	
	}
	
	while(head != NULL)
	{
		printf("%d\n",head->value);
		head = head->back;
	}
}

//adaugam un element in fata capului listei
void insertBefore(nod* &head,TypeVal value)
{
	nod *New  = new nod;
	New->value  = value;
	New->back = NULL;
	New->next = head;
	
	if(head != NULL)           //daca lista nu este goala
	{
		New->back = head;
	}
	head = New;
}

//adaugam un element la sfarsitul listei
void insertAfter(nod* &head,TypeVal value)
{
	nod *New = new nod;
	New->value = value;
	New->back = New->next = NULL;
	
	if(head == NULL)   //daca lista este goala
	{
		head = New;
	}
	else
	{
		nod *tmp = head;
		while(tmp->next != NULL) //parcurgem lista si adaugam dupa coada
			tmp = tmp->next;
		tmp->next = New;
		New->back = tmp;
	}
}

//adaugam un element la pozitia pos(unde pos este referinta catre un element din lista)
//elementul adaugat inainte de referinta
void insertAtPositionBefore(nod* &head,TypeVal value,nod* pos)
{
	nod *New = new nod;
	New->value = value;
	New->back = New->next = NULL;
	
	if(head == NULL) //daca lista este goala
	{
		head = New;
	}
	else if(head == pos)  //daca capul reprezinta referinta pos`ului
	{
		New->next = head;
		head->back = New;
		head = New;
	}
	else //daca este un alt element
	{
		New->next = pos->next;
		New->back = pos;
        pos->back->next = New;
        pos->next = New;		
	}
}


//cautam elementul al steps`lea din lista
//(daca exista returneaza pointer catre acesta,respectiv NULL in caz contrar)
nod* searchByPosition(nod* head,int steps)
{
    int i = 0; // pozitia curenta
	while(head != NULL && i < steps) //cautam elementul pana ajungem la sfarsitul listei
	{
		head = head->next; i++; 
	}
	if(i == steps)
		return head;
	else
		return NULL;
}

//cautam un nod din lista dupa valoare
//returneaza pointerul catre acesta respectiv NULL in caz contrar
nod* searchByValue(nod* head,int value)
{
    while(head != NULL && head->value != value) //cautam pana ajungem la sfarsitul listei
	    head = head->next;
    return head;	
}

//stergem un element ce nu este capul listei
void removeInsideElement(nod *element)
{
	if(element != NULL)
	{
	     element->next->back = element->back;
      	 element->back->next = element->next;
	 
	     delete element; //stergem un element si setam referintele intre elementele ce erau inainte si dupa el
	}
}

//stergem un element la o anumita pozitie
void removePositionElement(nod* &head,int position)
{
	if(head == NULL)
	{
		return;
	}
	else if(position == 0) //daca este capul listei
	{
		nod* del = head;
		head = head->next;
		head->back = NULL;
		delete del;
	}
	else
	{
		nod* element = searchByPosition(head,position); //cautam elementul
		removeInsideElement(element);
	}
}

int main()
{
	insertBefore(head,100);
	insertAfter(head,150);
	insertAfter(head,120);
	insertAfter(head,125);
	insertAfter(head,152);
	insertAfter(head,160);
	insertAtPositionBefore(head,99,head);
	 
	showForward(head);
	printf("----\n");
	showBackward(head);
	return 0;
}
