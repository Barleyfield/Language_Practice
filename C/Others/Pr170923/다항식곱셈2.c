#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

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

void main()
{
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

void AddNode(POLY head, float coef, int expr)
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
		if (expr >= (p->expr))
		{
			equal = ((expr == p->expr) ? 1 : 0);
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