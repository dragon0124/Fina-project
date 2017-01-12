#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Bet 1000

typedef struct pokers
{
	int num[5];
	int suit[5];
}poker;
typedef struct cards
{
	int num;
	int suit;
}card;

void set(card poker[], int num[], int suit[]);						//�]�w�P
void intercard(int num[], int suit[]);								//��J�P
void incard(card cards[], int num[], int suit[], int bark);			//��P
int bet(int money[],int bark[]);										//�U�`
int judge(const char *suit_name[], int num[], int suit[],int bark);	//�P�_
void bubble(int n[], int s[]);										//��w�Ƨ�
int maxs(int a,int b,int c,int d);									//��j�p


#include "5.h"
#include "25.h"
#include "19.h"
#include "28.h"
int main(void)
{
	int i,j,k,a,b,c;
	int total,max,p1, pc_s[3];
	int bark[4] = { 1, 1, 1, 1 };
	int money[4] = { Bet, Bet, Bet, 200 };
	int num[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int suit[4] = { 1, 2, 3, 4 };
	const char *suit_name[] = { "����", "���", "�R��", "�®�" ,"    "};
	const char *numble[] = { " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "11", "12", "13", "  ", };
	card cards[52];													//�]�w52�յP���
	poker player,pc[3];												//���a�ƶq

	srand(time(NULL));												//�]�w�üƺؤl
	b = 1;															//�ĴX��
	c = 0;															//c=1�A����

	printf("�@���@�ʤ�(��l���B1000)\n1��쬰�@�ʡA�Y��J�W�L�����������\n�P�ᶶ> �|��> ��Ī> �P��> ���l> �T��> ���> �@��> ���P\n\n");
	while (c!=1)
	{
		printf("Game %d\n", b);
		b = b + 1;
		set(cards, num, suit);											//�Ncards�}�C�]�w���@�ƵP
		//intercard(player.num, player.suit);							//��ʿ�J�ۤv���P
		incard(cards, player.num, player.suit,bark[0]);					//�۰ʵo�P

		for (i = 0; i < 3; i++)											//�۰ʵo�P
		{
			incard(cards, pc[i].num, pc[i].suit,bark[i+1]);
		}
		total = 0;
		for (i = 0; i < 4; i++)											//�򥻤U�`
		{
			if (bark[i] == 1)
			{
				total = total + 100;
				money[i] = money[i] - 100;
			}
		}

		for (i = 0; i < 5; i++)											//�L�X�C�ӤH���P
		{
			printf("   Player $%-4d\t\tPC1 $%-4d\t\tPC2 $%-4d\t\tPC3 $%-4d\t���%-4d\n", money[0], money[1], money[2], money[3], total);
			for (j = 0; j < i + 1; j++)
			{
				printf("%d  %s\t   %s\t\t", j + 1, suit_name[player.suit[j] - 1], numble[player.num[j]-1]);
				for (k = 0; k < 3; k++)
				{
					printf("%s\t%s\t\t", suit_name[pc[k].suit[j] - 1], numble[pc[k].num[j]-1]);
				}
				printf("\n");
			}
			if (i < 4)
			{
				if (money[0] != 0)
				{
					a = bet(money, bark);								//�U�`
					total = total + a;									//�`���
				}
				else
					printf("\n");
			};
		}
		printf("\n   ");

		p1 = judge(suit_name, player.num, player.suit,bark[0]);					//�P�_�P
		for (i = 0; i < 3; i++)
		{
			pc_s[i] = judge(suit_name, pc[i].num, pc[i].suit,bark[i+1]);
		}
		//printf("\n%-24d%-24d%-24d%-24d\n\t", p1, pc_s[0], pc_s[1], pc_s[2]);	//�����
		//printf("\t");
		max = maxs(p1, pc_s[0], pc_s[1], pc_s[2]);
		if (p1 == max)															//���Ĺ
		{
			money[0] = money[0] + total;
			printf("\n   Player +$%d\n",total);
		}
		for (i = 0; i < 3; i++)
		{
			if (pc_s[i] == max)
			{
				money[i + 1] = money[i + 1] + total;
				printf("\n   PC%d +$%d\n",i+1, total);
			}
		}
		for (i = 0; i < 4; i++)
		{
			if (money[i] == 0)
				bark[i] = 0;
		}
		printf("\n   Player $%-4d\t\tPC1 $%-4d\t\tPC2 $%-4d\t\tPC3 $%-4d\n", money[0], money[1], money[2], money[3]);
		printf("\n");
		if (bark[0] == 0)														//player�}��
		{
			printf("\tYOU LOSE!!\n");
			c = 1;
		}
		if ((bark[1] == 0) && (bark[2] == 0) && (bark[3] == 0))					//PC1~PC3�}��
		{
			printf("\tYOU WIN!!\n");
			c = 1;
		}
	}

	system("pause");
	return 0;
}


void intercard(int num[], int suit[])									//��J�P
{
	int i, j;
	int a;
	printf("�п�J5�i���P���P\n(���� 1 ,��� 2 ,�R�� 3 ,�®� 4)\n\n");

	for (i = 0; i < 5; i++)
	{
		do
		{
			a = 0;
			do
			{
				printf("��J��%d�i�P���:", i + 1);
				scanf_s("%d", &suit[i]);
				if (suit[i]<1 || suit[i]>4)
					printf("��J���~�Э��s��J\n");
			} while (suit[i]<1 || suit[i]>4);
			do
			{
				printf("��J��%d�i�P�Ʀr:", i + 1);
				scanf_s("%d", &num[i]);
				if (num[i]<1 || num[i]>13)
					printf("��J���~�Э��s��J\n");
			} while (num[i]<1 || num[i]>13);
			for (j = 0; j < i; j++)
			{
				if ((num[i] == num[j]) && (suit[i] == suit[j]))
				{
					a = 1;
					printf("���ƿ�J�A�Э��s��J\n");
				}
			}
		} while (a == 1);
	}
	bubble(num, suit);
}







