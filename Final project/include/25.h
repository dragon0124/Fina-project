int bet(int money[], int bark[])											//�U�`
{
	int i;
	int	bet;
	int total = 0;

	printf("   ��J�U�`���B(1=> $100)\n   ?");
	scanf_s("%d", &bet);

	if (100 * bet >= money[0])											//�Y�j�󵥩󥻪���������
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
			if (bark[i] == 1)											//�O�_�}��
			{
				if (money[i] < 100 * bet)								//�Y���������U�`���B�A�N����
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