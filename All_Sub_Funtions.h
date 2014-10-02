#ifndef Sub_Funtions_For_Dominoes_Game
#define Sub_Funtions_For_Dominoes_Game



int Stop_In_Middel_Of_the_Game()
{
		char Choice;

Top:	system("cls");
	printf("\n\n\n\t\n\n\n\n\n\n\n\n\t \7\20 Are you sure you want to Stop the Game and Return to Main Menu...? \n");
	printf("\n\n\n\n\n\t\t \20 1. YES\n");
	printf("\n\n\t\t \20 2. NO\n");
	printf("\n\n\n\n\n\t \4 Enter your Choice : ");
	Choice=getche();
	switch(Choice)
	{

	case '1':return 1;


	 case '2':
		     return 0;

	 default:
		  printf("\n\n\n\n\t\20 Erorr : Invalid Choice...");
		  getch();
		  goto Top;
			 		       
	}
}

//************************************************>> Funtions for Easy Level ...........

int Cheack_Similar_Node_Easy(Box Head,Box New)
{
	Box Temp;
	Total_Node=New->Data_1;	

	Temp=Head;
          
	while(Temp!=NULL)
	{
	
		if(Temp->Data_2==New->Data_2||Temp->Data_1==New->Data_1||Temp->Data_2==New->Data_1||Temp->Data_1==New->Data_2)
		return 1;

		Temp=Temp->Rlink;
		
	}

	return 0;
}


int Valid_Position_And_Similar_Node_Easy(Box Head,Box New,char Position)
{

	char Count='1';
    Box Temp;
	Temp=Head;


	while(Temp!=NULL)
	{
		if(Count==Position)
		{
			if(Temp->Data_1==New->Data_1||Temp->Data_1==New->Data_2||Temp->Data_2==New->Data_1||Temp->Data_2==New->Data_2)
		     return 1;

			printf("\n\n\n\t\5 Message : Not found similar Pair Dominoes...");
			return 0;
		}
		

		Temp=Temp->Rlink;
		Count++;
	}

	if(Temp==NULL)
		printf("\n\n\n\t\2 Erorr : Invalid Position....");
		return 0;

}


void Easy(Box Head)
{
   char Position;
   int Result,Chance=0;
   Box New;
   
   while(Head!=NULL)
   {
	    New=(Box)malloc(sizeof(Box));
		New->Llink=New->Rlink=NULL;
		New->Data_1=rand()%7;
		New->Data_2=rand()%7;
Top:system("cls");
	    printf("\n\n\n\n\n");
		if(Print_Level_Menu==0)
		{
		printf("\n\n  \4 Score : %d\t\t   \17 Level : Easy \t\t    \3 Chance : 3/%d",Score,Chance);  
		printf("\n--------------------------------------------------------------------------------");
		}
		else
		{
		printf("\n\n  \5 Score : %d\t\t   \6 Level : Medium\t\t    \16 Chance : 3/%d",Score,Chance); 
		printf("\n--------------------------------------------------------------------------------");
		}
		printf("\n\n\n\n\nDominoes : ");
		Display_Node(Head);
		Total_Nodes();
		Result=Total_Node;
		printf("\n\n\n\n\n\20 Dominoe : ");
		Display_Node(New);
		Total_Node=Result;

	    Result=Cheack_Similar_Node_Easy(Head,New);

		if(Result==0)
		{
            Head=Common_Cahanc(Head,&Chance);

			if(Head==NULL) return;
				
			goto Top;
		}

		printf("\n\n\n\n\n\n\t\4 Enter Valid Position : ");
		Position=getche();
		
		if(Position=='q' || Position=='Q') 
		{
			Result=Stop_In_Middel_Of_the_Game(); 
			if(Result==1) return;
			goto Top;
		}

		Result=Valid_Position_And_Similar_Node_Easy(Head,New,Position);

		if(Result==0)
		{
			getch();
			Score=Score-3;
			goto Top;
		}

		Head=Delete_Node(Head,Position);
   }
   getch();
   Main_Scroce_For_High(Score);
  
}

//************************************************************************ End Easy ***************************************************


//************************************************>> Funtions for Medium Level ...........



int Cheack_Similar_Node_Medium(Box Head,Box Front,Box Rear)
{
	Box Temp;
    Total_Node=Rear->Data_2;	
	Temp=Head;

	while(Temp!=NULL)
	{
		if(Temp->Data_1==Front->Data_1||Temp->Data_2==Front->Data_1||Temp->Data_1==Rear->Data_2||Temp->Data_2==Rear->Data_2)
			return 1;

		Temp=Temp->Rlink;
	}
	return 0;
}

int Valid_Position_Similar_And_Node_Medium(Box Head,Box Front,Box Rear,char Position)
{
	Box Temp;
	char Count='1';
	Temp=Head;

	while(Temp!=NULL)
	{
		if(Count==Position)
		{
                
	        if(Temp->Data_1==Front->Data_1||Temp->Data_2==Front->Data_1||Temp->Data_1==Rear->Data_2||Temp->Data_2==Rear->Data_2)
			return 1;

			printf("\n\n\n\t\5 Message : Not found similar pair dominoes...");
			return 0;
		}
		

		Temp=Temp->Rlink;
		Count++;
	}

	if(Temp==NULL)
		printf("\n\n\n\t\2\2 Erorr : Invalid Position....");
		return 0;
}

void Medium()
{
	char Position;
	int Result,Count,Chance;
	Box Rear,New,Temp,Head=NULL,Front=NULL;
	Score=Chance=0;
	Print_Level_Menu=1;

    Head=Create_Node(Head,6);
	Front=(Box)malloc(sizeof(Box));
	Front->Rlink=Front->Llink=NULL;
	Front->Data_1=rand()%7;
	Front->Data_2=rand()%7;

     Rear=Front;

	while(Head!=NULL)
	{
Top:system("cls");
		printf("\n\n\n\n\n");
		printf("\n\n  \5 Score : %d\t\t   \6 Level : Medium\t\t    \16 Chance : 3/%d",Score,Chance); 
		printf("\n--------------------------------------------------------------------------------");
		
		printf("\n\n\n\nDominoes : ");
		Display_Node(Head);
		Total_Nodes();
		Result=Total_Node;
		printf("\n\n\n\n\n\20 Dominoe : ");
		Display_Node(Front);
        Total_Node=Result;
		Result=Cheack_Similar_Node_Medium(Head,Front,Rear);

		if(Result==0)
		{
            Head=Common_Cahanc(Head,&Chance);

			if(Head==NULL)  return;
				
        	goto Top;
		}
		printf("\n\n\n\n\n\n\t\4 Enter Valid Position : ");
		Position=getche();
		
		if(Position=='q'||Position=='Q')  
		{
			Result=Stop_In_Middel_Of_the_Game(); 
			if(Result==1) return;
			goto Top;
		}

		Result=Valid_Position_Similar_And_Node_Medium(Head,Front,Rear,Position);

		if(Result==0)
		{
			getch();
			Score=Score-3;
			goto Top;
		}
//--------------------------------------------------------------------------------------------------------
           Temp=Head;
		   Count='1';

		   while(Temp!=NULL)
		   {
			   if(Count==Position)
			   {
				   
				   if(Temp->Data_1==Front->Data_1)
				   {
	                  New=(Box)malloc(sizeof(Box));
		              New->Rlink=New->Llink=NULL;
		              New->Data_1=Temp->Data_2;
		              New->Data_2=Temp->Data_1;
		              New->Rlink=Front;
		              Front->Llink=New;
		              Front=New;
		              break;
				   }

	              if(Temp->Data_2==Rear->Data_2)
				 {
	                 New=(Box)malloc(sizeof(Box));
		             New->Rlink=New->Llink=NULL;
		             New->Data_1=Temp->Data_2;
		             New->Data_2=Temp->Data_1;
		             Rear->Rlink=New;
		             New->Llink=Rear;
	                 Rear=New;
		             break;
				 }

	              if(Temp->Data_1==Rear->Data_2)
				  {
	               	 New=(Box)malloc(sizeof(Box));
		             New->Rlink=New->Llink=NULL;
		             New->Data_1=Temp->Data_1;
		             New->Data_2=Temp->Data_2;
		             Rear->Rlink=New;
		             New->Llink=Rear;
		             Rear=New;
		             break;
				  }

	             

				  if(Temp->Data_2==Front->Data_1)
				   {
		              New=(Box)malloc(sizeof(Box));
		              New->Rlink=New->Llink=NULL;
		              New->Data_1=Temp->Data_1;
		              New->Data_2=Temp->Data_2;
		              New->Rlink=Front;
		              Front->Llink=New;
		              Front=New;
		              break;
				   }
			  }
			   Temp=Temp->Rlink;
			   Count++;
		   }
//--------------------------------------------------------------------------------------------------------
		Head=Delete_Node(Head,Position);
	}
	
	Head=Front;

	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n  \3  Message : ");
	printf("\n\n\n\n\n\t\6 Successfully finished first stage, Now second stage is start....");
	printf("\n\n\n\t\20 Press Any Key to continue the Game...");
	getch();

	Easy(Head);


}

//***************************************************************** End Medium ***********************************************************



//************************************************>> Funtions for Hard Level ...........


int Cheack_Similar_Node_Hard(Box Head)
{
	Box Temp_1,Temp_2;

	Temp_1=Head;
	Total_Node=Head->Data_1;	

	while(Temp_2!=NULL)
	{
		Temp_2=Temp_1->Rlink;
		while(Temp_2!=NULL)
		{
			Total_Node=Temp_2->Data_1;

			if(Temp_1->Data_2==Temp_2->Data_1) return 1;
				
            Temp_2=Temp_2->Rlink;
		}
         
		Temp_1=Temp_1->Rlink;
		Temp_2=Temp_1;
	}

	return 0;
}



Box Valid_Position_Hard(Box Head,char Position)
{
   Box Temp;
   char Count='1';

   Temp=Head;

   while(Temp!=NULL)
   {
	   if(Count==Position)  return Temp;
		   

	   Temp=Temp->Rlink;
	   Count++;
   }

   printf("\n\n\n\n\t\2\2 Erorr : Invalid Position...!");
   getch();

   return Temp=NULL;
}


int Similar_Node_Hard(Box Temp_1,Box Temp_2)
{
	if(Temp_1->Data_2!=Temp_2->Data_1)
		{

			printf("\n\n\n\n\t\5 Message : Not found similar pair dominoes.....");
			getch();

			return 0;
		}

	return 1;

}


void Hard()
{
   char Position_1,Position_2,Result;
   Box Temp_1,Temp_2,Head=NULL;
   int Chance;

   Score=Chance=0;

   Head=Create_Node(Head,9);

     while(Head!=NULL)
	 {
Top:system("cls");
	printf("\n\n\n\n\n");
	    
		printf("\n\n  \6 Score : %d\t\t   \16 Level : Hard  \t\t    \4 Chance : 3/%d",Score,Chance); 
		printf("\n--------------------------------------------------------------------------------");
        
		printf("\n\n\n\nDominoes : ");
		Display_Node(Head);
		Total_Nodes();

		Result=Cheack_Similar_Node_Hard(Head);

		if(Result==0)
		{
            Head=Common_Cahanc(Head,&Chance);

			if(Head==NULL) return;
				
            goto Top;
		}

		printf("\n\n\n\n\n\n\t\4 Enter Valid Any Two Position's : ");
		Position_1=getche();
		
		if(Position_1=='q'||Position_1=='Q') 
		{
above:Result=Stop_In_Middel_Of_the_Game(); 
			if(Result==1) return;
			goto Top;
		}

		Position_2=getche();
		if(Position_2=='q'||Position_2=='Q')  goto above; 
		

		Temp_1=Valid_Position_Hard(Head,Position_1);
		if(Temp_1==NULL) goto Top;

		Temp_2=Valid_Position_Hard(Head,Position_2);
		if(Temp_2==NULL) goto Top;
        
			Result=Similar_Node_Hard(Temp_1,Temp_2);
			if(Result==0) goto Top;

			Head=Delete_Node(Head,Position_2);
		    Head=Delete_Node(Head,Position_1);				
	}
       getch();
	   Main_Scroce_For_High(Score);


}

//**************************************************************** End Hard ********************************************************



#endif