#include <iostream>

char* MyStrCopy(const char* src)		//Метод принимающий строку симводов, и искомый элемент (символ преобразован в число)
{
	char* dest = new char[strlen(src)];			//Выделение памяти для нового массива длинной src
	for (int i = 0; i < strlen(dest); ++i)
		dest[i] = src[i];						//Почаровое копирование в массив dest.
	return dest;				//Возврат результатов поиска
}

int main() {
	const char* src = "Hi! Join our group - 'www.some_link.com'";		//Строка символов в которой будем искать
	char* dest = new char[strlen(src)];								//Объявление заполняемой строки desc (stlen(src)+1 сделано из-за особенности strcpy)
	
	strcpy_s(dest, strlen(src)+1, src);					//Стандартный метод встроенный в библиотеку С++. Запись его результата
	
	char* MyMethod = MyStrCopy(src);		//Наш метод описанный выше . Запись нашего результата. dest объявляю внутри метода, чтобы удостоверится что он тоже работоспособен(основной dest уже заполнен)

	printf("Initial string: %s\nStandard: %s\nMy version: %s\n",	//Вывод результатов на консоль %s - строка символов
		src, dest, MyMethod);
	return 0;														//Конец программы
}