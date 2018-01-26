#include <iostream>
#include <stdio.h>
using namespace std;
class Processor
{
public:
unsigned char a;
unsigned char b;
unsigned char c;
unsigned char d;
Processor()
{
a = 0;
b = 0;
c = 0;
d = 0;
};
//непосредственная адресация
void mov(unsigned char *reg, unsigned char num)
{
*reg = num;
};
//регистровая адресация
void mov(unsigned char *op1, unsigned char *op2)
{
*op1 = *op2;
};
// сложение
void add(unsigned char *op1, unsigned char *op2)
{
*op1 = *op1 + *op2;
};
void add(unsigned char *op1, unsigned char num)
{
*op1 = *op1 + num;
};
// сдвиг влево, передаваемое число - количество разрядов сдвига
void ls (unsigned char *op1, unsigned char num)
{
*op1 = *op1 << num;
};
// сдвиг вправо, передаваемое число - количество разрядов сдвига
void rs (unsigned char *op1, unsigned char num)
{
*op1 = *op1 >> num;
};
// операция инверсии
void neg(unsigned char *op1)
{
*op1 = ~*op1;
};
};

int main()
{
Processor proc;
unsigned char *rega = &proc.a;
unsigned char *regb = &proc.b;
proc.mov(rega, 4);
proc.mov(regb, 9);
proc.add(regb,rega);
proc.ls(rega,3);
printf("%d \n", *rega);
printf("%d \n", *regb);
return 0;
}
