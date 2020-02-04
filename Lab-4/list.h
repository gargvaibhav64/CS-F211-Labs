typedef struct node {
	int ele;
	struct node * next;
}Node;

typedef struct ll {
	int size;
	Node * first;
}LinkedList;