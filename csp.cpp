#include <stdio.h>
#include <math.h>
#include <string.h>
 

#define Max_len 20000001
#define Out_line 100000
#define Max_back 65535
int n, count, mark;
char ans[Max_len];
int l, r;

void dispose1(long long len);
void dispose2(int len, int o);
void output();

int main()
{
	char tepc1, tepc2;
	long long num1, num2, i, j, k, o;
	long long len, teplen;
	scanf("%d\n", &n);
	do{
		scanf("%c%c", &tepc1, &tepc2);
		count += 2;
		if(!(count % 16))
		{
			getchar();
		}
	}
	while(tepc1 >= '8');
	while(count < 2 * n)
	{
		scanf("%c%c", &tepc1, &tepc2);
		count += 2; 
		if(!(count % 16))
		{
			getchar();
		}
		if(tepc1 <= '9')
		{
			num1 = tepc1 - '0';
		}
		else {
			num1 = tepc1 - 'a' + 10;
		}
		if(tepc2 <= '9')
		{
			num2 = tepc2 - '0';
		}
		else {
			num2 = tepc2 - 'a' + 10;
		}
		if(num2 % 4 == 0)
		{
			len = (unsigned)((16 * num1 + num2) >> 2);
			if(len <= 59);
			else 
			{
				teplen = len;
				len = 0;
				for(i = 0; i < teplen - 59; i++)
				{
					scanf("%c%c", &tepc1, &tepc2);
					count += 2;
					if(!(count % 16))
					{
						getchar();
					} 
					if(tepc1 <= '9')
					{
						num1 = tepc1 - '0';
					}
					else {
						num1 = tepc1 - 'a' + 10;
					}
					if(tepc2 <= '9')
					{
						num2 = tepc2 - '0';
					}
					else {
						num2 = tepc2 - 'a' + 10;
					}
					len = len * 16 * 16 + num1 * 16 + num2;
				}
			}
			len += 1;
			dispose1(len);
		}
		else 
		{
			if(num2 % 2)
			{
				len = 0;
				o = 0;
				len = (num2 >>2 )+ ((num1 % 1) << 2 ) + 4;
				o = ((num1 >> 1) << 8);
				scanf("%c%c", &tepc1, &tepc2);
				if(!(count % 16))
				{
					getchar();
				} 
				count += 2;
				if(tepc1 <= '9')
				{
					num1 = tepc1 - '0';
				}
				else {
					num1 = tepc1 - 'a' + 10;
				}
				if(tepc2 <= '9')
				{
					num2 = tepc2 - '0';
				}
				else {
					num2 = tepc2 - 'a' + 10;
				}
				o += num1 * 16 + num2;
			}
			else
			{
				len = 0;
				o = 0;
				len = (num2>> 2) + (num1 << 2 )+ 1;
				scanf("%c%c", &tepc1, &tepc2);
				count += 2;
				if(!(count % 16))
				{
					getchar();
				} 
				if(tepc1 <= '9')
				{
					num1 = tepc1 - '0';
				}
				else {
					num1 = tepc1 - 'a' + 10;
				}
				if(tepc2 <= '9')
				{
					num2 = tepc2 - '0';
				}
				else {
					num2 = tepc2 - 'a' + 10;
				}
				o += (num1 * 16 + num2);
				scanf("%c%c", &tepc1, &tepc2);
				count += 2;
				if(!(count % 16))
				{
					getchar();
				}
				if(tepc1 <= '9')
				{
					num1 = tepc1 - '0';
				}
				else {
					num1 = tepc1 - 'a' + 10;
				}
				if(tepc2 <= '9')
				{
					num2 = tepc2 - '0';
				}
				else {
					num2 = tepc2 - 'a' + 10;
				}
				o += (num1 * 16 + num2) * 16 * 16;
			}
			dispose2(len * 2, o * 2);
		}
	}
	len = (r - l) % Max_len;
	for(i = 0; i < len; i++)
	{
		printf("%c", ans[l]);
		l++;
		mark++;
		if(mark == 16)
		{
			printf("\n");
			mark = 0;
		}
		if(l == Max_len)
		{
			l = 0;
		}
	}

	return 0;
}

void dispose1(long long len)
{
	char tepc1, tepc2;
	int num1, num2, i;
	for(i = 0; i < 2 * len; i++)
	{
		scanf("%c", ans + r);
		count++;
		if(!(count % 16))
		{
			getchar();
		}
		r++;
	}
}

void dispose2(int len, int o)
{
	int tep, i, pos, ori = r;
	tep = r - o;
	pos = tep;
	for(i = 0; i < len; i++)
	{
		ans[r] = ans[pos];
		r++;
		pos++;
		if(pos == ori)
		{
			pos = tep;
		}
	}
	
}

