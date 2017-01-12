void bubble(int n[], int s[])										//®ðªw
{
	int i, j;
	int a, b;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4 - i; j++)
		{
			if (n[j] < n[j + 1])
			{
				a = n[j];
				b = s[j];
				n[j] = n[j + 1];
				s[j] = s[j + 1];
				n[j + 1] = a;
				s[j + 1] = b;
			}
		}
	}
}

int maxs(int a, int b, int c, int d)								//§ä³Ì¤j
{
	if (a < b)
		a = b;
	if (a < c)
		a = c;
	if (a < d)
		a = d;
	return a;
}