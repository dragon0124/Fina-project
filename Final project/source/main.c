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

void set(card poker[], int num[], int suit[]);						//設定牌
void intercard(int num[], int suit[]);								//輸入牌
void incard(card cards[], int num[], int suit[], int bark);			//抽牌
int bet(int money[],int bark[]);										//下注
int judge(const char *suit_name[], int num[], int suit[],int bark);	//判斷
void bubble(int n[], int s[]);										//氣泡排序
int maxs(int a,int b,int c,int d);									//比大小


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
	const char *suit_name[] = { "梅花", "方塊", "愛心", "黑桃" ,"    "};
	const char *numble[] = { " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "11", "12", "13", "  ", };
	card cards[52];													//設定52組牌資料
	poker player,pc[3];												//玩家數量

	srand(time(NULL));												//設定亂數種子
	b = 1;															//第幾場
	c = 0;															//c=1，結束

	printf("一局一百元(初始金額1000)\n1單位為一百，若輸入超過賭金視為梭哈\n同花順> 四條> 葫蘆> 同花> 順子> 三條> 兩對> 一對> 雜牌\n\n");
	while (c!=1)
	{
		printf("Game %d\n", b);
		b = b + 1;
		set(cards, num, suit);											//將cards陣列設定為一副牌
		//intercard(player.num, player.suit);							//手動輸入自己的牌
		incard(cards, player.num, player.suit,bark[0]);					//自動發牌

		for (i = 0; i < 3; i++)											//自動發牌
		{
			incard(cards, pc[i].num, pc[i].suit,bark[i+1]);
		}
		total = 0;
		for (i = 0; i < 4; i++)											//基本下注
		{
			if (bark[i] == 1)
			{
				total = total + 100;
				money[i] = money[i] - 100;
			}
		}

		for (i = 0; i < 5; i++)											//印出每個人的牌
		{
			printf("   Player $%-4d\t\tPC1 $%-4d\t\tPC2 $%-4d\t\tPC3 $%-4d\t賭金%-4d\n", money[0], money[1], money[2], money[3], total);
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
					a = bet(money, bark);								//下注
					total = total + a;									//總賭金
				}
				else
					printf("\n");
			};
		}
		printf("\n   ");

		p1 = judge(suit_name, player.num, player.suit,bark[0]);					//判斷牌
		for (i = 0; i < 3; i++)
		{
			pc_s[i] = judge(suit_name, pc[i].num, pc[i].suit,bark[i+1]);
		}
		//printf("\n%-24d%-24d%-24d%-24d\n\t", p1, pc_s[0], pc_s[1], pc_s[2]);	//比較值
		//printf("\t");
		max = maxs(p1, pc_s[0], pc_s[1], pc_s[2]);
		if (p1 == max)															//找誰贏
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
		if (bark[0] == 0)														//player破產
		{
			printf("\tYOU LOSE!!\n");
			c = 1;
		}
		if ((bark[1] == 0) && (bark[2] == 0) && (bark[3] == 0))					//PC1~PC3破產
		{
			printf("\tYOU WIN!!\n");
			c = 1;
		}
	}

	system("pause");
	return 0;
}


void intercard(int num[], int suit[])									//輸入牌
{
	int i, j;
	int a;
	printf("請輸入5張不同的牌\n(梅花 1 ,方塊 2 ,愛心 3 ,黑桃 4)\n\n");

	for (i = 0; i < 5; i++)
	{
		do
		{
			a = 0;
			do
			{
				printf("輸入第%d張牌花色:", i + 1);
				scanf_s("%d", &suit[i]);
				if (suit[i]<1 || suit[i]>4)
					printf("輸入錯誤請重新輸入\n");
			} while (suit[i]<1 || suit[i]>4);
			do
			{
				printf("輸入第%d張牌數字:", i + 1);
				scanf_s("%d", &num[i]);
				if (num[i]<1 || num[i]>13)
					printf("輸入錯誤請重新輸入\n");
			} while (num[i]<1 || num[i]>13);
			for (j = 0; j < i; j++)
			{
				if ((num[i] == num[j]) && (suit[i] == suit[j]))
				{
					a = 1;
					printf("重複輸入，請重新輸入\n");
				}
			}
		} while (a == 1);
	}
	bubble(num, suit);
}







