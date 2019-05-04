#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
	int nume;
	int deno;
}FRAC;

void Main_loop(int I_Num[]);
void Main_calc(FRAC P_Num[]);
FRAC operant(int R,FRAC x,FRAC y);
void print_ope(int R);
int gcd(int m, int n);
void normalize(FRAC *f);
void pattern1(FRAC P_Num[],int R1,int R2,int R3);

int main(void)
{
	int i,number;
	int numbers[4]={0,0,0,0};
	char num_str[4];
	char tmp_str[1];
	printf("Input 4 Numbers \'1234\'\n");
	scanf("%s",num_str);

	if(strlen(num_str) != 4)
	{
		printf("Please Input 4digits!!\n");
		exit(1);
	}

	for (i=0;i<4;i++)
	{
		tmp_str[0] = num_str[i];
		numbers[i] = num_str[i]-48;
	}

	Main_loop(numbers);

	return 0;
}


void Main_loop(int I_Num[])
{
	int R1,R2,R3,R4,i;
	FRAC P_Num[4];

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
								P_Num[0].nume=I_Num[R1];
								P_Num[1].nume=I_Num[R2];
								P_Num[2].nume=I_Num[R3];
								P_Num[3].nume=I_Num[R4];
								P_Num[0].deno = 1;
								P_Num[1].deno = 1;
								P_Num[2].deno = 1;
								P_Num[3].deno = 1;

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



void Main_calc(FRAC P_Num[])
{
	int i;
	int R1,R2,R3;
	int Calc_Res = 0;
	FRAC t_R1,t_R2,t_R3;

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
				pattern1(P_Num,R1,R2,R3);
			}
		}
	}
}

void pattern1(FRAC P_Num[],int R1,int R2,int R3)
{
	int Calc_Res = 0;
	FRAC t_R1,t_R2,t_R3;
	t_R1 = operant(R1,P_Num[0],P_Num[1]);
	t_R2 = operant(R2,t_R1,P_Num[2]);
	t_R3 = operant(R3,t_R2,P_Num[3]);

	if(t_R3.nume%t_R3.deno == 0)
	{
		Calc_Res = t_R3.nume/t_R3.deno;
		if(Calc_Res == 10)
		{
			printf("Success!!  Formula : ");
			//printf("t_R1:%d/%d t_R2:%d/%d t_R3:%d/%d ",t_R1.nume,t_R1.deno,t_R2.nume,t_R2.deno,t_R3.nume,t_R3.deno);
			//printf("Res:%d",Calc_Res);
			printf("%d",P_Num[0].nume);
			print_ope(R1);
			printf("%d",P_Num[1].nume);
			print_ope(R2);
			printf("%d",P_Num[2].nume);
			print_ope(R3);
			printf("%d",P_Num[3].nume);
			printf("\n");
		}
	}
}



int gcd(int m, int n)
{
   int i;

   if(m < 0) m = -m;
   if(n < 0) n = -n;

   if(m < n){
      i = m; m = n; n = i;
   }
   while(n > 0) {
      i = m % n; m = n; n = i;
   }
   return m;
}

void normalize(FRAC *f)
{
	if(f->nume != 0)
	{
		int t_gcd;
		t_gcd = gcd(f->nume,f->deno);
		f->nume/=t_gcd;
		f->deno/=t_gcd;
	}else{
		f->deno = 1;
	}
}

FRAC operant(int R,FRAC x,FRAC y)
{
	FRAC Res;
	switch (R)
	{
		case 0:Res.nume = x.nume*y.deno + x.deno*y.nume;Res.deno = x.deno*y.deno;normalize(&Res);break;
		case 1:Res.nume = x.nume*y.deno - x.deno*y.nume;Res.deno = x.deno*y.deno;normalize(&Res);break;
		case 2:Res.nume = x.nume*y.nume;Res.deno = x.deno*y.deno;normalize(&Res);break;
		case 3:Res.nume = x.nume*y.deno;Res.deno = x.deno*y.nume;normalize(&Res);break;
		default:Res.nume = 1000;break;
	}
	return Res;
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
