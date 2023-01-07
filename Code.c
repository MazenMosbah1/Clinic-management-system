/* Description */
/* This project is about clinic management system */
/* It has two modes => first mode is an admin mode, second mode is a user mode */
/* In Admin mode: the system asks fo passwords with 3 trials for login,
What Admins Can Do ?
- Add new patient record:
	To add a new patient, the user shall admin shall enter these basic information: name, age, gender and
	ID. The ID shall be unique for the user, if the entered ID is already exists, the system shall reject the
	entry.
- Edit patient record:
	By entering patient ID the system shall checks if the ID exists, the system shall allow the user to edit the
	patient information. If not, the system shall display incorrect ID message.
- Reserve a Slot with a doctor :
	By default there are 5 available slots, 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm
	and 4:30pm to 5pm. Upon opening of this window, the system shall display the available slots. The
	admin shall enter the patient ID and the desired slot. The reserved slot shall not appear again in the next
	patient reservation.
- Cancel reservation */
/* -------------------------------------------*/
/* In user mode => There is no passwords, Users can do these:
- View patient record
- By adding patient ID, the system will show some basic information
- View today's reservation


@Author => Mazen Mosbah
@All rights Reserved

 */

/* -------------------------------------------*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "STD_TYPES.h"

void patient_one();
void patient_two();
void patient_three();
void patient_four();
void patient_five();
void patient_six();
void patientInformation();
void patientInformationOnly();
void edit_patient_information();
void Check_Before_Reservation();
void Reservation();
void available_slots();
u8 slots[6][15] = {"2pm to 2:30pm", "2:30pm to 3pm", "3pm to 3:30pm", "3:30pm to 4pm", "4pm to 4:30pm", "4:30pm to 5pm"};
void slots_choice();
u16 *arrayOfAges[6];
u8 *arrayOfGenders[6];
u32 arrayOfIDs[6];
u8 arrayOfNames[6][10]; /* the first number is the number of names and the second is the maximum letters allowed for name */

/* New Information for patient_one */
u8 *patientOneNewName[6][10];
u16 patientOneNewAge;
u32 patientOneNewId;
u8 *patientOneNewGender[6];

#define arraySize 6

void admin_mode();
void admin_features();
void user_mode();
void user_mode_after_added_patients();
void optionsBack();
u16 check_mode;
u32 pass;
u32 dpass = 1234;
u16 attempts;
u16 times = 0;
u32 ID_Check;
u32 ID_Check_Again;
u16 option;
u16 Empty = 0;

void main(void)
{

	printf("----------Welcome----------\n"
		   "choose between admin mode and user mode\n"
		   "Enter Number 1 for admin mode\n"
		   "Enter Number 2 for user mode\n"
		   "Enter Number 3 to exit\n"
		   "Enter The Number: ");
	scanf(" %d", &check_mode);

	switch (check_mode)
	{
	case 1:
		admin_mode();
		break;

	case 2:
		user_mode();
		break;

	case 3:
		printf("See You Soon\n");
		break;

	default:
		printf("Wrong Input! Please Try Again");
	}
}

void admin_mode()
{
	printf("----------Hello Admin----------\n");
	printf("Please Enter Your Password: ");
	scanf(" %d", &pass);
	if (pass == dpass)
	{
		printf("-----login successful-----\n");
		optionsBack();
	}
	else if (pass != dpass)
	{
		printf("Incorrect Password, Please Try Again: ");
		scanf(" %d", &attempts);
		if (attempts == dpass)
		{
			printf("-----login successful-----\n");
			optionsBack();
		}
		while (attempts != dpass)
		{
			times++;
			printf("Try Again: ");
			scanf(" %d", &attempts);
			if (attempts == dpass)
			{
				printf("-----login successful-----\n");
				optionsBack();
			}
			else if (times > 1)
			{
				printf("You Are Restricted!");
				break;
			}
		}
	}
	else
	{
		printf("You Are Not Registered");
	}
}

void optionsBack()
{
	printf("-----OPTIONS-----\n");
	printf("[1] Add new patients\n"
		   "[2] Edit patient's information\n"
		   "[3] View patients' information\n"
		   "[4] View available appointment\n"
		   "Your Choice: ");
	scanf(" %d", &option);

	switch (option)
	{
	case 1:
		admin_features();
		break;

	case 2:
		printf("Please, Add patients first\n");
		admin_features();
		break;

	case 3:
		printf("Please, Add patients first\n");
		admin_features();
		break;

	case 4:
		available_slots();
		break;

	default:
		printf("Wrong Input!");
	}
}

void admin_features()
{
	printf("Available Appointments\n");
	printf("2pm to 2:30pm\n"
		   "--------------\n"
		   "2:30pm to 3pm\n"
		   "--------------\n"
		   "3pm to 3:30pm\n"
		   "--------------\n"
		   "3:30pm to 4pm\n"
		   "--------------\n"
		   "4pm to 4:30pm\n"
		   "--------------\n"
		   "4:30pm to 5pm\n"
		   "--------------\n");

	/* Array For Patient's Ages */
	printf("Enter the ages of the patients\n");
	for (u16 i = 0; i <= arraySize - 1; i++)
	{
		printf("Patient Number #%d: ", i + 1);
		scanf(" %d", &arrayOfAges[i]);
	}
	printf("--------------------------------------\n");
	/* Array For Patient's Names */
	printf("Enter the names of patients\n");
	for (u16 i = 0; i <= arraySize - 1; i++)
	{
		printf("Patient Number #%d: ", i + 1);
		scanf(" %s", &arrayOfNames[i]);
	}
	printf("--------------------------------------\n");
	/* Array For Patient's Genders */
	printf("Enter the Genders of patients\n");
	for (u16 i = 0; i <= arraySize - 1; i++)
	{
		printf("Patient Number #%d: ", i + 1);
		scanf(" %s", &arrayOfGenders[i]);
	}
	printf("--------------------------------------\n");
	/* Array For Patient's IDs */

	printf("Enter the IDs of the patients\n");
	for (u16 i = 0; i <= arraySize - 1; i++)
	{
		u32 value = arrayOfIDs[0];
		u32 value_two = arrayOfIDs[1];
		u32 value_three = arrayOfIDs[2];
		u32 value_four = arrayOfIDs[3];
		u32 value_five = arrayOfIDs[4];
		u32 value_six = arrayOfIDs[5];
		printf("Patient Number #%d: ", i + 1);
		scanf(" %d", &arrayOfIDs[i]);
		if (value == arrayOfIDs[i])
		{
			printf("The ID is already exists!\n");
			printf("Enter another ID: ");
			scanf(" %d", &arrayOfIDs[i]);
		}
		else if (value_two == arrayOfIDs[i])
		{
			printf("The ID is already exists!\n");
			printf("Enter another ID: ");
			scanf(" %d", &arrayOfIDs[i]);
		}
		else if (value_three == arrayOfIDs[i])
		{
			printf("The ID is already exists!\n");
			printf("Enter another ID: ");
			scanf(" %d", &arrayOfIDs[i]);
		}
		else if (value_four == arrayOfIDs[i])
		{
			printf("The ID is already exists!\n");
			printf("Enter another ID: ");
			scanf(" %d", &arrayOfIDs[i]);
		}
		else if (value_five == arrayOfIDs[i])
		{
			printf("The ID is already exists!\n");
			printf("Enter another ID: ");
			scanf(" %d", &arrayOfIDs[i]);
		}
		else if (value_six == arrayOfIDs[i])
		{
			printf("The ID is already exists!\n");
			printf("Enter another ID: ");
			scanf(" %d", &arrayOfIDs[i]);
		}
		else
		{
			printf("ID added successfully!\n");
		}
	}

	patientInformation();
	printf("--------------------\n");
	printf("--------------------\n");
	edit_patient_information();
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

void patientInformation()
{
	u16 found;
	printf("Enter the number of patients you added: ");
	scanf(" %d", &found);
	if (found != 6)
	{
		printf("Wrong!\n");
		printf("Try Again: ");
		scanf(" %d", &found);
	}

	else if (found == 6)
	{
		printf("-----This is User Check-----\n"
			   "Enter patient's ID to check: ");
		scanf(" %d", &ID_Check);
		if (ID_Check == arrayOfIDs[0])
		{
			patient_one();
		}
		else if (ID_Check == arrayOfIDs[1])
		{
			patient_two();
		}
		else if (ID_Check == arrayOfIDs[2])
		{
			patient_three();
		}
		else if (ID_Check == arrayOfIDs[3])
		{
			patient_four();
		}
		else if (ID_Check == arrayOfIDs[4])
		{
			patient_five();
		}
		else if (ID_Check == arrayOfIDs[5])
		{
			patient_six();
		}
		else
		{
			printf("This ID Not Exist!");
		}
	}
}

void patientInformationOnly()
{
	u32 ID_Check_For_User;
	printf("Enter your ID to check: ");
	scanf(" %d", &ID_Check_For_User);
	if (ID_Check_For_User == arrayOfIDs[0])
	{
		patient_one();
	}
	else if (ID_Check_For_User == arrayOfIDs[1])
	{
		patient_two();
	}
	else if (ID_Check_For_User == arrayOfIDs[2])
	{
		patient_three();
	}
	else if (ID_Check_For_User == arrayOfIDs[3])
	{
		patient_four();
	}
	else if (ID_Check_For_User == arrayOfIDs[4])
	{
		patient_five();
	}
	else if (ID_Check_For_User == arrayOfIDs[5])
	{
		patient_six();
	}
	else
	{
		printf("No Information yet\n");
		printf("Please let admin add information first\n");
		admin_mode();
	}
}

void edit_patient_information()
{
	u16 yesOrNoCheck;
	printf("Do you want to edit patient's information ?\n");
	printf("Enter Num 1 for yes\n"
		   "Enter Num 2 for No\n"
		   "Your Choice: ");
	scanf(" %d", &yesOrNoCheck);
	switch (yesOrNoCheck)
	{
	case 1:
		printf("Enter the ID of patient: ");
		scanf(" %d", &ID_Check_Again);
		if (ID_Check_Again == arrayOfIDs[0])
		{
			patient_one();
		}
		else if (ID_Check_Again == arrayOfIDs[1])
		{
			patient_two();
		}
		else if (ID_Check_Again == arrayOfIDs[2])
		{
			patient_three();
		}
		else if (ID_Check_Again == arrayOfIDs[3])
		{
			patient_four();
		}
		else if (ID_Check_Again == arrayOfIDs[4])
		{
			patient_five();
		}
		else if (ID_Check_Again == arrayOfIDs[5])
		{
			patient_six();
		}
		else
		{
			printf("This ID Not Exist!");
		}
		break;

	case 2:
		// Reservation();
		break;
	}
	if (ID_Check_Again == arrayOfIDs[0])
	{
		printf("Enter the New Name: ");
		scanf(" %s", &arrayOfNames[0]);
		printf("Enter The New Age: ");
		scanf(" %d", &arrayOfAges[0]);
		printf("---Here is New Patient's Information---\n");
		patient_one();
	}
	else if (ID_Check_Again == arrayOfIDs[1])
	{
		printf("Enter the New Name: ");
		scanf(" %s", &arrayOfNames[1]);
		printf("Enter The New Age: ");
		scanf(" %d", &arrayOfAges[1]);
		printf("---Here is New Patient's Information---\n");
		patient_two();
	}
	else if (ID_Check_Again == arrayOfIDs[2])
	{
		printf("Enter the New Name: ");
		scanf(" %s", &arrayOfNames[2]);
		printf("Enter The New Age: ");
		scanf(" %d", &arrayOfAges[2]);
		printf("---Here is New Patient's Information---\n");
		patient_three();
	}
	else if (ID_Check_Again == arrayOfIDs[3])
	{
		printf("Enter the New Name: ");
		scanf(" %s", &arrayOfNames[3]);
		printf("Enter The New Age: ");
		scanf(" %d", &arrayOfAges[3]);
		printf("---Here is New Patient's Information---\n");
		patient_four();
	}
	else if (ID_Check_Again == arrayOfIDs[4])
	{
		printf("Enter the New Name: ");
		scanf(" %s", &arrayOfNames[4]);
		printf("Enter The New Age: ");
		scanf(" %d", &arrayOfAges[4]);
		printf("---Here is New Patient's Information---\n");
		patient_five();
	}
	else if (ID_Check_Again == arrayOfIDs[5])
	{
		printf("Enter the New Name: ");
		scanf(" %s", &arrayOfNames[5]);
		printf("Enter The New Age: ");
		scanf(" %d", &arrayOfAges[5]);
		printf("---Here is New Patient's Information---\n");
		patient_six();
	}

	Reservation();
}

void Check_Before_Reservation()
{
	u16 yesOrNoCheck_two;
	printf("Before Reservation, Do you want to edit any information\n"
		   "Enter Num 1 for yes\n"
		   "Enter Num 2 for No\n"
		   "Your Choice: ");
	scanf(" %d", &yesOrNoCheck_two);
	switch (yesOrNoCheck_two)
	{
	case 1:
		edit_patient_information();
		break;

	case 2:
		available_slots();
		break;
	}
}

void available_slots()
{
	u16 slots[6] = {0};
	u16 user_input, user_input_again;
	printf("Enter Num 1 to choose first reservation\n");
	printf("Enter Num 2 to choose second reservation\n");
	printf("Enter Num 3 to choose third reservation\n");
	printf("Enter Num 4 to choose fourth reservation\n");
	printf("Enter Num 5 to choose fifth reservation\n");
	printf("Enter Num 6 to choose sixth reservation\n");
	printf("Your choice: ");
	scanf(" %d", &user_input);

	switch (user_input)
	{
	case 1:
		printf("Reservation Done\n");
		slots[0] = 1;
		break;

	case 2:
		printf("Reservation Done\n");
		slots[1] = 1;
		break;

	case 3:
		printf("Reservation Done\n");
		slots[2] = 1;
		break;

	case 4:
		printf("Reservation Done\n");
		slots[3] = 1;
		break;

	case 5:
		printf("Reservation Done\n");
		slots[4] = 1;
		break;

	case 6:
		printf("Reservation Done\n");
		slots[0] = 1;
		break;

	default:
		printf("Wrong Input!\n");
		printf("Try Again: ");
		scanf(" %d", &user_input);
	}

	if (slots[0] == 1)
	{
		printf("This Appointment is reserved!\n"
			   "CAN'T USE IT AGAIN\n");
	}
	else if (slots[1] == 1)
	{
		printf("This Appointment is reserved!\n"
			   "CAN'T USE IT AGAIN\n");
	}
	else if (slots[2] == 1)
	{
		printf("This Appointment is reserved!\n"
			   "CAN'T USE IT AGAIN\n");
	}
	else if (slots[3] == 1)
	{
		printf("This Appointment is reserved!\n"
			   "CAN'T USE IT AGAIN\n");
	}
	else if (slots[4] == 1)
	{
		printf("This Appointment is reserved!\n"
			   "CAN'T USE IT AGAIN\n");
	}
	else if (slots[5] == 1)
	{
		printf("This Appointment is reserved!\n"
			   "CAN'T USE IT AGAIN\n");
	}

	u16 ch;
	printf("Do you want to choose another appointment\n");
	printf("Enter num 1 for Yes\n"
		   "Enter num 2 for No\n"
		   "Your Choice: ");
	scanf(" %d", &ch);
	patientInformationOnly();
	printf("Enter Num 1 to choose first reservation\n");
	printf("Enter Num 2 to choose second reservation\n");
	printf("Enter Num 3 to choose third reservation\n");
	printf("Enter Num 4 to choose fourth reservation\n");
	printf("Enter Num 5 to choose fifth reservation\n");
	printf("Enter Num 6 to choose sixth reservation\n");
	printf("Your choice: ");
	scanf(" %d", &user_input_again);
	switch (user_input_again)
	{
	case 1:
		if (slots[0] == 1)
		{
			printf("This Appointment is reserved!\n"
				   "CAN'T USE IT AGAIN\n");
		}
		else
		{
			printf("Reservation Done\n");
			slots[0] = 1;
		}
		break;

	case 2:
		if (slots[1] == 1)
		{
			printf("This Appointment is reserved!\n"
				   "CAN'T USE IT AGAIN\n");
		}
		else
		{
			printf("Reservation Done\n");
			slots[1] = 1;
		}
		break;

	case 3:
		if (slots[2] == 1)
		{
			printf("This Appointment is reserved!\n"
				   "CAN'T USE IT AGAIN\n");
		}
		else
		{
			printf("Reservation Done\n");
			slots[2] = 1;
		}
		break;

	case 4:
		if (slots[3] == 1)
		{
			printf("This Appointment is reserved!\n"
				   "CAN'T USE IT AGAIN\n");
		}
		else
		{
			printf("Reservation Done\n");
			slots[3] = 1;
		}
		break;

	case 5:
		if (slots[4] == 1)
		{
			printf("This Appointment is reserved!\n"
				   "CAN'T USE IT AGAIN\n");
		}
		else
		{
			printf("Reservation Done\n");
			slots[4] = 1;
		}
		break;

	case 6:
		if (slots[5] == 1)
		{
			printf("This Appointment is reserved!\n"
				   "CAN'T USE IT AGAIN\n");
		}
		else
		{
			printf("Reservation Done\n");
			slots[5] = 1;
		}
		break;

	default:
		printf("Wrong Input!\n");
		printf("Try Again: ");
		scanf(" %d", &user_input_again);
	}
}

void Reservation()
{
	u16 choice;
	printf("--------------------------------\n");
	printf("Time for appointment\n");
	printf("Please choose between available appointments\n");
	printf("Available Appointments\n");
	printf("2pm to 2:30pm\n"
		   "--------------\n"
		   "2:30pm to 3pm\n"
		   "--------------\n"
		   "3pm to 3:30pm\n"
		   "--------------\n"
		   "3:30pm to 4pm\n"
		   "--------------\n"
		   "4pm to 4:30pm\n"
		   "--------------\n"
		   "4:30pm to 5pm\n"
		   "--------------\n");
	printf("--------------------------------\n");
	slots_choice();
}

void slots_choice()
{
	printf("Enter the ID to reserve a slot: ");
	scanf(" %d", &ID_Check);
	if (ID_Check == arrayOfIDs[0])
	{
		patient_one();
	}
	else if (ID_Check == arrayOfIDs[1])
	{
		patient_two();
	}
	else if (ID_Check == arrayOfIDs[2])
	{
		patient_three();
	}
	else if (ID_Check == arrayOfIDs[3])
	{
		patient_four();
	}
	else if (ID_Check == arrayOfIDs[4])
	{
		patient_five();
	}
	else if (ID_Check == arrayOfIDs[5])
	{
		patient_six();
	}
	else
	{
		printf("This ID Not Exist!\n");
		Check_Before_Reservation();
	}

	available_slots();
}

void user_mode()
{
	u16 user_options;
	printf("-----Hello User-----\n");
	printf("-----OPTIONS-----\n");
	printf("[1] View patients' information\n"
		   "[2] View available appointment\n"
		   "Your Choice: ");
	scanf(" %d", &user_options);
	switch (user_options)
	{
	case 1:
		printf("Please let admin add information\n");
		admin_mode();
		break;

	case 2:
		printf("Available Appointments\n");
		printf("2pm to 2:30pm\n"
			   "--------------\n"
			   "2:30pm to 3pm\n"
			   "--------------\n"
			   "3pm to 3:30pm\n"
			   "--------------\n"
			   "3:30pm to 4pm\n"
			   "--------------\n"
			   "4pm to 4:30pm\n"
			   "--------------\n"
			   "4:30pm to 5pm\n"
			   "--------------\n");
		break;

	default:
		printf("Wrong Input!\n");
	}
	u16 op;
	printf("Enter Num 1 for another options: ");
	scanf(" %d", &op);
	if (op == 1)
	{
		user_mode_after_added_patients();
	}
	else
	{
		printf("Wrong Input!\n");
	}
}

void user_mode_after_added_patients()
{
	u16 o;
	printf("-----Hello User-----\n");
	printf("[1] View patient's information\n"
		   "[2] View available appointment\n"
		   "Your Choice: ");
	scanf(" %d", &o);
	if (o == 1)
	{
		u16 *arrayOfAges[6] = {NULL};
		if (arrayOfAges[6] == NULL)
		{
			printf("-----No Information yet-----\n");
			optionsBack();
		}
		else
		{
			patientInformationOnly();
		}
	}
	else if (o == 2)
	{
		available_slots();
	}
	else
	{
		printf("Wrong Input!\n");
	}
}