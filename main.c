/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct user
{
  char name[30];
  int userid;
  int password;
  int booksadded;
  int booksrented;
  struct user *next;
};
typedef struct user users;
struct dept
{
  int sem;
  int tc_books[8];
  int is_books[8];
};

struct dept a[3];
void login ();
void reg ();
void display (int, int);
void available ();
void updatebooks ();
int i = 990, flag = 0, more = 0;
int logpwd, c, department, bookch, moresem;
users *head = NULL;
int
main ()
{
  printf ("WELCOME TO THE BOOK SHARING FORUM OF RIT \n");
  while (c != 99)
    {
      printf ("\n 1) LOGIN \n 2) REGISTER \n 3) BOOKS AVAILABLE \n 99) EXIT\n");
      scanf ("%d", &c);
      switch (c)
	{
	case 1:
	  login ();
	  break;
	case 2:
	  reg ();
	  break;
	case 3:
	  available ();
	  break;
	case 99:
	  exit (0);
	default: printf("\nWRONG CHOICE \n");
	}
    }
  return 0;
}

void
login ()
{
  users *temp;
  temp = head;
  int logid;
  int pwd, semester;
  printf ("LOGIN PAGE \n PLEASE ENTER YOUR USER ID \n");
  scanf ("%d", &logid);
  printf (" \n ENTER YOUR PASSWORD \n");
  scanf ("%d", &pwd);

  while (logid != temp->userid && temp != NULL)
    temp = temp->next;
  if (temp != NULL)
    {
      if (pwd == temp->password)
	{
	  printf ("LOGIN SUCCESSFUL \n");
	  flag = 1;
	}
      else
	printf ("WRONG PASSWORD \n");
    }
  else
    printf ("LOGIN FAILED \n");
  if (flag == 1)
    {
      do
	{
	  printf
	    ("1) TO ADD BOOKS \n 2) TO RENT BOOKS \n 3) YOUR PROFILE \n 4) EXIT \n");
	  scanf ("%d", &c);
	  switch (c)
	    {
	    case 1:
	      do
		{
		  printf
		    ("ENTER THE SEMESTER IN WHICH THE SUBJECT IS TAUGHT \n");
		  scanf ("%d", &semester);
		  printf ("ENTER THE DEPARTMENT \n 1) TELECOM \t 2) ISE \n");
		  scanf ("%d", &department);
		  display (semester, department);
		  do{
		  printf ("SELECT WHICH BOOK YOU WANT TO ADD \n");
		  scanf ("%d", &bookch);
		  if (department == 1)
		    a[semester - 3].tc_books[bookch - 1]++;
		  else
		    a[semester - 3].is_books[bookch - 1]++;
		  temp->booksadded++;
		  printf ("\n THANK YOU FOR DONATING \n");
		  printf ("DO YOU WANT TO ADD MORE BOOKS from the same semester department?\n 1) YES \t 2) NO \n");
		  scanf("%d", &moresem);
		  }
		  while (moresem == 1);
		  printf ("DO YOU WANT TO ADD MORE BOOKS from other semester or department? \n 1) YES \t 2) NO \n");
		  scanf ("%d", &more);
		  }
	      while (more == 1);
	      break;

	    case 2:
	      available ();
	      do
		{
		  printf ("ENTER THE DEPARTMENT \n 1) TELECOM \t 2) ISE \n");
		  scanf ("%d", &department);
		  printf
		    ("ENTER THE SEMESTER AND CORRESPONDING SUBJECT SERIAL NUMBER \n");
		  scanf ("%d %d", &semester, &c);
		      if ((department == 1
		       && a[semester - 3].tc_books[c - 1] == 0)
		      || (department == 2
			  && a[semester - 3].is_books[c - 1] == 0))
		    printf ("THIS BOOK IS NOT AVAILABLE \n");
		  else if (temp->booksrented == 3)
		    printf ("YOU CANNOT RENT MORE THAN 3 BOOKS \n");
		  else
		    {
		      if (department == 1)
			a[semester - 3].tc_books[bookch - 1]--;
		      else
			a[semester - 3].is_books[bookch - 1]--;
		      temp->booksrented++;
		      printf
			("Order CONFIRMED. Please collect it from the PITSTOP \n");
		printf
		    ("DO YOU WANT TO RENT MORE BOOKS from the other semester or department \n 1) YES \t 2) NO \n");
		    scanf("%d", &c);
		}
		}while (c == 1); break;
	    case 3:
	      printf
		(" NAME: %s \n USER ID %d \n BOOKS ADDED %d \n BOOKS TAKEN %d \n",
		 temp->name, temp->userid, temp->booksadded,
		 temp->booksrented);
	      break;

	    }
	  
	}while (c != 4);
    }
}
    

      void reg ()
      {
	users *temp = (users *) malloc (sizeof (users));
	i += 10;
	printf (" \n REGISTRATION PAGE \n PLEASE ENTER YOUR NAME ");
	scanf ("%s", temp->name);
	printf ("\n PLEASE SET UP A NUMERICAL PASSWORD ");
	scanf ("%d", &logpwd);
	temp->password = logpwd;
	printf ("\n******* YOUR USER ID IS %d *******\n", i);
	temp->userid = i;
	temp->next = head;
	head = temp;
      }

      void display (int semester, int department)
      {
	switch (semester)
	  {
	  case 3:
	    if (department == 1)
	      printf
		("1) MATHS 3 \n 2) ACD \n 3) DCD \n 4) NA \n 5) EMT \n 6)DATA STRUCTURES using C \n 7) BES \n");
	    else if (department == 2)
	      printf
		("1) MATHS 3 \n 2) COA \n 3) ME \n 4) DMS \n 5) OOPS \n 6)DATA STRUCTURES using C \n");
	    break;
	  case 4:
	    if (department == 1)
	      printf
		("1) MATHS 4 \n 2) MicroControllers \n 3) MicroElectronics \n 4) Signals \n 5) MATLAB \n 6)Web development \n 7) Android development");
	    else if (department == 2)
	      printf
		("1) MATHS 4 \n 2) DC \n 3) SE \n 4) Design Algorithms \n 5) MicroProcessors \n 6)Finite Automata \n");
	    break;
	  case 5:
	    if (department == 1)
	      printf
		("1) DSP \n 2) AC \n 3) MA Engineering \n 4) ITC \n 5) ME \n 6) IOT \n 7) DATA STRUCTURES using C++");
	    else if (department == 2)
	      printf
		("1) Computer Networks \n 2) Operation Research \n 3) Operating Systems \n 4) DMS \n 5) IPR \n 6)IMAGE PROCESSING \n 7) NL PROCESSING \n");
	    break;
	  case 6:
	    if (department == 1)
	      printf
		("1) DC \n 2) Computer NETWORKING \n 3) ESD \n 4) MACHINE LEARNING \n 5) OPERATING SYSTEMS");
	    else if (department == 2)
	      printf
		("1) System Software \n 2) C++ \n 3) JAVA & J2EE \n 4) MACHINE LEARNING \n 5) COMPILER DESIGN \n 6)DST \n");
	    break;
	  }
      }

      void available ()
      {
	printf ("SEMESTER III \n TELECOM \n");
	printf
	  (" 1) MATHS 3  %d \n 2) ACD %d \n 3) DCD %d\n 4) NA %d\n 5) EMT %d\n 6)DATA STRUCTURES using C %d\n 7) BES %d \n",
	   a[0].tc_books[0], a[0].tc_books[1], a[0].tc_books[2],
	   a[0].tc_books[3], a[0].tc_books[4], a[0].tc_books[5],
	   a[0].tc_books[6]);
	printf
	  ("\n ISE \n 1) MATHS 3 %d\n 2) COA %d\n 3) ME %d\n 4) DMS %d\n 5) OOPS %d\n 6)DATA STRUCTURES using C %d\n",
	   a[0].is_books[0], a[0].is_books[1], a[0].is_books[2],
	   a[0].is_books[3], a[0].is_books[4], a[0].is_books[5],
	   a[0].is_books[6]);
	printf ("\nSEMESTER IV \nTELECOM \n");
	printf
	  (" 1) MATHS 4 %d\n 2) MicroControllers %d\n 3) MicroElectronics %d\n 4) Signals %d\n 5) MATLAB %d\n 6)Web development %d\n 7) Android development %d",
	   a[1].tc_books[0], a[1].tc_books[1], a[1].tc_books[2],
	   a[1].tc_books[3], a[1].tc_books[4], a[1].tc_books[5],
	   a[1].tc_books[6]);
	printf
	  ("\n ISE \n 1) MATHS 4 %d\n 2) DC %d\n 3) SE %d\n 4) Design Algorithms %d\n 5) MicroProcessors %d\n 6)Finite Automata %d\n",
	   a[1].is_books[0], a[1].is_books[1], a[1].is_books[2],
	   a[1].is_books[3], a[1].is_books[4], a[1].is_books[5],
	   a[1].is_books[6]);

	printf ("\nSEMESTER V \nTELECOM \n");
	printf
	  (" 1) DSP %d\n 2) AC %d\n 3) MA Engineering %d\n 4) ITC %d\n 5) ME %d\n 6) IOT %d\n 7) DATA STRUCTURES using C++ %d",
	   a[2].tc_books[0], a[2].tc_books[1], a[2].tc_books[2],
	   a[2].tc_books[3], a[2].tc_books[4], a[2].tc_books[5],
	   a[2].tc_books[6]);
	printf
	  ("\n ISE \n 1) Computer Networks %d\n 2) Operation Research %d\n 3) Operating Systems %d\n 4) DMS %d\n 5) IPR %d\n 6)IMAGE PROCESSING %d\n 7) NL PROCESSING %d\n",
	   a[2].is_books[0], a[2].is_books[1], a[2].is_books[2],
	   a[2].is_books[3], a[2].is_books[4], a[2].is_books[5],
	   a[2].is_books[6]);
	printf ("\nSEMESTER VI \nTELECOM \n");
	printf
	  (" 1) DC %d\n 2) Computer NETWORKING %d\n 3) ESD %d\n 4) MACHINE LEARNING %d\n 5) OPERATING SYSTEMS %d",
	   a[3].tc_books[0], a[3].tc_books[1], a[3].tc_books[2],
	   a[3].tc_books[3], a[3].tc_books[4], a[3].tc_books[5]);
	printf
	  ("\n ISE \n 1) System Software %d\n 2) C++ %d\n 3) JAVA & J2EE %d\n 4) MACHINE LEARNING %d\n 5) COMPILER DESIGN %d\n 6)DST %d\n",
	   a[3].is_books[0], a[3].is_books[1], a[3].is_books[2],
	   a[3].is_books[3], a[3].is_books[4], a[3].is_books[5]);
      }
