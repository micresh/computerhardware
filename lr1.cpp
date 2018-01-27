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
//-----------------------начало исходного варианта
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
// ---------------------конец исходного варианта
// --------------------- команда вычитания регистр-регистр
void sub (unsigned char *op1, unsigned char *op2)
{
	unsigned char buf = *op2; // ---- сохраняем в буфер значение инвертируемого регистра
	neg(op2); // -- выполняем операцию инверсии для получение обратного кода
	add(op2,1); // -- получаем обратный код
	add(op1,op2); // -- выполняя сложение фактически выполняем вычитание
	mov(op2,buf); // - восстанавливаем из буфера значение операнда 2
};
// --------------------- команда вычитания регистр-число
void  sub(unsigned char *op1, unsigned char num) {
	unsigned char *buf = &num;
	neg(buf);
	add(buf,1);
	add(op1,buf);

}
};

int main()
{
Processor proc;
unsigned char *rega = &proc.a;
unsigned char *regb = &proc.b;
proc.mov(rega, 4);
proc.mov(regb, 9);
proc.sub(regb, rega);
proc.sub(rega,2);
printf("%d \n", *rega);
printf("%d \n", *regb);
return 0;
}
