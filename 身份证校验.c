/*
二代身份证号码共 18 位 ，其中最后一位是校验码 。 
校验码计算方法描述如下 ：
假设某身份证的前 17 位数字为 l2345678912345678

第 1 步：计算前 17 位各位数字与对应加权因子乘积的和S
前17位数字：1	2	3	4	5	6	7	8	9	1	2	3	4	5	6	7	8
  加权因子：7	9	10	5	8	4	2	1	6	3	7	9	10	5	8	4	2
  S = 1*7 + 2*9 + 3*10 + 4*5 + 5*8 + 6*4 + 7*2 + 8*1 + 9*6 + 1*3 + 2*7 + 3*9 + 4*10 + 5*5 + 6*8 + 7*4 + 8*2 = 416
第 2 步：计算 S 除 11 的余数 T :  T	= 416 %	11	=	9
第 3 步：将余数 T 转换为 l 位校验码。以下是转换表：
余数 T：0	1	2	3	4	5	6	7	8	9	10
校验码：1	0	X	9	8	7	6	5	4	3	2
2 对应 X，所以我们会发现有些人的身份证号码的最后一位是 X。
9 对应 3，所以例中身份证的校验码为3，18位身份证号码就应该是 123456789123456783。
写一个程序 ，输入一个 18 位身份证号码 （注意最后一位可能是大写字母X）， 检查这个号码是否合法 。
若长度不对、前17位不是数字或校验码不正确就认为是不合法的号码（本题不考虑其它的非法情况  ，如身份证中出生日期非法等）
最后输出一行信息指出输入的身份证号码是否合法
*/
#include<stdio.h>
int IsLegal(char info[]);
int main(void)
{
	char info[50];
	scanf("%s",info);
	if(IsLegal(info))
		puts("合法！");
	else
		puts("非法！");
	return 0;
}
int IsLegal(char info[])
{
	int power[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int i,sum = 0;
	char check[] = "10X98765432";
	//先检验长度
	if(info[18] != '\0')
		return 0;
	//检验最后一位是否合法
	if(info[17] != 'x' && info[17] != 'X' && (info[17] > '9' || info[17] < '0'))//最后一位不是x且不是数字
		return 0;
	for(i = 0;i < 17;++i)
		if(info[i] < '0' || info[i] > '9')//如果不是数字
			return 0;
	for(i = 0;i < 17;++i)
		sum += (info[i] - '0') * power[i];
	if(check[sum%11] == info[17])
		return 1;
	return 0;
}
