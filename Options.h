#ifndef Options_2010_3sem_CSE_2_RGIT
#define Options_2010_3sem_CSE_2_RGIT



struct Point
{
	char Name[15];
	int point;
}S;
char char_arrya[9][10];
int Integer_arrya[9];
char password_Number[]={'1','0','5'};
FILE *fp;



void High_Scores_Display()
{
	
     int i;
	 FILE *fp;
	 system("cls");
	 printf("\n\n\n\n\n\t\3 Top Scores in dominoes game..");
	 printf("\n ------------------------------------------------------------------------------\n\n\n");

	 printf("\n\n\n\t\t\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\n");
	 printf("\t\t\5\t\t\t\t\t\t\5\n\t\t\5\t\t\t\t\t\t\5\n\t\t\5  RANK\t\tNAME\t\tHIGH SCORE\t\5\n\t\t\5\t\t\t\t\t\t\5\n\t\t\5\t\t\t\t\t\t\5\n");
	 printf("\t\t\5-----------------------------------------------\5\n\t\t\5\t\t\t\t\t\t\5");
	 fp=fopen("High_Scores_Dominoes.rgit","r");

	 if(fp==NULL)
	 {
		 for(i=1;i<=8;i++)
		 {
			 printf("\n\t\t\5    %d \t\t -- \t\t   -- \t\t\5",i);
			 printf("\n\t\t\5\t\t\t\t\t\t\5\n\t\t\5\t\t\t\t\t\t\5");
		 }
   

	 }
	 else
	 {
		 i=1;
		 while(1)
		 {
			 fscanf(fp,"%s %d",S.Name,&S.point);
           	if(feof(fp))
	        	break;
           	printf("\n\t\t\5    %d\t        %s\t           %d\t\t\5",i,S.Name,S.point);
			 printf("\n\t\t\5\t\t\t\t\t\t\5\n\t\t\5\t\t\t\t\t\t\5");
			 i++;
			 

		 }
		 fclose(fp);
		 while(i!=9)
		 {
			 printf("\n\t\t\5    %d \t\t -- \t\t   -- \t\t\5",i);
			 printf("\n\t\t\5\t\t\t\t\t\t\5\n\t\t\5\t\t\t\t\t\t\5");
			 i++;
		 }

	 }
	  printf("\n\t\t\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5\5");
}




//********************** Updating Score into FIle..................................

void Copy_1(int i)
{
	int k=0;

	while(char_arrya[i][k]!='\0')
	{
		S.Name[k]=char_arrya[i][k];
		k++;
	}
	S.Name[k]='\0';
}


void Copy_2(int i)
{
	int k=0;

	while(S.Name[k]!='\0')
	{
		char_arrya[i][k]=S.Name[k];
		k++;

	}
	char_arrya[i][k]='\0';
}


void Copy_3(int i)
{
	int k=0,j;

	j=i+1;

	while(char_arrya[j][k]!='\0')
	{
		char_arrya[i][k]=char_arrya[j][k];
		k++;
	}
char_arrya[i][k]='\0';
}



void Coppy_4(int i)
{
	int k=0;

	while(char_arrya[i][k]!='\0')
	{
		S.Name[k]=char_arrya[i][k];
		k++;
	}
	
	S.Name[k]='\0';
}


int Compare_String(char *s1,char *s2)
{
	while(*s1==*s2)
	{
		if(*s1=='\0')  break;

		s1++,s2++;
	}

	return *s1-*s2;

}


void Reset_Score()
{
	char password[10],Data;
	int i=0,j=0;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\t\t\20 Input password : ");
Top:Data=getch();
	switch(Data)
	{
	case 13:
		       break;

	case 8:
		if(i==0)
		{
			j=0;
			goto Top;
		}
		i--;		       
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
    	printf("\n\n\t\t\20 Input password : ");
		while(j<=i-1)
		{
	    printf("\3");
		j++;
		}
		j=0;

		
			goto Top;

	default :
		password[i]=Data;
system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
    	printf("\n\n\t\t\20 Input password : ");
		while(j<=i)
		{
	    printf("\3");
		j++;
		}
		i++;
		j=0;
		
		goto Top;
	}
	password[i]='\0';


	i=Compare_String(password,password_Number);

	if(i==0)
	{
		   fp=fopen("High_Scores_Dominoes.rgit","w");
           fclose(fp);
		   system("cls");
		   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t  \20 Message : Successfully reset the score...");
		   getch();
	}
	else
	{
		printf("\n\n\n\t\t\4 Erorr : Invalid password...");
		getch();
		return;
	}

}


void Up_Date_Socre_For_High()
{
	int i,j,count=0,temp;
	
	fp=fopen("High_Scores_Dominoes.rgit","r");
	while(1)
	{
	fscanf(fp,"%s %d",S.Name,&S.point);
	if(feof(fp))
		break;
	    Integer_arrya[count]=S.point;
		//Copy_2(count);
		strcpy(char_arrya,S.Name);
	count++;
	}
	fclose(fp);     

	for(j=1;j<count;j++)
	{
		for(i=0;i<count-j;i++)
		{
			if(Integer_arrya[i]<=Integer_arrya[i+1])
			{
				temp=Integer_arrya[i];
				//Copy_1(i);
				strcpy(S.Name,char_arrya);

				Integer_arrya[i]=Integer_arrya[i+1];
				//Copy_3(i);
				strcpy(char_arrya,char_arrya);

				Integer_arrya[i+1]=temp;
				//Copy_2(i+1);
				strcpy(char_arrya,S.Name);
			}
		}
	}

  fp=fopen("High_Scores_Dominoes.rgit","w");

  if(count>8) count=8;

	for(i=0;i<count;i++)
	{
		S.point=Integer_arrya[i];
		//Coppy_4(i);//S.Name[k]=char_arrya[i][k];
		strcpy(S.Name,char_arrya);
		fprintf(fp,"%s %d\n",S.Name,S.point);
		
	}
	fclose(fp);



}




void Main_Scroce_For_High(int socre)
{
	int i=1;
    system("cls");
		
		fp=fopen("High_Scores_Dominoes.rgit","r");

	if(fp==NULL)
	{
		fp=fopen("High_Scores_Dominoes.rgit","w");
		S.point=socre;
system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\20 Type your name to save the score : ");
		scanf("%s",S.Name);
		fprintf(fp,"%s %d\n",S.Name,S.point);
		fclose(fp);
		return;

	}
	else
	{
		fp=fopen("High_Scores_Dominoes.rgit","a+");
		while(1)
		{
		fscanf(fp,"%s %d\n",S.Name,&S.point);
		
		if(socre>S.point||i<=8)
		{
			fclose(fp);
			S.point=socre;
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\20 Type your name to save the score : ");
			fflush(stdin);
		    scanf("%s",S.Name);
			fp=fopen("High_Scores_Dominoes.rgit","a+b");
			fprintf(fp,"%s %d\n",S.Name,S.point);
	    	fp=fopen("High_Scores_Dominoes.rgit","a+b");
			fprintf(fp,"%s %d\n",S.Name,S.point);
			//--------------------------------------------
			fclose(fp);
			Up_Date_Socre_For_High();
			return;
		}
		if(feof(fp)) break;
		i++;

		}
		fclose(fp);	
	}		

}

//////////////////////////////////////////////////////////////////




void About_Team()  
{
	int i;
	 system("cls");
	 printf("\n     \4 Team Information..");
	 printf("\n -------------------------------------------------------------------------------");
     printf("\n\t          \17  Rajiv Gandhi Institute of Technology  \17 ");
	 printf("\n\t             ~~~~~ ~~~~~~ ~~~~~~~~~ ~~ ~~~~~~~~~~\n");
     printf("\n\t        \6 Department of Computer Science & Engineering \6 ");
	 printf("\n\t          ~~~~~~~~~~ ~~ ~~~~~~~~ ~~~~~~~ ~ ~~~~~~~~~~~\n\n");
	 printf("\n\t \3 Computer Science H.O.D : Mr. JAYAPRASAD");
     printf("\n\t   ~~~~~~~~ ~~~~~~~ ~~~~~\n");
     printf("\n\t \3 Data Structure Lecturer : Mr. SANTOSH E");
     printf("\n\t   ~~~~ ~~~~~~~~~ ~~~~~~~~\n\n");
     printf("\n\t \20 Team Number : 105\n");
	 printf("\n\t \20 Team Name : STRUCTURES\n");
	 printf("\n\t \20 Project Name : The Dominoes\n");
     printf("\n\n\t \20 Team Members :-\n");
       printf("\n\t\t\3 Naveen Kumar BV \t\5 Leader 1 \n");
	   printf("\n\t\t\3 Suman           \t\6 Leader 2 \n");
	   printf("\n\t\t\3 N.Rajasekhar\n");
	   printf("\n\t\t\3 Varun\n");
	   printf("\n\t\t\3 Sneha Narayanan\n");
	   printf("\n\t\t\3 Mudit Sharma\n");
	   printf("\n\t\t\3 Ullas\n");
	   printf("\n\t\t\3 Sheela Vasant\n");
	   printf("\n\t\t\3 Vidya K\n");
	   printf("\n\t\t\3 Abdul\n\n\n ");
	for(i=0;i<40;i++)
	{
		printf("\16 ");
	}

}





#endif