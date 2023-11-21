#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

struct Cell
{
	int vol;
	struct Cell* next;
};
typedef struct Cell Cell;

int appStart(Cell* head, int vol) {
	Cell* pNewCell;
	if (!(pNewCell =(Cell*)malloc(sizeof(Cell)))) {
		return 0;
	}

	pNewCell->next = head->next;
	head->next = pNewCell;
	pNewCell->vol = vol;
	return 1;
}

int main() {
	char inp;
	int num;
	Cell head = { -1, NULL };
	Cell* pointer, *remPointer;

	while (scanf("%i", &num))
	{
		if (!(appStart(&head, num))) {
			printf("NOT ENOUGH MEMORY!");
			return 1;
		}
	}

	if (head.next == NULL) {
		printf("NULL");
		return 0;
	}

	pointer = head.next;
	while (pointer != NULL){
		printf("%i ", pointer->vol);
		pointer = pointer->next;
	}

	pointer = head.next;
	while (pointer != NULL){
		remPointer = pointer->next;
		free(pointer);
		pointer = remPointer;
	}
}
