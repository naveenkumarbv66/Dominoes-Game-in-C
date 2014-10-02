#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>

struct Point
{
	char Name[15];
	int point;
}S;
char char_arrya[9][10];
int Integer_arrya[9];
FILE *fp;


void Coppy_5(int i)
{
	int k=0;

	while(char_arrya[i][k]!='\0')
	{
		S.Name[k]=char_arrya[i][k];
		k++;
	}
	
	S.Name[k]='\0';
}

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


void Copy_4(int i)
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

void Up_Date_Socre()
{
	int i,j,count=0,temp;
	
	fp=fopen("High_Scores_Dominoes.txt","rb");
	while(1)
	{
	fscanf(fp,"%s %d",S.Name,&S.point);
	if(feof(fp))
		break;
	    Integer_arrya[count]=S.point;
		Copy_2(count);
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
				Copy_1(i);

				Integer_arrya[i]=Integer_arrya[i+1];
				Copy_4(i);

				Integer_arrya[i+1]=temp;
				Copy_2(i+1);
			}
		}
	}

  fp=fopen("High_Scores_Dominoes.txt","wb");

  if(count>8) count=8;

	for(i=0;i<count;i++)
	{
		S.point=Integer_arrya[i];
		Coppy_5(i);
		fprintf(fp,"%s %d\n",S.Name,S.point);
		
	}
	fclose(fp);



}



void MAIN(int socre)
{
	int i=1;
    system("cls");
		
		fp=fopen("High_Scores_Dominoes.txt","rb");

	if(fp==NULL)
	{
		fp=fopen("High_Scores_Dominoes.txt","wb");
		S.point=socre;
		printf("\n\n\n\n\n\n\n\n\n\t\20 Enter Your Name : ");
		scanf("%s",S.Name);
		fprintf(fp,"%s %d\n",S.Name,S.point);
		fclose(fp);
		return;

	}
	else
	{
		fp=fopen("High_Scores_Dominoes.txt","rb");
		while(1)
		{
		fscanf(fp,"%s %d\n",S.Name,&S.point);
		
		if(socre>S.point||i<=5)
		{
			fclose(fp);
			S.point=socre;
			printf("\n\n\n\n\n\n\n\n\n\t\20 Enter Your Name : ");
		    scanf("%s",S.Name);
			fp=fopen("High_Scores_Dominoes.txt","a+b");
			fprintf(fp,"%s %d\n",S.Name,S.point);
			fclose(fp);
			Up_Date_Socre();
			return;
		}
		if(feof(fp)) break;
		i++;

		}
		fclose(fp);	
	}		

}

