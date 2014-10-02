


                                      // Maha Lakshmi
                                      // Durga Davi
                                     // 2010, 4 sem CSE-2.

#include  "Standard_Library_File.h"

void main()
{
	char Choice;
	int i;
	Box Head=NULL;
	system("cls");
/*	printf("\n    ");
	for(i=0;i<36;i++)
	{
        printf("\17\17");
	}
	printf("\n    \17");
	printf("\t\t\t\t\t\t\t\t\t");
	printf("   \17\n ");
	printf("   \17  \4 Welcome To \3 \3 \3 \t\t\t\t\t\t   \17\n");
	Design();
	printf("\n\n\t\t\t\t\t \20 Press any key to continue....");
    getch();*/
	while(1)
	{
Main:system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("\n\t\t\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6");
		printf("\n\t\t\6\t\t\t\t\6\n\t\t\6\t\t\t\t\6\n");
		printf("\t\t\6  \3 Menu..\t\t\t\6");
		printf("\n\t\t\6\t\t\t\t\6\n\t\t\6\t\t\t\t\6");
		printf("\n\t\t\6\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\6");
		printf("\n\t\t\6\t\t\t\t\6\n\t\t\6\t\t\t\t\6");
		printf("\n\t\t\6\t\20 1. Start Game\t\t\6");
		printf("\n\t\t\6\t\t\t\t\6\n\t\t\6\t\t\t\t\6");
		printf("\n\t\t\6\t\20 2. Level\t\t\6");
		printf("\n\t\t\6\t\t\t\t\6\n\t\t\6\t\t\t\t\6");
		printf("\n\t\t\6\t\20 3. Instructions\t\6");
		printf("\n\t\t\6\t\t\t\t\6\n\t\t\6\t\t\t\t\6");
		printf("\n\t\t\6\t\20 4. Options\t\t\6");
		printf("\n\t\t\6\t\t\t\t\6\n\t\t\6\t\t\t\t\6");
		printf("\n\t\t\6\t\17 5. Quit\t\t\6");
		printf("\n\t\t\6\t\t\t\t\6\n\t\t\6\t\t\t\t\6");
		printf("\n\t\t\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6\6");
		
       printf("\n\n\n\n\t\t\4 Enter Your Choice : ");  //Choice=getche();
	   scanf("%d",&Choice);
	   
		switch(Choice)
		{

	case 1:  
			   Medium();
			   break;

		case 2:
Top:system("cls");
		       printf("\n\n\n\n\n\n\n\n\n\n\n");
			   printf("\t\t\5 Level..\n");
			   printf("\n\t\t------------------------------------\n\n\n");
			   printf("\t\t\t\20 1. Easy\n\n\n\n");
			   printf("\t\t\t\20 2. Medium\n\n\n\n");
			   printf("\t\t\t\20 3. Hard\n\n\n\n");
			   printf("\t\t\t\17 4. Back\n\n");
			   printf("\n\n\n\n\t\t\t\4 Enter Your Choice : ");
			   //Choice=getche();
			   scanf("%d",&Choice);

			   switch(Choice)
			   {

			   case 1:
				      Print_Level_Menu=Score=0;
					  Head=NULL;
					  Head=Create_Node(Head,9);
				      Easy(Head);
					  break;

			   case 2:
				      Medium();
					  break;

			   case 3:
				      Hard();
					  break;

				case 4: goto Main;
				      

			   default: printf("\n\n\n\t\t\t\20 Erorr : Invalid Choice.....!");
				   getch();
				   goto Top;

			   }
			   break;

	    case 3:
			    system("cls");
			    Instructions();
				getch();
				break;

		case 4:
			   while(1)
			 {
			  
			   system("cls");
		       printf("\n\n\n\n\n\n\n\n\n\n\n");
			   printf("\t\t\3 Options..\n");
			   printf("\n\t\t------------------------------------\n\n\n");
			   printf("\t\t\t\20 1. High Scores\n\n\n\n");
			   printf("\t\t\t\20 2. About Team\n\n\n\n");
			   printf("\t\t\t\20 3. Reset Score\n\n\n\n");
			   printf("\t\t\t\17 4. Back\n\n");
			   printf("\n\n\n\n\t\t\t\4 Enter Your Choice : ");
			  //Choice=getche();
			   scanf("%d",&Choice);

		   switch(Choice)
			   {

			   case 1:
				      High_Scores_Display();
					  getch();
					  break;

			    case 2:
				     About_Team();
					  getch();
					  break;

			   case 3:

				   Reset_Score();
					  break;

			   case 4:
				       goto Main;

			default: printf("\n\n\n\t\t\t\20 Erorr : Invalid Choice.....!");
			         getch();
			         break;
			   }

			 }
			   break;
			    
		case 5:
			   Stop_Game();
			   
			   break;

		default: printf("\n\n\n\t\t\t\20 Erorr : Invalid Choice.....!");
			getch();
			break;


		}
	}
}