#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
  node* temp = head;
  int count = 0;
  while(temp != NULL)//increments for every node
    {
      count++;
      temp = temp->next;
    }
  return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
  node* temp = head;
  int len = length(head);//use length function to calculate the length of the string

  char* str = (char*)malloc((len + 1) * sizeof(char));//allocate memory for the string

  if (str == NULL) {//checking if NULL
      return NULL;
  }

  while (temp != NULL) {
    for(int i = 0; i < len; i++)
      {
        str[i] = temp->letter;//place the letter stored in the node to the same index of the string
        temp = temp->next;
      }
  }

  return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
  node* newNode = (node*)malloc(sizeof(node));

  if (newNode == NULL) {
      exit(-1); 
  }
  
  //transvering the data
  newNode->letter = c;
  newNode->next = NULL;
  
  if (*pHead==NULL)
  {
    *pHead = newNode;
  }
  else{
    node* temp = *pHead;
    while(temp->next != NULL)
      {
        temp= temp-> next;
      }
    temp-> next = newNode;
  }
  
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
  node* temp = *pHead;
  node* nextNode;
  while(temp != NULL)
    {
      nextNode = temp->next;
      free(temp);
      temp = nextNode;
    }
  *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}