#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

struct {
	float coef;
	int expon;
} terms[MAX_TERMS];
int avail;

typedef struct poly
{
	float coef;
	int expr;
	struct poly *next;
} poly;
typedef poly *POLY;
POLY InitLinkList();
void AddNode(POLY, float, int);
void PrintNode(POLY);
void MultiplyPoly(POLY, POLY, POLY);
void DeleteNode(POLY);

void Inputinit()
{
	terms[0].coef = 2; terms[0].expon = 15;
	terms[1].coef = 3; terms[1].expon = 10;
	terms[2].coef = -1; terms[2].expon = 3;
	terms[3].coef = 0.5; terms[3].expon = 2;
	terms[4].coef = 1; terms[4].expon = 1;
	terms[5].coef = 1; terms[5].expon = 0;
	terms[6].coef = 3; terms[6].expon = 8;
	terms[7].coef = -8; terms[7].expon = 4;
	terms[8].coef = 1; terms[8].expon = 1;
	terms[9].coef = -5; terms[9].expon = 0;
	avail = 10;

}

void StructInit()
{
	typedef struct poly
	{
		float coef;
		int expon;
		struct poly *next;
	} poly;
	typedef poly *POLY;
}


void main()
{
	Inputinit();
	StructInit();
	POLY Ahead = NULL;
	POLY Bhead = NULL;
	POLY Chead = NULL;

	Ahead = InitLinkList();
	Bhead = InitLinkList();
	Chead = InitLinkList();

	float coef = 0;
	int expr = 0;

	printf("Input Poly A's coef and expr. (expr<0 to exit)\n");
	while (1)
	{
		scanf("%f%d", &coef, &expr);

		if (expr < 0)
			break;

		AddNode(Ahead, coef, expr);
	}

	printf("Input Poly B's coef and expr. (expr<0 to exit)\n");
	while (1)
	{
		scanf("%f%d", &coef, &expr);

		if (expr < 0)
			break;

		AddNode(Bhead, coef, expr);
	}
	printf("\n");
	PrintNode(Ahead);
	printf("\n");
	PrintNode(Bhead);
	printf("\n");
	MultiplyPoly(Ahead, Bhead, Chead);
	PrintNode(Chead);
	printf("\n");
	DeleteNode(Ahead);
	DeleteNode(Bhead);
	DeleteNode(Chead);

	system("pause");




}

POLY InitLinkList()
{
	POLY head = NULL;
	POLY tail = NULL;

	head = (POLY)malloc(sizeof(poly));
	tail = (POLY)malloc(sizeof(poly));
	if (head == NULL || tail == NULL)
		exit(1);

	head->next = tail;
	tail->next = NULL;
	return head;
}

void AddNode(POLY head, float coef, int expon)
{
	POLY p = NULL;
	POLY t = NULL;
	POLY ptr = NULL;
	int equal = 0;
	int i = 0;

	t = head;
	p = head->next;

	for (; p->next != NULL; p = p->next)
	{
		if (expon >= (p->expr))
		{
			equal = ((expon == p->expon) ? 1 : 0);
			break;
		}
		t = p;
	}

	if (equal)
		(p->coef) = (p->coef) + coef;
	else
	{
		ptr = (POLY)malloc(sizeof(poly));

		if (ptr == NULL)
			exit(1);

		ptr->coef = coef;
		ptr->expr = expr;
		ptr->next = p;
		t->next = ptr;
	}
}

void MultiplyPoly(POLY Ahead, POLY Bhead, POLY Chead)
{
	POLY ap = NULL;
	POLY at = NULL;
	POLY bp = NULL;
	POLY bt = NULL;
	POLY cp = NULL;
	POLY ct = NULL;

	ap = Ahead->next;
	at = Ahead;
	cp = Chead->next;
	ct = Chead;

	for (; ap->next != NULL; ap = ap->next)
	{
		bp = Bhead->next;
		bt = Bhead;
		for (; bp->next != NULL; bp = bp->next)
		{
			AddNode(Chead, (ap->coef) * (bp->coef), (ap->expr) + (bp->expr));
			bt = bp;
		}
		at = ap;
	}

}



void PrintNode(POLY head)
{
	POLY p = NULL;
	p = head->next;

	for (; p->next != NULL; p = p->next)
	{
		printf("%.1fx^%d ", (p->coef), p->expr);
		printf(" + ");
	}

}

void DeleteNode(POLY head)
{
	POLY p = NULL;
	POLY t = NULL;

	p = head->next;
	t = head;

	for (; p->next != NULL; p = p->next)
	{
		free(t);
		t = p;
	}
	free(t);
	free(p);
}