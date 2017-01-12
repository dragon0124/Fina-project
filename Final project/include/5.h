void set(card poker[], int num[], int suit[])							//設定牌
{
	int i;

	for (i = 0; i < 52; i++)
	{
		poker[i].num = num[i % 13];
		poker[i].suit = suit[i / 13];
	}
}

void incard(card cards[], int num[], int suit[], int bark)						//抽牌
{
	int i;
	int a;

	if (bark == 1)
	{
		for (i = 0; i < 5; i++)
		{
			do
			{
				a = rand() % 52;
				num[i] = cards[a].num;
				suit[i] = cards[a].suit;
			} while ((cards[a].num == 0) && (cards[a].suit == 0));			//重複重抽
			cards[a].num = 0;
			cards[a].suit = 0;
		}
		bubble(num, suit);
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			num[i] = 14;
			suit[i] = 5;
		}
	}
}