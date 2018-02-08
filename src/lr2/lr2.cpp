#include <iostream>
#include <stdio.h>
using namespace std;
class Processor
{
public:
unsigned char a; //---- регистр аккумулятор
unsigned char b; //---- регистр базового адреса
unsigned char c; //---- регистр счетчик
unsigned char d; //---- регистр хранения данных
unsigned long int opcount; //---- счетчик выполненных команд
Processor()
//-----------------------начало исходного варианта
{
a = 0;
b = 0;
c = 0;
d = 0;
opcount = 0;
};
//непосредственная адресация
void mov(unsigned char *reg, unsigned char num)
{
*reg = num;
opcount++;
};
//регистровая адресация
void mov(unsigned char *op1, unsigned char *op2)
{
*op1 = *op2;
opcount++;
};
// сложение
void add(unsigned char *op1, unsigned char *op2)
{
*op1 = *op1 + *op2;
opcount++;
};
void add(unsigned char *op1, unsigned char num)
{
*op1 = *op1 + num;
opcount++;
};
// сдвиг влево, передаваемое число - количество разрядов сдвига
void ls (unsigned char *op1, unsigned char num)
{
*op1 = *op1 << num;
opcount++;
};
// сдвиг вправо, передаваемое число - количество разрядов сдвига
void rs (unsigned char *op1, unsigned char num)
{
*op1 = *op1 >> num;
opcount++;
};
// операция инверсии
void neg(unsigned char *op1)
{
*op1 = ~*op1;
opcount++;
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
	unsigned char *buf = &num; //------ сохраняем в область видимости функции указатель на число
	neg(buf); //---- инвертируем буфер
	add(buf,1); //---- формируем дополнительный код
	add(op1,buf); //----- выполняем вычитание

};
//-----операция умножения регистра на регистр
void mul(unsigned char *op1, unsigned char *op2) {
	//----- в данной реализации будет выполнен простейший вариант умножения, состоящий из последовательного складывания чисел
	
    unsigned char buf = *op1; //---- сохраняем в буфер умножаемое 
    for (int i=1; i<*op2; i++) //---- инициализируем цикл 
    {
        add(op1, buf); //----- непосредственно выполнение операции сложения
    };
    
    //---- данная реализация более сложна с точки зрения реализации, однако более эффективна с точки зрения времени выполнения

}

};

int main()
{
Processor proc;
unsigned char *rega = &proc.a;
unsigned char *regb = &proc.b;
proc.mov(rega, 4);
proc.mov(regb, 12);
proc.mul(rega,regb);
printf("%d \n", *rega);
printf("%d \n", *regb);
printf("%d \n", proc.opcount);
return 0;
}