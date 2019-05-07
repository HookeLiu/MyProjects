#define  _CRT_SECURE_NO_WARNINGS








#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define WAN 10000
#define SOA SetConsoleTextAttribute
typedef struct CHchar																					CWORD;
/*
作者：中德1708班 柳玉虎 1700002321
*/
struct CHchar
{																															// 使用结构体数组以便汉字处理
	char cbuff[4];/* 这里有点坑，MS的VisualStudio用的是Unicode可是很多其他的如GCC编译器等用的是UTF-8，汉字 
							  占的长度不同输出就会有差别，为了输出统一就3(UTF8)+1(\0)*/						
};
int main() {
	/*
	主函数		：	奖金计算程序
	函数功能	：	根据输入的利润计算应发放的奖金，可重复多次输入计算，输入小于零的数时结束程序
	输入输出	：	输入任意12位以内的实数，但只保留两位小数；输出格式化字符串三种可选
	*/
	/*__________子函数表__________*/
	int num2str(double, char *);																	// 将输入的整型量转换为中文字符串
	int unitC(char, short, char *, CWORD *);											// 格式化字符串以得到相应的货币表达字符串
	void printSymb(char);																				// 格式化输出标题和UI以及提示文字
	double bonusCale(double);																	// 主计算程序
	/*__________————__________*/
	/*___________变量表___________*/
	int						intLen = 0, outLen, typeFlag = 0, neFlag = 1 ;
	double				input;
	CWORD				output[30] = { 0 };
	char					money[13] = { 0 };
	char					outTpye[]  = { 'z','s','l' };												// 输出类型：中文大写、逗号千分、万位简写
	/*___________———___________*/
#ifdef _MSC_VER																							// 避免更换编译环境可能会乱码的情况
	system("CHCP 936");																				// MS的VisualStudio默认用Unicode编码
#else
	system("CHCP 65001");																			//	其他常见的如GCC等编译器默认使用UTF-8
#endif 
START:
	system("CLS"); system("COLOR 8b");	printSymb('t');	printSymb('w');// 设置控制台初始状态并输出标题和提示文字
	printf("\n"); printSymb('3'); printf("\n(输出格式还支持逗号千分和万位简写，输入22进行切换)\n");
	printSymb('o');																							// 输出操作提示
	do{																													// 输入正数则循环执行
		if (scanf("%lf", &input)) {																		// 先判断输入的是否合法
			if (input > 100) {																					// 100以内预留给其他指令
				neFlag = 1;
				intLen = num2str(bonusCale(input) , money);						// 计算结果转字符串方便进行格式化为大写数字的操作
				if (intLen < 12) {																				// 并判断长度是否正常
PrintOut:
					if (intLen < 1) { input = 24260461.06; intLen = num2str(input, money); }// 允许用户未输入时切换默认值的输出格式
					outLen = unitC(outTpye[typeFlag], intLen, money, output);  //	格式化字符串并返回总长度
					printSymb('e');
					if (neFlag)printf("当输入利润为%0.4lf万元时，应发放的奖金总数为", input / WAN);// 正确输入才显示输入输出情况 
					printSymb('s');																			// 设置输出字符样式
					for (short temp = 0; temp < outLen; temp += 1) printf("%s", output[temp].cbuff);
					printf("\n"); printSymb('n');	printSymb('o');					// 结束本次循环，提示选择下一个操作
				}
				else { printSymb('y'); neFlag = 0; system("pause"); goto START; }	// 提示输入过长
			}else {
				if (input == 22) {																				// 其他指令的处理							
					if (typeFlag < 2) typeFlag = typeFlag + 1;else typeFlag = 0;
					switch (typeFlag){
					case 0:printSymb('3'); break;case 1:printSymb('4'); break;case 2:printSymb('6'); break;default:break;
					}
					neFlag = 0; goto PrintOut;
				}																											// 后续还可以在这里添加其他指令的处理							
				else if (input > 0) { printSymb('x'); neFlag = 0; system("pause"); goto START; }	// 提示输入数的值过小
			}
		}else { printSymb('z');  system("pause"); return -1; }					// 提示输入了错误的数据
	} while (input > 0);
	printSymb('b'); system("pause"); system("COLOR 2b"); return 0;// 用户结束程序，输出再见信息
}

void printSymb(char type) {
	/*
	子函数名	：	图形打印
	函数功能	：	输出UI等特殊样式的文本
	输入输出	：	要输出的类型；预设样式文本
	*/
	HANDLE hOp;
	hOp = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (type) {
	case't':	SOA(hOp, 0x8a); printf("\
	　\t　\t　\t┌——————————┐\n\
	　\t　\t　\t├　　奖金计算程序　　┤\n\
	　\t　\t　\t└——————————┘\n\
"); break;
	case 'b':SOA(hOp, 0x8b); printf("输入了非正数，程序将退出，欢迎再次使用！\n");  break;
	case 'o':SOA(hOp, 0x8e); printf("(24260461.06 )进行计算 or (-1)退出 or (22)切换格式)："); SOA(hOp, 0x8a); break;
	case 'n':SOA(hOp, 0x8f); printf("\n本次结束,请继续(");  break;
	case 'w':SOA(hOp, 0x8a); printf("├　欢迎使用本程序，本程序输入利润(例如24260461.06或616471607等实数)输出应发放奖金总数。┤\n");
		SOA(hOp, 0x89); printf("请输入数据或选择操作("); SOA(hOp, 0x1a);  break;
	case '3':SOA(hOp, 0x87); printf("(当前输出格式：中文大写)"); break;
	case '4':SOA(hOp, 0x87); printf("(当前输出格式：逗号千分)"); break;
	case '6':SOA(hOp, 0x87); printf("(当前输出格式：万位简写)"); break;
	case 'y':SOA(hOp, 0xfc);  printf("\n***错误：超过12位数的需另请高明，本程序只接受最大12位数。请检查并重试***\n"); SOA(hOp, 0x8a); break;
	case 'x':SOA(hOp, 0xfc);  printf("\n***错误：真有那么太寒酸？100总应该有吧？请检查并输入100以上的任意实数***\n"); SOA(hOp, 0x8a); break;
	case 'z':SOA(hOp, 0xfc);  printf("\n***错误：输入了无法处理的数据，请检查输入重启程序重试***\n"); break;
	case 's':SOA(hOp, 0x8b);	break;
	case 'e':SOA(hOp, 0x80);	break;
	default:break;
	}
}

int num2str(double in, char *out) {
	/*
	子函数名	：	数字转字符串
	函数功能	：	将任意大于零实数转换为到小数点后两位的纯数字字符串（数组）以便后续转换为大写中文数字
	输入输出	：	任意大于零的实数；字符数组；返回整数位数
	*/
	char tmp[30] = { 0 };																				// 中间数组设置得足够长，但在处理时判断长度
	int i = 0, j = 0, dotFlag = 0;
	sprintf(tmp, "%0.3lf",  in);
	while (tmp[i]) {																						// 跳过小数点复制整数部分和小数点后两位
		if (tmp[i] != '.') {
			if (j < 12 && (i - j) < 3)out[i - dotFlag] = tmp[i];						// 遇到小数点时i继续加，让过了小数点，输出需要减1
			if (!dotFlag) j++;																				// 遇到小数点前计数得到整数位
		}else  dotFlag = 1;
		i += 1;
	}
	return j;
}

int unitC(char type, short intLen, char *money, CWORD *out) {
	/*
	子函数名	：	货币格式化
	函数功能	：	将数字字符数组转换为符合货币表示习惯的字符串
	输入输出	：	格式化类型、源数组长度、源数组；格式化后的二维字符数组；返回总长度
	*/
	short point, CWlen, j;
	switch (type)
	{
	case 'z': {																									// 将数字数组转换为金额中文大写
		CWlen = j = 0;
		CWORD CHunits[] = { "分","角","圆","拾","佰","仟","万","拾","佰","仟","亿","拾","佰","仟","万","拾","佰","仟" },\
						 Excp[]		= { "拾","万","整" }, CHnum[]  = { "零","壹","贰","叁","肆","伍","陆","柒","捌","玖" };
		for (point = 0 ; point < intLen + 2 ; point += 1) {
			short num = (int)(money[point] - '0');
			if (num == 0) j += 1;
			else {																									// 记录连续的0的数量，零不能在最后一位，连续的零只输出最后一个
				if (j > 0 && point < intLen) { out[CWlen] = CHnum[0]; CWlen += 1; }
				 out[CWlen] = CHnum[num]; CWlen += 1; j = 0;				// 零不连续了就把0的计数清零，输出对应的中文
			}
			if (num != 0 || intLen - point == 5 || intLen - point == 9 || ((intLen - point + 3) % 8 == 0 && j < 4)) {
				out[CWlen] = CHunits[intLen - point + 1]; CWlen += 1;// 圆, 万, 亿三个单位必须存在，每到万位开始循环
			}
			if (point == intLen - 1) {																// intLen的位置是小数点，小数点前是10会被转换为拾，补个圆
				if (money[intLen - 1] == '0') { out[CWlen] = CHunits[2]; CWlen += 1; }
				if ( (money[intLen] == '0') && (money[intLen + 1] != '0') ) { out[CWlen] = CHnum[0]; CWlen += 1; }
			}																											// 小数点后是零但最后非0就补零
		}																												// 在最末尾时后两位都为0说明没有小数部分，输出整
		if (money[intLen + 1] == '0' && money[intLen] == '0') { out[CWlen] = Excp[2]; CWlen += 1; }
	}break;

	case 'l': {
		CWlen = j = 0; CWORD tmp[30] = { 0 }, \
		 num[] = { "0","1","2","3","4","5","6","7","8","9",".","万","￥" };
		out[CWlen] = num[12]; CWlen += 1;											// 人民币符号开头
		if (intLen>4){																						// 先判断是否能简写
			for (point = 0; point < intLen - 4; point += 1) {						// 直接复制万位（第六位）前面的
				short n = (int)(money[point] - '0'); out[CWlen] = num[n]; CWlen += 1;
			}
			out[CWlen] = num[10]; CWlen += 1;										// 万位前复制完后插入小数点
			for (point = intLen - 4; point < intLen - 2; point += 1) {		// 直接复制万位后的2位	
				short n = (int)(money[point] - '0'); out[CWlen] = num[n]; CWlen += 1;								
			}
			out[CWlen] = num[11]; CWlen += 1;										// 最后插入万字
		}
		else {																										// 不能简写就直接复制并忽略小数		
			for (point = 0; point < intLen ; point += 1) {short n = (int)(money[point] - '0');
			out[CWlen] = num[n]; CWlen += 1;										
			}
		}
	}break;

	default:
	case 's': {
		CWlen = j = 0; CWORD tmp[30] = { 0 },\
		 num[] = { "0","1","2","3","4","5","6","7","8","9",",","." };
		for (point = intLen; point > -1; point -= 1) {								//	 整数部分由低位到高位每三位插入一个逗号
			short n = (int)(money[point] - '0');
			tmp[CWlen] = num[n]; CWlen += 1; j += 1;
			if (((j-1) % 3 == 0) && (j > 2) && point ) { tmp[CWlen] = num[10]; CWlen += 1; }
		}
		for (point = CWlen; point > -1; point -= 1) out[CWlen - point] = tmp[point];	// 翻转序列
		out[CWlen] = num[11]; CWlen += 1;											// 整数部分处理完后插入小数点
		for (point = intLen; point < intLen + 2; point += 1) {
			short n = (int)(money[point] - '0');
			out[CWlen] = num[n]; CWlen += 1;											// 小数部分直接复制
		}
	}break;
	}
	return CWlen;
}

double bonusCale(double inpt) {
	/*
	子函数名	：	主计算
	函数功能	：	完成题目要求的阶段奖金计算
	输入输出	：	键盘输入的任意实数；返回奖金总数
	*/
	double op, result = 0;
	op = inpt / WAN;																					// 为了方便将阶段范围和提成率放入数组，先进行缩放																							
	int	i, rateT[6] = {      100,			75,			50,			30,		    15,			10 }, /*各阶段提成率(1000x)*/\
				level[6]	= { 0,			10,			20,			40,			60,			100		  };// 各阶段下限(万元)，使用数组方便以后维护(添加或删改)
	if (inpt > 1) {																								// 由于后一阶段包含前一阶段的，所以循环判断并累加							
		for (i = 5; i > -1; i -= 1) { if (op > level[i]) { result += (rateT[i] * (op - level[i]) / 1000); op = level[i]; } }
	}else return 1;
	return result * 10000;
}
