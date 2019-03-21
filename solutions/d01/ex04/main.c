#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	struct s_queue *q = queueInit();
	enqueue(q, "Hello");
	enqueue(q, "my");
	enqueue(q, "beautiful");
	enqueue(q, "queue");
	printf("- %s\n", dequeue(q));

	struct s_node *node = q->first;
	while (node)
	{
		printf("+ %s\n", node->message);
		node = node->next;
	}

	printf("- %s\n", dequeue(q));
	printf("- %s\n", dequeue(q));
	printf("- %s\n", dequeue(q));
	printf("- %s\n", dequeue(q));
	printf("isEmpty: %d\n\n", isEmpty(q));

	node = q->first;
	while (node)
	{
		printf("+ %s\n", node->message);
		node = node->next;
	}

	printf("peek: %s\n", peek(q));
	enqueue(q, "Hello");
	enqueue(q, "my");
	enqueue(q, "beautiful");
	enqueue(q, "world");

	while (node)
	{
		printf("+ %s\n", node->message);
		node = node->next;
	}

	printf("peek: %s\n", peek(q));
	printf("isEmpty: %d\n", isEmpty(q));

	return (0);
	return (0);
}



// Function used for the test
// Don't go further :)

