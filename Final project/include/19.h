int judge(const char *suit_name[], int num[], int suit[], int bark)				//�P�_
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
		for (i = 0; i < 4; i++)				//�P���Asuits=4�����P���
		{
			if (suit[i] == suit[i + 1])
				suits = suits + 1;
		}
		for (i = 0; i < 5; i++)				//1~13���Ʀr���X��
		{
			pokernum[num[i] - 1] = pokernum[num[i] - 1] + 1;
		}
		for (i = 0; i < 9; i++)				//���l
		{
			if (((pokernum[i] == 1) && (pokernum[i + 1] == 1) && (pokernum[i + 2] == 1) && (pokernum[i + 3] == 1) && (pokernum[i + 4] == 1)) || ((pokernum[0] == 1) && (pokernum[9] == 1) && (pokernum[10] == 1) && (pokernum[11] == 1) && (pokernum[12] == 1)))
				continues = 1;
		}
		for (i = 2; i < 5; i++)				//���ƪ��Ʀr�Arenum[i]������i�������X�Ӽ�
		{
			for (j = 0; j < 13; j++)
			{
				if (pokernum[j] == i)
					renum[i] = renum[i] + 1;
			}
		}
		if (renum[4] == 1)					//�P�_ ���P�B �@��B ���B �T���B ���l�B �P��B ��Ī�B �K���B �P�ᶶ
		{
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 4)
					a = i + 1;
			}
			printf("�K��\t%d�K\t", a);
			if ((a == 1) || (a == 2))		//���J��1�B2�̤j(1=>14�A2=>15)
			{
				b = a + 13;
			}
			else
				b = a;
			judges = 8000 + b;				//�Q��Ӧ�O�P���Ʀr
		}
		else if ((renum[3] == 1) && (renum[2] == 1))
		{
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 3)
					a = i + 1;
			}
			printf("��Ī\t%dĪ\t", a);
			if ((a == 1) || (a == 2))		//���J��1�B2�̤j(1=>14�A2=>15)
			{
				b = a + 13;
			}
			else
				b = a;
			judges = 7000 + b;				//�Q��Ӧ�O�P���Ʀr
		}
		else if (renum[3] == 1)
		{
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 3)
					a = i + 1;
			}
			printf("�T��\t�T��%d\t", a);
			if ((a == 1) || (a == 2))		//���J��1�B2�̤j(1=>14�A2=>15)
			{
				b = a + 13;
			}
			else
				b = a;
			judges = 4000 + b;				//�Q��Ӧ�O�P���Ʀr
		}
		else if (renum[2] == 2)
		{
			printf("���\t");
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 2)
				{
					a = i + 1;
					printf("%d�� ", a);
					if ((a == 1) || (a == 2))				//���J��1�B2�̤j(1=>14�A2=>15)
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
			judges = 3000 + b * 10 + suit[c];				//�Q��ʦ�O�P���Ʀr�A�Ӧ�O���
		}
		else if (renum[2] == 1)
		{
			for (i = 0; i < 13; i++)
			{
				if (pokernum[i] == 2)
					a = i + 1;
			}
			printf("�@��\t%d��\t", a);
			if ((a == 1) || (a == 2))						//���J��1�B2�̤j(1=>14�A2=>15)
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
			judges = 2000 + b * 10 + suit[c];				//�Q��ʦ�O�P���Ʀr�A�Ӧ�O���
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
			printf("�P�ᶶ\t%s %d~%d", suit_name[suit[1] - 1], a, b);
			judges = 9000 + suit[1] * 100 + a;							//�Q��Ӧ�O���l�̤p���Ʀr�A�ʦ�O���
		}
		else if (suits == 4)
		{
			printf("�P��\t%s\t", suit_name[suit[1] - 1]);
			if ((num[4] == 2) || num[3] == 2)		//���J��1�B2�̤j(2=>15)
			{
				a = 15;
			}
			else if (num[4] == 1)					//���J��1�B2�̤j(1=>14)
			{
				a = 14;
			}
			else
			{
				a = num[0];
			}
			judges = 6000 + suit[1] * 100 + a;						//�Q��Ӧ�O�P���Ʀr�A�ʦ�O���
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
			printf("���l\t%d~%d\t", a, b);
			for (i = 0; i < 5; i++)
			{
				if (num[i] == b)
					c = suit[i];
			}
			judges = 5000 + a * 10 + c;								//�Q��ʦ�O���l�̤p���Ʀr�A�Ӧ�O�Ĥ@�쪺���
		}
		else
		{
			printf("���P\t\t");
			if ((num[4] == 2) || num[3] == 2)						//���J��1�B2�̤j(2=>15)
			{
				a = 15;
				for (i = 0; i < 2; i++)
				{
					if (num[3 + i] == 2)
						b = suit[3 + i];
				}
			}
			else if (num[4] == 1)									//���J��1�B2�̤j(1=>14)
			{
				a = 14;
				b = suit[4];
			}
			else
			{
				a = num[0];
				b = suit[0];
			}
			judges = 1000 + a * 10 + b;								//�Q��ʦ�O�̤j���Ʀr�A�Ӧ�O�̤j�Ʀr�����
		}
	}
	else
	{
		printf("�}��\t\t");
		judges = 0;
	}
	printf("\t");
	return judges;
}