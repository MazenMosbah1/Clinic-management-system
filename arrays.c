#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void patient_one();
void patient_two();
void patient_three();
void patient_four();
void patient_five();
void patient_six();
int arrayOfAges[6];
char *arrayOfGenders[6];
int arrayOfIDs[6];
char arrayOfNames[6][10]; /* the first number is the number of names and the second is the maximum letters allowed for name */
	
#define arraySize 6
void main(void){
	
	/* Array For Patient's Ages */
	printf("Enter the ages of the patients\n");
	for(int i = 0; i <= arraySize - 1; i++)
	{
		printf("Patient Number #%d: ", i+1);
		scanf(" %d", &arrayOfAges[i]);
	}
	printf("--------------------------------------\n");
	/* Array For Patient's Names */
	printf("Enter the names of patients\n");
	for(int i = 0; i <= arraySize - 1; i++)
	{
		printf("Patient Number #%d: ", i+1);	
		scanf(" %s", &arrayOfNames[i]);
	}
	printf("--------------------------------------\n");
	/* Array For Patient's Genders */
	printf("Enter the Genders of patients\n");
	for(int i = 0; i <= arraySize - 1; i++)
	{
		printf("Patient Number #%d: ", i+1);	
		scanf(" %s", &arrayOfGenders[i]);
	}
	printf("--------------------------------------\n");
	/* Array For Patient's IDs */
	printf("Enter the IDs of the patients\n");
	for(int i = 0; i <= arraySize - 1; i++)
	{
		printf("Patient Number #%d: ", i+1);
		scanf(" %d", &arrayOfIDs[i]);
	}
	
	patient_one();
	printf("--------------------\n");
	patient_two();
	printf("--------------------\n");
	patient_three();
	printf("--------------------\n");
	patient_four();
	printf("--------------------\n");
	patient_five();
	printf("--------------------\n");
	patient_six();
}
void patient_one()
{
	/* print the first patient's information */
	printf("-----Patient Number 1-----\n");
	printf("Name is %s\n", arrayOfNames[0]);
	printf("Age is %d\n", arrayOfAges[0]);
	printf("Gender is %c\n", arrayOfGenders[0]); /* changed this from printing a string to printing a char */
	printf("ID is %d\n", arrayOfIDs[0]);
}

void patient_two()
{
	/* print the second patient's information */
	printf("-----Patient Number 2-----\n");
	printf("Name is %s\n", arrayOfNames[1]);
	printf("Age is %d\n", arrayOfAges[1]);
	printf("Gender is %c\n", arrayOfGenders[1]); /* changed this from printing a string to printing a char */
	printf("ID is %d\n", arrayOfIDs[1]);
}

void patient_three()
{
	/* print the third patient's information */
	printf("-----Patient Number 3-----\n");
	printf("Name is %s\n", arrayOfNames[2]);
	printf("Age is %d\n", arrayOfAges[2]);
	printf("Gender is %c\n", arrayOfGenders[2]); /* changed this from printing a string to printing a char */
	printf("ID is %d\n", arrayOfIDs[2]);
}

void patient_four()
{
	/* print the fourth patient's information */
	printf("-----Patient Number 4-----\n");
	printf("Name is %s\n", arrayOfNames[3]);
	printf("Age is %d\n", arrayOfAges[3]);
	printf("Gender is %c\n", arrayOfGenders[3]); /* changed this from printing a string to printing a char */
	printf("ID is %d\n", arrayOfIDs[3]);
}

void patient_five()
{
	/* print the fifth patient's information */
	printf("-----Patient Number 5-----\n");
	printf("Name is %s\n", arrayOfNames[4]);
	printf("Age is %d\n", arrayOfAges[4]);
	printf("Gender is %c\n", arrayOfGenders[4]); /* changed this from printing a string to printing a char */
	printf("ID is %d\n", arrayOfIDs[4]);
}

void patient_six()
{
	/* print the sixth patient's information */
	printf("-----Patient Number 6-----\n");
	printf("Name is %s\n", arrayOfNames[5]);
	printf("Age is %d\n", arrayOfAges[5]);
	printf("Gender is %c\n", arrayOfGenders[5]); /* changed this from printing a string to printing a char */
	printf("ID is %d\n", arrayOfIDs[5]);
}