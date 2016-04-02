/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL||date2head == NULL)
		return -1;
	struct node *temp1 = NULL, *temp2 = NULL;
	temp1 = (struct node *)malloc(sizeof(struct node));
	temp2 = (struct node *)malloc(sizeof(struct node));
	temp1 = date1head;
	temp2 = date2head;
	int Arr1[10], Arr2[10], i = 0, j = 0, D1 = 0, D2 = 0, M1 = 0, M2 = 0, Y1 = 0, Y2 = 0, Day_count = 0;
	while (temp1 != NULL&&temp2 != NULL){
		Arr1[i] = temp1->data;
		i++;
		Arr2[j] = temp2->data;
		j++;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	for (i = 0; i < 2; i++)
		D1 = 10 * D1 + Arr1[i];
	for (i = 0; i < 2; i++)
		D2 = 10 * D2 + Arr2[i];
	for (i = 2; i < 4; i++)
		M1 = 10 * M1 + Arr1[i];
	for (i = 2; i < 4; i++)
		M2 = 10 * M2 + Arr2[i];
	for (i = 4; i < 8; i++)
		Y1 = 10 * Y1 + Arr1[i];
	for (i = 4; i < 8; i++)
		Y2 = 10 * Y2 + Arr2[i];
	if (D1 == D2&&M1 == M2&&Y1 == Y2){
		if (D1 == 31 && D2 == 1 || D1 == 30 && D2 == 1)
			return -1;
	}
	if (D1>D2&&M1 == M2&&Y1 == Y2){
		if (D1 == 31 || D1 == 30){
			Day_count = D2 - 1;
		}
		else
			Day_count = D1 - D2 - 1;
	}
	if (D1<D2&&M1 == M2&&Y1 == Y2){
		Day_count = D2 - D1 - 1;
	}
	return Day_count;
}