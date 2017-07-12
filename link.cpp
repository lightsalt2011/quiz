#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int ele;
	struct node *next;

}node_t;

node_t *head;

static void create_link(node_t *p1)
{
	int value;
	node_t *p_new;

	p1 = (node_t *)malloc(sizeof(node_t));
	if (p1 == NULL)
		return ;

	printf("enter you wanna\n");
	scanf("%d", &value);

	p1->ele = value;
	p1->next = NULL;

	head = p1;
	//p2 = p1;

	do {

		p_new = (node_t *)malloc(sizeof(node_t));
		
		printf("enter you wanna\n");
		scanf("%d", &value);
		p_new->ele = value;
		p_new->next = NULL;

		p1->next = p_new;
		p1 = p_new;

	}while(p_new->ele > 0);

	return ;
}

static void print_link(void)
{
	node_t *p = head;

	printf("%s\n", __func__);

	while(p != NULL) {

		printf("%d \t", p->ele);
		p = p->next;
	}
	printf("\n");
}

static void swap(int *k, int *i)
{
	int tmp;

	tmp = *k;
	*k = *i;
	*i = tmp;
}

static void sort_link()
{
	node_t *i=head;
	node_t *j, *k;

	for (; i!=NULL; i=i->next) {

		printf("test %d\n", i->ele);
		k = i;

		for(j=i->next; j!=NULL; j=j->next) {

			if (k->ele > j->ele)
				k = j;
		}

		if (k != i)
			swap(&k->ele, &i->ele);
	}
}
#if 0
static void delete_link(node_t *cur)
{

	assert(cur != NULL);
	assert(cur->next != NULL);

	node_t *pnext;

	pnext = cur->next;

	cur->ele = pnext->ele;

	cur->next = pnext->next;

	free pnext;
}
#endif

static void reversebyloop(void)
{
	node_t *priv = NULL;
	node_t *cur = head;
	node_t *pnext = NULL;


	while(cur->next != NULL) {
	
		pnext = cur->next;

		cur->next = priv;

		priv = cur;

		cur = pnext;

	}

	cur->next = priv;

	head = cur;
}

/*
Node* reverseByLoop(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node *pre = NULL;
    Node *next = NULL;
    while(head != NULL)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
*/
static void reversebyrecursion(node_t *head)
{

}

int main(int argc, char **argv)
{
	node_t *p1, *p2;

	if (p1 == NULL)
		create_link(p1);	

	print_link();

	sort_link();

	print_link();

	reversebyloop();

	print_link();


}