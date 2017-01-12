int bet(int money[], int bark[])											//下注
{
	int i;
	int	bet;
	int total = 0;

	printf("   輸入下注金額(1=> $100)\n   ?");
	scanf_s("%d", &bet);

	if (100 * bet >= money[0])											//若大於等於本金視為梭哈
	{
		for (i = 0; i < 4; i++)
		{
			total = total + money[i];
			money[i] = 0;
		}
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			if (bark[i] == 1)											//是否破產
			{
				if (money[i] < 100 * bet)								//若本金不足下注金額，就全押
				{
					total = total + money[i];
					money[i] = 0;
				}
				else
				{
					total = total + 100 * bet;
					money[i] = money[i] - 100 * bet;
				}
			}
		}
	}
	return total;
}