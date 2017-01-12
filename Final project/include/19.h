int judge(const char *suit_name[], int num[], int suit[], int bark)				//判斷
{
	int i, j;
	int a, b, c;
	int suits = 0;
	int continues = 0;
	int	judges;
	int pokernum[13] = { 0 };
	int renum[5] = { 0 };

	if (bark == 1)
	{
		for (i = 0; i < 4; i++)				//同花色，suits=4全部同花色
		{
			if (suit[i] == suit[i + 1])
				suits = suits + 1;
		}
		for (i = 0; i < 5; i++)				//1~13的數字有幾個
		{
			pokernum[num[i] - 1] = pokernum[num[i] - 1] + 1;
		}
		for (i = 0; i < 9; i++)				//順子
		{
			if (((pokernum[i] == 1) && (pokernum[i + 1] == 1) && (pokernum[i + 2] == 1) && (pokernum[i + 3] == 1) && (pokernum[i + 4] == 1)) || ((pokernum[0] == 1) && (pokernum[9] == 1) && (pokernum[10] == 1) && (pokernum[11] == 1) && (pokernum[12] == 1)))
				continues = 1;
		}
		for (i = 2; i < 5; i++)				//重複的數字，renum[i]為重複i次的有幾個數
		{
			for (j = 0; j < 13; j++)
			{
				if (pokernum[j] == i)
					renum[i] = renum[i] + 1;
			}
		}
		if (renum[4] == 1)					//判斷 雜牌、 一對、 兩對、 三條、 順子、 同花、 葫蘆、 鐵之、 同花順
		{
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 4)
					a = i + 1;
			}
			printf("鐵支\t%d鐵\t", a);
			if ((a == 1) || (a == 2))		//撲克中1、2最大(1=>14，2=>15)
			{
				b = a + 13;
			}
			else
				b = a;
			judges = 8000 + b;				//十位個位是牌的數字
		}
		else if ((renum[3] == 1) && (renum[2] == 1))
		{
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 3)
					a = i + 1;
			}
			printf("葫蘆\t%d蘆\t", a);
			if ((a == 1) || (a == 2))		//撲克中1、2最大(1=>14，2=>15)
			{
				b = a + 13;
			}
			else
				b = a;
			judges = 7000 + b;				//十位個位是牌的數字
		}
		else if (renum[3] == 1)
		{
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 3)
					a = i + 1;
			}
			printf("三條\t三條%d\t", a);
			if ((a == 1) || (a == 2))		//撲克中1、2最大(1=>14，2=>15)
			{
				b = a + 13;
			}
			else
				b = a;
			judges = 4000 + b;				//十位個位是牌的數字
		}
		else if (renum[2] == 2)
		{
			printf("兩對\t");
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 2)
				{
					a = i + 1;
					printf("%d啤 ", a);
					if ((a == 1) || (a == 2))				//撲克中1、2最大(1=>14，2=>15)
					{
						b = a + 13;
						for (j = 0; j < 5; j++)
						{
							if (num[j] == a)
								c = j;
						}
					}
				}
			}
			if (b != 14)
			{
				if (b != 15)
				{
					b = a;
					for (i = 0; i < 5; i++)
					{
						if (num[i] == a)
							c = i;
					}
				}
			}
			if (suit[c] < suit[c - 1])
				c = c - 1;
			judges = 3000 + b * 10 + suit[c];				//十位百位是牌的數字，個位是花色
		}
		else if (renum[2] == 1)
		{
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 2)
					a = i + 1;
			}
			printf("一對\t%d啤\t", a);
			if ((a == 1) || (a == 2))						//撲克中1、2最大(1=>14，2=>15)
			{
				b = a + 13;
			}
			else
				b = a;
			for (i = 0; i < 5; i++)
			{
				if (num[i] == a)
					c = i;
			}
			if (suit[c] < suit[c - 1])
				c = c - 1;
			judges = 2000 + b * 10 + suit[c];				//十位百位是牌的數字，個位是花色
		}
		else if ((suits == 4) && (continues == 1))
		{
			for (i = 0; i < 9; i++)
			{
				if ((pokernum[i] == 1) && (pokernum[i + 1] == 1) && (pokernum[i + 2] == 1) && (pokernum[i + 3] == 1) && (pokernum[i + 4] == 1))
				{
					a = i + 1;
					b = a + 4;
				}
				else if ((pokernum[0] == 1) && (pokernum[9] == 1) && (pokernum[10] == 1) && (pokernum[11] == 1) && (pokernum[12] == 1))
				{
					a = 10;
					b = 1;
				}
			}
			printf("同花順\t%s %d~%d", suit_name[suit[1] - 1], a, b);
			judges = 9000 + suit[1] * 100 + a;							//十位個位是順子最小的數字，百位是花色
		}
		else if (suits == 4)
		{
			printf("同花\t%s\t", suit_name[suit[1] - 1]);
			if ((num[4] == 2) || num[3] == 2)		//撲克中1、2最大(2=>15)
			{
				a = 15;
			}
			else if (num[4] == 1)					//撲克中1、2最大(1=>14)
			{
				a = 14;
			}
			else
			{
				a = num[0];
			}
			judges = 6000 + suit[1] * 100 + a;						//十位個位是牌的數字，百位是花色
		}
		else if (continues == 1)
		{
			for (i = 0; i < 9; i++)
			{
				if ((pokernum[i] == 1) && (pokernum[i + 1] == 1) && (pokernum[i + 2] == 1) && (pokernum[i + 3] == 1) && (pokernum[i + 4] == 1))
				{
					a = i + 1;
					b = a + 4;
				}
				else if ((pokernum[0] == 1) && (pokernum[9] == 1) && (pokernum[10] == 1) && (pokernum[11] == 1) && (pokernum[12] == 1))
				{
					a = 10;
					b = 1;
				}
			}
			printf("順子\t%d~%d\t", a, b);
			for (i = 0; i < 5; i++)
			{
				if (num[i] == b)
					c = suit[i];
			}
			judges = 5000 + a * 10 + c;								//十位百位是順子最小的數字，個位是第一位的花色
		}
		else
		{
			printf("雜牌\t\t");
			if ((num[4] == 2) || num[3] == 2)						//撲克中1、2最大(2=>15)
			{
				a = 15;
				for (i = 0; i < 2; i++)
				{
					if (num[3 + i] == 2)
						b = suit[3 + i];
				}
			}
			else if (num[4] == 1)									//撲克中1、2最大(1=>14)
			{
				a = 14;
				b = suit[4];
			}
			else
			{
				a = num[0];
				b = suit[0];
			}
			judges = 1000 + a * 10 + b;								//十位百位是最大的數字，個位是最大數字的花色
		}
	}
	else
	{
		printf("破產\t\t");
		judges = 0;
	}
	printf("\t");
	return judges;
}