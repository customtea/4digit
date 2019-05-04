#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void Main_loop(int I_Num[]);
void Main_calc(int P_Num[]);
int operant(int R,int x,int y);
void print_ope(int R);

int main(void)
{
	int i,number;
	int numbers[4];
	printf("Input 4 Numbers \'1234\'\n");
	scanf("%d",&number);

	if(number < 1000 || 10000 <= number)
	{
		printf("Please Input 4digits!!\n");
		exit(1);
	}

	numbers[0]=number/1000;
	numbers[1]=number%1000;
	numbers[1]=numbers[1]/100;
	numbers[2]=number%100;
	numbers[2]=numbers[2]/10;
	numbers[3]=number%10;

	Main_loop(numbers);

	return 0;


}


void Main_loop(int I_Num[])
{
	int R1,R2,R3,R4,i;
	int P_Num[4];

	for(R1=0;R1<4;R1++)
	{
		for(R2=0;R2<4;R2++)
		{
			if(R2!=R1)
			{
				for(R3=0;R3<4;R3++)
				{
					if(R3!=R1 && R3!=R2)
					{
						for(R4=0;R4<4;R4++)
						{
							if(R4!=R1 && R4!=R2 && R4!=R3 )
							{
								P_Num[0]=I_Num[R1];
								P_Num[1]=I_Num[R2];
								P_Num[2]=I_Num[R3];
								P_Num[3]=I_Num[R4];

								Main_calc(P_Num);

								/*
								for(i=0;i<4;i++)
								{
									printf("%d",P_Num[i]);
								}
								printf("\n");
								*/
							}
						}
					}
				}
			}
		}
	}
}



void Main_calc(int P_Num[])
{
	int i;
	int R1,R2,R3;
	int Calc_Res = 0;
	int t_R1,t_R2,t_R3;

	/*
	for(i=0;i<4;i++)
	{
		printf("%d",P_Num[i]);
	}
	printf("\n");
	*/

	for(R1=0;R1<4;R1++)
	{
		for(R2=0;R2<4;R2++)
		{
			for(R3=0;R3<4;R3++)
			{


				t_R1 = operant(R1,P_Num[0],P_Num[1]);
				if(t_R1 == 1000)break;
				t_R2 = operant(R2,t_R1,P_Num[2]);
				if(t_R2 == 1000)break;
				t_R3 = operant(R3,t_R2,P_Num[3]);
				if(t_R3 == 1000)break;

				Calc_Res = t_R3;

				if(Calc_Res == 10)
				{
					printf("Success!!  Formula : ");
					//printf("t_R1:%d t_R2:%d t_R3:%d",t_R1,t_R2,t_R3);
					//printf("Res:%d",Calc_Res);
					printf("%d",P_Num[0]);
					print_ope(R1);
					printf("%d",P_Num[1]);
					print_ope(R2);
					printf("%d",P_Num[2]);
					print_ope(R3);
					printf("%d",P_Num[3]);
					printf("\n");
				}
			}
		}
	}
}


int operant(int R,int x,int y)
{
	switch (R)
	{
		case 0:return x+y;
		case 1:return x-y;
		case 2:return x*y;
		case 3:if(y != 0 && x%y == 0) return x/y; break;
		default: break;
	}
	return 1000;
}

void print_ope(int R)
{
	switch (R)
	{
		case 0: printf("+");break;
		case 1: printf("-");break;
		case 2: printf("x");break;
		case 3: printf("/");break;
		default: printf("Miss!");break;
	}
}
