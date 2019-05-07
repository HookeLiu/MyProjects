#include <stdio.h>

char zf[] = { "零壹贰叁肆伍陆柒捌玖拾佰仟万亿兆圆角分整" };
char sbuff[200];

void out(char i, char j)
{
	sbuff[j * 2] = zf[i * 2];
	sbuff[j * 2 + 1] = zf[i * 2 + 1];
}

void jiexi(long in1)
{
	char  js = 0, py = 0;
	unsigned int z1, z2, z3, z4, z5, y;
	for (js = 0; js < 200; js++)
		sbuff[js] = 0;

	if (in1 >= 1000000000000000000)//输入大于等于1亿亿
		printf("太尼玛多了mmp");
	else if (in1 < 0)
		printf("Mmp");
	else if (in1 == 0)
		printf("零圆整");
	else
	{
		//qqqqqqqqqqqqqqqqqqq

		z1 = in1 / 100000000000000;//1万亿
		z2 = in1 % 100000000000000 / 10000000000;//取余1万亿除1亿
		z3 = in1 % 10000000000 / 100000;//取余1亿除1w
		z4 = in1 % 1000000 / 100;//取余1w除1元
		z5 = in1 % 100;
		//sssssssssssssssss
		y = z1;
		if (y != 0)
		{
			if (y >= 1000)//如果大于1000
			{
				out(y / 1000, py++);
				out(12, py++);
				if (y % 1000 >= 100)//取余1000大于100
				{
					out(y % 1000 / 100, py++);
					out(11, py++);
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(15, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(15, py++);
					}
				}
				else  // 取余1000小于100
				{
					if (y % 100 >= 10)
					{
						out(0, py++);
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(15, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(15, py++);
					}
				}
			}
			else //如果小于1000
			{
				if (y % 1000 >= 100)//取余1000大于100
				{
					out(y % 1000 / 100, py++);
					out(11, py++);
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(15, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(15, py++);
					}
				}
				else  // 取余1000小于100
				{
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(15, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(y % 100, py++);
							out(15, py++);
						}
					}
				}
			}
		}
		//ssssssssssssssss
		//sssssssssssssssss
		y = z2;
		if (y != 0)
		{
			if ((z1 % 10 == 0) && (py != 0))
				out(0, py++);
			if (y >= 1000)//如果大于1000
			{
				out(y / 1000, py++);
				out(12, py++);
				if (y % 1000 >= 100)//取余1000大于100
				{
					out(y % 1000 / 100, py++);
					out(11, py++);
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(14, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(14, py++);
					}
				}
				else  // 取余1000小于100
				{
					if (y % 100 >= 10)
					{
						out(0, py++);
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(14, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(14, py++);
					}
				}
			}
			else //如果小于1000
			{
				if (y % 1000 >= 100)//取余1000大于100
				{
					out(y % 1000 / 100, py++);
					out(11, py++);
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(14, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(14, py++);
					}
				}
				else  // 取余1000小于100
				{
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(14, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(y % 100, py++);
							out(14, py++);
						}
					}
				}
			}
		}
		//ssssssssssssssss
		//dddddddddddddd
		//sssssssssssssssss
		y = z3;
		if (y != 0)
		{
			if ((z2 % 10 == 0) && (py != 0))
				out(0, py++);
			if (y >= 1000)//如果大于1000
			{
				out(y / 1000, py++);
				out(12, py++);
				if (y % 1000 >= 100)//取余1000大于100
				{
					out(y % 1000 / 100, py++);
					out(11, py++);
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(13, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(13, py++);
					}
				}
				else  // 取余1000小于100
				{
					if (y % 100 >= 10)
					{
						out(0, py++);
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(13, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(13, py++);
					}
				}
			}
			else //如果小于1000
			{
				if (y % 1000 >= 100)//取余1000大于100
				{
					out(y % 1000 / 100, py++);
					out(11, py++);
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(13, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(13, py++);
					}
				}
				else  // 取余1000小于100
				{
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(13, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(y % 100, py++);
							out(13, py++);
						}
					}
				}
			}
		}
		//ssssssssssssssss
		//fffffffffffffffff
		//sssssssssssssssss
		y = z4;
		if (y != 0)
		{
			if ((z3 % 1 == 0) && (py != 0))
				out(0, py++);
			if (y >= 1000)//如果大于1000
			{
				out(y / 1000, py++);
				out(12, py++);
				if (y % 1000 >= 100)//取余1000大于100
				{
					out(y % 1000 / 100, py++);
					out(11, py++);
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(16, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(16, py++);
					}
				}
				else  // 取余1000小于100
				{
					if (y % 100 >= 10)
					{
						out(0, py++);
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(16, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(16, py++);
					}
				}
			}
			else //如果小于1000
			{
				if (y % 1000 >= 100)//取余1000大于100
				{
					out(y % 1000 / 100, py++);
					out(11, py++);
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(16, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(0, py++);
							out(y % 100, py++);
						}
						out(16, py++);
					}
				}
				else  // 取余1000小于100
				{
					if (y % 100 >= 10)
					{
						out(y % 100 / 10, py++);
						out(10, py++);
						if (y % 10 >= 1)
							out(y % 10, py++);
						out(16, py++);
					}
					else
					{
						if (y % 100 >= 1)
						{
							out(y % 100, py++);
							out(16, py++);
						}
					}
				}
			}
		}
		else
			out(16, py++);
		//ssssssssssssssss
		//ggggggggggggg
		y = z5;
		if (y >= 10)
		{
			out(y / 10, py++);
			out(17, py++);
			if (y % 10 >= 1)
			{
				out(y % 10, py++);
				out(18, py++);
			}
			else
				out(19, py++);
		}
		else
		{
			if (y >= 1)
			{
				out(0, py++);
				out(y, py++);
				out(18, py++);
			}
			else
				out(19, py++);
		}
		//qqqqqqqqqqqqqqqqqq
	}
}

int main()
{
	jiexi(320405001005);
	//三十二亿零四百零五万零一拾元零五分
	printf("%s", sbuff);
}



