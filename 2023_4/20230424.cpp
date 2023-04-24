/*
https://www.acmicpc.net/problem/5430
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FUNCTION_LEN (100000)
#define MAX_NUM_COUNT (100000)

static char function_string[MAX_FUNCTION_LEN + 1];
static char numbers_string[400002]; //(최대 3자리 + 콤마 ) * 10만개 + [ + ] + 널문자
static int numbers[MAX_NUM_COUNT];

typedef enum error_code {
	DEQUEUE_EMPTY_QUEUE = -1
} error_code_t;

typedef enum position {
	FRONT,
	BACK
} position_t;

typedef struct queue {
	int* numbers;
	int front;
	int back;
	int pop_position;
	int number_count;
} queue_t;

int* initiate_queue_malloc(queue_t* q, int* numbers, const int num_count) {

	if (num_count == 0) {
		q->numbers = NULL;
	}
	else {
		q->numbers = malloc(sizeof(int) * num_count);
	}

	for (int i = 0; i < num_count; ++i) {
		q->numbers[i] = numbers[i];
	}

	q->front = 0;
	q->back = num_count - 1;
	q->number_count = num_count;
	q->pop_position = FRONT;

	return q->numbers;
}

int dequeue_front(queue_t* q) {
	int ret = q->numbers[q->front++];
	--q->number_count;
	return ret;
}

int dequeue_back(queue_t* q) {
	int ret = q->numbers[q->back--];
	--q->number_count;
	return ret;
}

int dequeue(queue_t* q) {
	int ret;

	if (q->pop_position == FRONT) {
		ret = dequeue_front(q);
		return ret;
	}

	ret = dequeue_back(q);
	return ret;
}

void print_queue_front_to_back(const queue_t* q) {
	putchar('[');
	for (int i = q->front; i < q->back; ++i) {
		printf("%d,", q->numbers[i]);
	}
	printf("%d]", q->numbers[q->back]);
}

void print_queue_back_to_front(const queue_t* q) {
	putchar('[');
	for (int i = q->back; i > q->front; --i) {
		printf("%d,", q->numbers[i]);
	}
	printf("%d]", q->numbers[q->front]);
}

void print_empty_queue(void) {
	printf("[]");
}
void print_queue(queue_t* q) {

	if (q->number_count == 0) {
		print_empty_queue();
		putchar('\n');
		return;
	}

	if (q->pop_position == FRONT) {
		print_queue_front_to_back(q);
		putchar('\n');
		return;
	}

	print_queue_back_to_front(q);
	putchar('\n');
}

int execute_functions(char* function_set, queue_t* q) {
	char* p = function_set;
	while (*p != '\0') {
		if (*p == 'R') { // 뒤집기
			q->pop_position = q->pop_position == FRONT ? BACK : FRONT;
		}
		else if (*p == 'D') { // 버리기
			if (q->number_count == 0) {
				return DEQUEUE_EMPTY_QUEUE;
			}
			dequeue(q);
		}
		++p;
	}

	return 0;
}

int main(void) {
	int test_case_count;
	int num_count;
	int* temp;

	scanf("%d", &test_case_count);

	queue_t my_queue;
	my_queue.back = -1;
	my_queue.front = 0;
	my_queue.number_count = 0;
	my_queue.pop_position = FRONT;

	for (int i = 0; i < test_case_count; ++i) {
		char* pnum;

		scanf("%s", function_string);
		scanf("%d", &num_count);
		scanf("%s", numbers_string);

		pnum = strtok(numbers_string, "[,]");
		if (pnum != NULL) {
			numbers[0] = atoi(pnum);
		}

		for (int j = 1; j < num_count; ++j) {
			numbers[j] = atoi(strtok(NULL, "[,]"));
		}

		temp = initiate_queue_malloc(&my_queue, numbers, num_count);

		if (execute_functions(function_string, &my_queue) == DEQUEUE_EMPTY_QUEUE) {
			printf("error\n");
		}
		else {
			print_queue(&my_queue);
		}

		free(temp);
	}

}
