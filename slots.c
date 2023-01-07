#include <stdio.h>

void available_slots();

void main(void)
{
	available_slots();
}

void available_slots()
{
	int slots[6] = {0};
	int user_input;
	printf("Enter Num 1 to choose first reservation\n");
	printf("Enter Num 2 to choose second reservation\n");
	printf("Enter Num 3 to choose third reservation\n");
	printf("Enter Num 4 to choose fourth reservation\n");
	printf("Enter Num 5 to choose fifth reservation\n");
	printf("Enter Num 6 to choose sixth reservation\n");
	printf("Your choice: ");
	scanf(" %d", &user_input);
	if(user_input == 1)
	{
		if(slots[0] == 0)
		{
			printf("Reservation Done\n");
			slots[0] = 1;
		}
	}
	else if(user_input == 2)
	{
		if(slots[1] == 0)
		{
			printf("Reservation Done\n");
			slots[1] = 1;
		} 
	}
	else if(user_input == 3)
	{
		if(slots[2] == 0)
		{
			printf("Reservation Done\n");
			slots[2] = 1;
		} 
	}
	else if(user_input == 4)
	{
		if(slots[3] == 0)
		{
			printf("Reservation Done\n");
			slots[3] = 1;
		} 
	}
	else if(user_input == 5)
	{
		if(slots[4] == 0)
		{
			printf("Reservation Done\n");
			slots[4] = 1;
		} 
	}
	else if(user_input == 6)
	{
		if(slots[5] == 0)
		{
			printf("Reservation Done\n");
			slots[5] = 1;
		} 
	}
	else 
	{
			printf("Wrong Input!\n");
	}
}