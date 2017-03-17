#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct link {
    struct link *next;
    int data;
};


struct link *head = NULL;


void insert(int data) {
    struct link *tmp;
    struct link *new;

    new = malloc(sizeof(struct link));
    if (new == NULL) return;

    new->data = data;
    new->next = NULL;

    if (head == NULL) {
	head = new;
	return;
    }

    tmp = head;
    while (tmp->next != NULL) {
	tmp = tmp->next;
    }

    tmp->next = new;
}

void print_list(void) {
    struct link *tmp;
    int i = 0;

    while (tmp != NULL) {
	printf(" -> %d:%d", i, tmp->data);	
	tmp = tmp->next;
	i++;
    }
}

int main(int argc, char *argv[]) {
    insert(5);
    insert(3);
    insert(1);
    insert(-1);
    insert(-3);
    insert(-5);

    print_list();

    return 0;
}


