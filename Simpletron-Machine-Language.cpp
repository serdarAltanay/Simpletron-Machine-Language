#include<stdio.h>

// Declaration Of OPCodes
//input-output operations:
#define READ 10
#define WRITE 11

//load-store operations:

#define LOAD 20
#define STORE 21

//arithmetic operations:

#define ADD 30 
#define SUBSTRACT 31
#define DIVIDE 32
#define MULTIPLY 33

//transfer-of-control operations:

#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

// Declaration of other variables
#define MEMSIZE 100

static int memory[MEMSIZE];
static int accumulator = 0000;
static int insregister = 0000;
static int counter = 00;
static int operationcode = 00;
static int operand = 00;
static int simpletron();
static void loadprogram();
static void printregisters();
static void printcurrentmemory();


int main(void) {
	//initilazation of empty memory
	for (int i = 0; i < MEMSIZE; i++) {
		memory[i] = 0;
	}
	printf("start typing your program\n");
	loadprogram();
	simpletron();
	printregisters();
	printcurrentmemory();
}

static int simpletron() {

	while (counter < MEMSIZE) {
		insregister = memory[counter];
		operationcode = insregister / 100;
		operand = insregister % 100;
		switch (operationcode) {
		case READ:
			printf("Vaiting for intager value:\n");
			scanf_s("%d", &memory[operand]);
			counter++;
			break;
		case WRITE:
			printf("%d\n", memory[operand]);
			counter++;
			break;
		case LOAD:
			accumulator = memory[operand];
			counter++;
			break;
		case STORE:
			memory[operand] = accumulator;
			counter++;
			break;
		case ADD:
			accumulator += memory[operand];
			counter++;
			break;
		case SUBSTRACT:
			accumulator -= memory[operand];
			counter++;
			break;
		case DIVIDE:
			accumulator /= memory[operand];
			counter++;
			break;
		case MULTIPLY:
			accumulator *= memory[operand];
			counter++;
			break;
		case BRANCH:
			counter = operand;
			break;
		case BRANCHNEG:
			if (accumulator < 0) {
				counter = operand;
			}
			else {
				counter++;
			}
			break;
		case BRANCHZERO:
			if (accumulator == 0) {
				counter = operand;
			}
			else {
				counter++;
			}
			break;
		case HALT:
			return 0;
		default:
			printf("%+05d: invalid instruction\n", insregister);
			return 1;
		}
	};
}

static void loadprogram() {
	int counter = 0;
	int code = 0;
	while (true) {
		scanf_s("%d", &code);
		if (code == -99999) {
			break;
		}
		memory[counter] = code;
		printf("%d code was written in memory location %d. \n", code, counter);
		counter++;
	}
	printf("***Program loading completed***\n");
	printf("***Program execution begins***\n");
}

static void printregisters() {
	printf("REGISTERS:\n");
	printf("accumulator:  %d\n", accumulator);
	printf("instructionCounter:  %d\n", counter);
	printf("instructionRegister:  %d\n", insregister);
	printf("operationCode:  %d\n", operationcode);
	printf("operand:  %d\n", operand);
}

static void printcurrentmemory() {
	printf("MEMORY:\n");
	int row = 10;
	int col = 10;
	printf("      ");
	for (int i = 0; i < 10; i++) {
		printf("%6d", i);
	}
	printf("\n");
	for (int i = 0; i < row; i++) {
		printf("%6d", i * 10);
		for (int k = 0; k < col; k++) {
			printf("%+6d", memory[(k * 10) + i]);
		}
		printf("\n");

	}
}
