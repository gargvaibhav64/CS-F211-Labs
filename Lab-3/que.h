typedef enum {FALSE, TRUE} Boolean;

typedef struct {
	int ele;
	struct Ele * next;
}Ele;

typedef Ele * Element;

typedef struct {
	int count;
	Element first;
	Element last;
}Que;

typedef Que * Queue;

Queue newQ();

Boolean isEmptyQ(Queue q);

Queue delQ(Queue q);

Element front(Queue q);

Queue addQ(Queue q, Element e);

int lengthQ(Queue q);
