//Lista circulara dublu inlantuita nesortata
#include<stdio.h>

typedef int TypeVal; //tipul valorilor cheilor

struct nod           //un element din lista cu cele 3 campuri 
{
	TypeVal value;   //valoarea elementului
	nod *next,*back; //referintele next si back
};

nod *head;          //pastreaza capul listei
nod *tail;          //pastreaza coada listei

//afisam lista de la cap la coada
void showForward(nod *head,nod *tail) 
{
	while(head != NULL)
	{
		printf("%d\n",head->value);
		
		head = (head == tail ? NULL : head->next);
	}
}

//afisam lista de la coada la cap
void showBackward(nod *head,nod *tail) 
{
	while(tail != NULL)
	{
		printf("%d\n",tail->value);
		
		tail = (head == tail ? NULL : tail->back);
	}
}

//adaugam un element in fata capului listei
void insertBefore(nod* &head,nod* &tail,TypeVal value) 
{
	nod *New        = new nod;
	New->value      = value;

	if(head == NULL)  //daca lista este goala capul si coada sunt aceleasi
	{
		head = tail = New;
		New->next   = tail;
		New->back   = head;
	} 
	else if(head == tail) //daca avem un singur element
	{
		New->next   = tail;
		New->back   = tail;
		head        = New;
		tail->next  = New;
		tail->back  = New;
	}
	else 
//in caz contrar noul element devine capul listei,il pointam catre coada si pointam fostul cap al listei catre noul cap si invers
	{
		New->next   = head;
		head->back  = New;
		New->back   = tail;
		tail->next  = New;
		head        = New;
	}
}

//adaugam un element la sfarsitul listei
void insertAfter(nod* &head,nod* &tail,TypeVal value)
{
	nod *New        = new nod;
	New->value      = value;
	
	
	if (head == NULL)  //daca lista este goala
	{
		head = tail = New;
		New->next   = New;
		New->back   = New;
	}
	else if(head == tail) //daca lista are un element
	{
		New->next   = head;
		New->back   = head;
		head->next  = New;
		head->back  = New;
		tail        = New;
	}
	else 
//in caz contrar noul element devine coada listei,il pointam catre capul listei si pointam fosta coada catre noua coada si invers
	{
		New->back   = tail;
		tail->next  = New;
		New->next   = head;
		tail        = New;
		head->back  = tail;
	}
}

//adaugam un element la pozitia pos(unde pos este referinta catre un element din lista)
//elementul adaugat inainte de referinta
void insertAtPositionBefore(nod* &head,nod* &tail,TypeVal value,nod* pos)
{
	nod *New             = new nod;
	New->value           = value;
	
	if(head == NULL)     //lista este goala
	{
		head = tail      = New;
		New->next        = New;
		New->back        = New;
	}
	else if(head == pos) //lista are un singur element
	{
		New->next        = head;
		New->back        = tail;
        head->back       = New;		
		head             = New;
		tail->next       = head;
	}
	else  //adaugam elementul inaintea celui pointat in pos si modificam referintele necesare
	{
		New->next        = pos;
		New->back        = pos->back;
		New->back->next  = New;
		pos->back        = New;
	}
}

//adaugam un element la pozitia pos(unde pos este referinta catre un element din lista)
//elementul adaugat dupa referinta
void insertAtPositionAfter(nod* &head,nod* &tail,TypeVal value,nod* pos)
{
	nod *New = new nod;
	New->value = value;
	
	if(head == NULL)  //lista este goala
	{
		head = tail = New;
		New->next = New;
		New->back = New;
	}
	else if(tail == pos) //lista are un singur element
	{
		New->back   = tail;
		tail->next  = New;
		New->next   = head;
		tail        = New;
		head->back  = tail;
	}
	else //adaugam elementul dupa cel pointat in pos si modificam referintele necesare
	{
		New->back = pos;
		New->next = pos->next;
		pos->next = New;
		New->back->next = New;
	}
}

//cautam elementul al steps`lea din lista
//(daca exista returneaza pointer catre acesta,respectiv NULL in caz contrar)
nod* searchByPosition(nod *head,int steps)
{
    int i = 0; // current position

	while(head != NULL && i < steps)
	{
		head = (head->next == tail->next ? NULL : head->next);  //daca urmatorul element face referire la primul element ne oprim
		i++; //incrementam pozitia
	}
	
	if(i == steps) //daca e al steps`lea element returnam referinta
		return head;
	else 
		return NULL; //null
}

//cautam un nod din lista dupa valoare
//returneaza pointerul catre acesta respectiv NULL in caz contrar
nod* searchByValue(nod *head,int value)
{
    while(head != NULL && head->value != value) 
	    head = (head->next == tail->next ? NULL : head->next); //daca urmatorul element face referire la primul element ne oprim
    return head; //returnam referinta NULL daca nu a fost gasit	
}

//stergem un element ce se afla intre cap si coada
void removeInsideElement(nod *element)
{
	if(element != NULL) //daca avem elementul in lista
	{
	     element->next->back = element->back;
	     element->back->next = element->next;
	
	     delete element; //il stergem si facem mai sus modificarile de referinte intre element
	}
}

//stergem un element la o anumita pozitie
void removePositionElement(nod* &head,int position)
{
	if(head == NULL)
	{
		return;
	}
	else if(position == 0) //daca eliminam capul listei
	{
		nod* del = head;
		head = head->next;
		head->back = tail;
		delete del;
	}
	else
	{		
		nod* element = searchByPosition(head,position);
		 
		if(element == tail) //daca eliminam coada listei
		{			 
			nod* del = tail;
			tail = tail->back;
			tail->next = head;
			head->back = tail;
			delete del;
		}
		else //daca eleminam un element din interiorul listei
		{
		    removeInsideElement(element);
		}
	}
}

int main()
{
//	insertBefore(head,tail,100);
//	insertBefore(head,tail,120);
//	insertBefore(head,tail,130);
//	insertBefore(head,tail,150);
//	insertAtPositionAfter(head,tail,99,head);
//	insertAtPositionAfter(head,tail,109,tail);
	insertAfter(head,tail,150);
	insertAfter(head,tail,120);
	insertAfter(head,tail,125);
	insertAfter(head,tail,152);
	insertAfter(head,tail,160);
	
	removePositionElement(head,1);
	showForward(head,tail);
	printf("----\n");
	showBackward(head,tail);
	return 0;
}
