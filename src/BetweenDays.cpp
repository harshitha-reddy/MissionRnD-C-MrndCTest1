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

struct Date
{
	int day, mnth, year;
};
int countLeapYears(struct Date *leap);
int findDifference(struct Date *date1,struct Date *date2);

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	int result;
	Date *date1 = (struct Date *)malloc(sizeof(struct Date));
	Date *date2 = (struct Date *)malloc(sizeof(struct Date));
	date1->day = (date1head->data) * 10 + (date1head->next->data);
	struct node *date1Temp = date1head->next->next;
	date1->mnth = (date1Temp->data) * 10 + (date1Temp->next->data);
	date1Temp = date1Temp->next->next;
	date1->year = (date1Temp->data) * 1000 + (date1Temp->next->data) * 100 + (date1Temp->next->next->data) * 10 + (date1Temp->next->next->next->data);

	date2->day = (date2head->data) * 10 + (date2head->next->data);
	struct node *date2Temp = date2head->next->next;
	date2->mnth = (date2Temp->data) * 10 + (date2Temp->next->data);
	date2Temp = date2Temp->next->next;
	date2->year = (date2Temp->data) * 1000 + (date2Temp->next->data) * 100 + (date2Temp->next->next->data) * 10 + (date2Temp->next->next->next->data);

	if (date1->mnth == date2->mnth || date1->day == date2->day || date1->year == date2->year)
		return 0;

	result = findDifference(date1, date2);

	return result;
}
const int days_Months[12] = { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };

int countLeapYears(struct Date *leap)
{
	int years = leap->year;
	if (leap->mnth <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}

int findDifference(struct Date *date1, struct Date *date2)
{
	long int days_1 = date1->year * 365 + date1->day;

	for (int i = 0; i<date1->mnth - 1; i++)
		days_1 += days_Months[i];
	days_1 += countLeapYears(date1);


	long int days_2 = date2->year * 365 + date2->day;
	for (int i = 0; i<date2->mnth - 1; i++)
		days_2 += days_Months[i];
	days_2 += countLeapYears(date2);

	return (days_2 - days_1);
}
