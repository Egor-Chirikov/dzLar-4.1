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
	if (!(pNewCell =(Cell*)(malloc(sizeof(Cell))))) {
		return 0;
	}

	pNewCell->next = head->next;
	head->next = pNewCell;
	pNewCell->vol = vol;
	return 1;
}

int main() {
	char inp;
	int num, fNewNum, fend = 0;
	Cell head = { -1, NULL };
	Cell* pointer, *remPointer;

	while (42)
	{
		if (fend)
			break;

		num = 0;
		fNewNum = 0;
		while (42) {
			scanf("%c", &inp);
			if (inp == ' ')
				break;
			if (inp == '.') {
				fend = 1;
				break;
			}

			num *= 10;
			num += inp - '0';
			fNewNum = 1;
		}

		if (fNewNum) {
			if (!(appStart(&head, num))) {
				printf("NOT ENOUGH MEMORY!");
				return 1;
			}
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
