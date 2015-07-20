#include<stdio.h>
#define BST_SIZE 30
#define START_INDEX 1
int bst[BST_SIZE+1];

void init();

void insert(int newNumber);
int search(int target);
void printAllNode();

void setLeftChild(int newValue);
void setRightChild(int newValue);

int main() {
	int count;
	int num;
	int targetNum;
	int resultIndex;
	init();
	scanf("%d", &count);
	while(count--) {
		scanf("%d", &num);
		insert(num);
	}
	scanf("%d", &targetNum);
	resultIndex = search(targetNum);
	printf("result : %d\n", resultIndex);
	printAllNode();

	return 0;
}

void init() {
	for(int i=0; i<BST_SIZE+1; i++) {
		bst[i] = -1;
	}
}

void insert(int newNumber) {
	for(int i=START_INDEX; i<BST_SIZE+1; ) {
		if( bst[i] == -1) {
			bst[i] = newNumber;
			return;
		}
	//	bst[i]>newNumber ? (i *= 2) : (i = i*2+1);
		if(bst[i] < newNumber) 
			i=i*2+1;
		else
			i*=2;
	}
}

void printAllNode() {
	for(int i=START_INDEX; i<BST_SIZE+1; i++) {
	//	if(bst[i] == -1)
	//		continue;
		printf("%d ",bst[i]);
	}
	printf("\n");
}

int search(int targetNum) {
	for(int i=START_INDEX; i<BST_SIZE+1;) {
		if(bst[i] == targetNum)
			return i;
		if(bst[i] < targetNum) 
			i=i*2+1;
		else
			i*=2;
	}
}
