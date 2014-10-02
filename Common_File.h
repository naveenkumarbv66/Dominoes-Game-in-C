#ifndef COMMON_FOR_ALL_FUNTIONS
#define COMMON_FOR_ALL_FUNTIONS


struct Dominoe
{
	int Data_1;
	int Data_2;
    struct Dominoe *Rlink;
	struct Dominoe *Llink;
};

typedef struct Dominoe *Box;



void Win()   // If User Won the match, then this function is Activted
{
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\n");
	printf("\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n");
	printf("\t\t\3\t\260 Congratulation...!\t\t\3\n");
	printf("\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n");
	printf("\t\t\3\t\260 You Won The Match.\t\t\3\n");
	printf("\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n");
	printf("\t\t\3\t\260 You cleared all Domioes.!  \t\3\n");
	printf("\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n");
	printf("\t\t\3\t\260 Score : %d\t\t\t\3\n",Score);
	printf("\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n\t\t\3\t\t\t\t\t\3\n");
	printf("\t\t\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3");
	
}

void Loose()   // If User Loose the match, then this function is Activted
{
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
	printf("\t\t\4\t\t\t\t\t\t\4\n\t\t\4\t\t\t\t\t\t\4\n\t\t\4\t\t\t\t\t\t\4\n");
	printf("\t\t\4\t\260 You not cleared all Domioes..!\t\4\n");
	printf("\t\t\4\t\t\t\t\t\t\4\n\t\t\4\t\t\t\t\t\t\4\n\t\t\4\t\t\t\t\t\t\4\n");
	printf("\t\t\4\t\260 You Lost The Match.\t\t\t\4\n");
	printf("\t\t\4\t\t\t\t\t\t\4\n\t\t\4\t\t\t\t\t\t\4\n\t\t\4\t\t\t\t\t\t\4\n");
	printf("\t\t\3\t\260 Score : %d\t\t\t\t\4\n",Score);
	printf("\t\t\4\t\t\t\t\t\t\4\n\t\t\4\t\t\t\t\t\t\4\n\t\t\4\t\t\t\t\t\t\4\n");
	printf("\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4");
	getch();
	 Main_Scroce_For_High(Score);
}

void Display_Node(Box Temp) // To Display All Nodes/Domenoes
{
	Total_Node=0;

	while(Temp!=NULL)
	{
		printf("[%d|%d] ",Temp->Data_1,Temp->Data_2);
		Temp=Temp->Rlink;
		Total_Node++;
	}
}




Box Create_Node(Box Head,int Total) // To Create Nodes/Dominoes
{
	int i;
    Box New;
	
    srand((unsigned int)time(NULL)); // To Generate randum numbers/Dominoes

	for(i=0;i<Total;i++)
	{
    	New=(Box)malloc(sizeof(Box));
		New->Llink=New->Rlink=NULL;
		New->Data_1=rand()%7;
		New->Data_2=rand()%7;

		if(Head==NULL)
		{
          	Head=New;
			
		}
		else
		{
            New->Rlink=Head;
			Head->Llink=New;
			Head=New;

		}
	}
	return Head;
}




Box Delete_Node(Box Head,char Position) // To Delete the Node/Dominoes
{
    Box Pre,Post,Temp;
	char Count='1';

    Score=Score+23;
	
	if(Count==Position&&Head->Rlink==NULL)
	{
		Head=NULL;
		Win();
		return Head;
	}

	if(Count==Position)
	{
		Head=Head->Rlink;
		Head->Llink=NULL;
		return Head;
	}

	Temp=Head;

	while(Temp!=NULL)
	{
		if(Count==Position) break;
			
        Temp=Temp->Rlink;
		Count++;
	}

	if(Temp->Rlink==NULL)
	{
		Temp=Temp->Llink;
		Temp->Rlink=NULL;
		return Head;
	}

	Pre=Temp->Llink;
	Post=Temp->Rlink;
	Pre->Rlink=Post;
	Post->Llink=Pre;

	return Head;
}


Box Common_Cahanc(Box Head,int *Chance)    // If Not Found Similler Nodes, then this function is Activted.
{                                          // this founction is activate only 3 times.
	Box New;
	*Chance=*Chance+1;

			if(*Chance>3)     
			{
				printf("\n\n\n\n\n\n    \3 Message : ");
			     printf("\n\n\t\t\1 No more Similar pair of Dominoes Found..!!");
				 printf("\n\n\t\t\20 Press any key to continue...");
				 getch();
				 Loose();
				 return Head=NULL;
			}
				
		Score=Score+13;

		  printf("\n\n\n\n\n\n    \3 Message : ");
          printf("\n\n\t\t\4 Not Found Similar Pair of Dominoes."); 

		  printf("\n\n\n\t\t\4 Out of 3 chances, %d chance is Activated...",*Chance);

		  printf("\n\n\n\n\t\t\20 Press any key to continue the Game...");

		 // Head=Create_Node(Head,1);
		New=(Box)malloc(sizeof(Box));
	    New->Llink=New->Rlink=NULL;
		New->Data_1=rand()%7;
		New->Data_2=Total_Node;

		    New->Rlink=Head;
			Head->Llink=New;
			Head=New;

		  getch();
		  return Head;

}


void Total_Nodes()              // To print Dominoes Position...
{
	int i;

	printf("\n\nPosition : ");

	for(i=1;i<=Total_Node;i++)
	{
		printf("  %d   ",i);
	}
}


void Design()
{
	int	i=0;
	while(i!=18)
	{
		printf("    \17");
	    printf("\t\t\t\t\t\t\t\t\t");
	    printf("   \17\n");
		i++;
	}
	       printf("    \17\t\t\t\t   THE DOMINOES   \t\t\t   \17\n");
	       printf("    \17\t\t\t\t   ~~~ ~~~~~~~~\t\t\t\t   \17\n");
		   i=0;
   while(i!=21)
	{
		printf("    \17");
		if(i==19)
			printf("\t\t\t\t\t\t\t\tRGIT\t");
		else
	        printf("\t\t\t\t\t\t\t\t\t");

	    printf("   \17\n");
		i++;
	}
   printf("    ");
   for(i=0;i<36;i++)
	{
      printf("\17\17");
	}
   

}


void Stop_Game()   //For Quit the Game
{
	char Choice;
	int i;

Top:	system("cls");
	printf("\n\n\n\t\n\n\n\n\n\n\n\n\t \7\20 Are you sure you want to quit the Game...? \n");
	printf("\n\n\n\n\n\t\t \20 1. YES\n");
	printf("\n\n\t\t \20 2. NO\n");
	printf("\n\n\n\n\n\t \4 Enter your Choice : ");
	Choice=getche();
	switch(Choice)
	{

	case '1':system("cls");
	printf("\n    ");
  	for(i=0;i<36;i++)
	{
        printf("\17\17");
	}
	printf("\n    \17");
	printf("\t\t\t\t\t\t\t\t\t");
	printf("   \17\n ");
	printf("   \17  \4 Thankyou \3 \3 \3 \t\t\t\t\t\t   \17\n");
		Design();
		printf("\n\n\t\t\t\t\t\20 ");
	       exit(0);

	 case '2':
		     return;

	 default:
		  printf("\n\n\n\n\t\20 Erorr : Invalid Choice...");
		  getch();
		  goto Top;
			 		       
	}
}


#endif