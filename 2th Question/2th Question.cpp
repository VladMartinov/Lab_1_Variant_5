#include <iostream>             //Для вывода информации на консоль
#include <iomanip>              //Для редактирование выводимого поля

using namespace std;

//Метод принимающий одномерный массив и его длинну
void initializeArray1D(double* Array1D, unsigned int LENGTH)      
{
    for (int i = 0; i < LENGTH; ++i)
    {
        if (i % 2 != 0)
            *(Array1D + i) = ((i * i) + 1)*-1;                   //Заполнение каждого элемента одномерного массива с помощью цикла (Значение записываемое в массив взято из варинта задния)
        else
            *(Array1D + i) = (i * i) + 1;
    }
}

//Метод принимающий одномерный массив, кол-во строк и столбцов (для инициализации двухмерного массива)
double** makeArray2D(double* Array1D, unsigned Length, unsigned int ROWS, unsigned int COLS)         
{
    int temp;
    for (int i = 0; i < Length-1; i++) {
        for (int j = 0; j < Length - i-1; j++) {
            if (Array1D[j] < Array1D[j + 1]) {
                // меняем элементы местами
                temp = Array1D[j];
                Array1D[j] = Array1D[j + 1];                    // Используем пузырьковый метод (ранее использовал в С#) для сортировки массива 
                Array1D[j + 1] = temp;
            }
        }
    }

    double** Array2D = new double* [ROWS];          // Выделение памяти для двух мерногомассива 
    for (unsigned int i = 0; i < ROWS; ++i)
    {
        *(Array2D + i) = new double[COLS];          // Выделение памяти для каждой строки двухмерного массива
    }

    for (unsigned int i = 0; i < ROWS; ++i)         // Пробегаемся по строками массива 2Д
    {

        for (unsigned int j = 0; j < COLS; ++j)     // Пробегаемя по столбцам массива 2Д
        {
            *(*(Array2D + i) + j) = *(Array1D + i * COLS + j);          //заполням элементы массива 2Д  
        }
    }
    return Array2D;                                 //Возврат двухмерного массива
}

//Метод принимающий одномерный массив и его длинну для вывода его на консоль
void printArray1D(double Array1D[], unsigned LENGTH) {                  
    cout<<"[ ";
    for (unsigned int i = 0; i < LENGTH; ++i)                           
    {
        cout << *(Array1D + i) << "  ";                                 //Вывод каждого элемента массива
    }
    cout<<"]\n";                                                        //Переход на следующую строку
}

//Метод принимающий двухмерный массив, его кол-во строк и длинну
void printArray2D(double** Array2D, int ROWS, int COLS) {               
    cout << "\n" << "=>\n";                                             //Разделение одномерого и двухмерного массива в консоли

    for (unsigned int i = 0; i < ROWS; ++i)                             //Пробегаемя по строкам
    {
        cout << "\n";                                                   //Переход на следующую строку
        for (unsigned int j = 0; j < COLS; ++j)
        {
            if (i == 0 && j == 0)
                cout<< "[" << setfill(' ') << setw(4) << *(*(Array2D + i) + j); //Вывод первого эоемента первой строки (из-за квадратной скобки)
            else
                cout << setfill(' ') << setw(5) << *(*(Array2D + i) + j);      //Вывод всех эл-ов массива
        }
    }
    cout << "  ]\n";                                                    //Завершающая скобка
}

//Метод принимает одномерный массив для его удаления из памяти
void freeArray1D(double* Array1D) {             
    delete Array1D;                             //Удаление из памяти массива
    Array1D = NULL;                             //Присвоение нулевой ссылки (то есть ничего)
}

//Метод принимающий двухмерный массив для его удаления из памяти
void freeArray2D(double** Array2D, int ROWS) {              
    for (int i = 0; i < ROWS; ++i)
    {
        delete[] *(Array2D + i);                            //Удаление каждой строки двухмерного массива
    } 
    delete[] Array2D;                                       //Удаление массива 
}

int main()
{
    const unsigned int Length = 18;         //Инициализация длинны одномерного массива
    const unsigned int ROWS = 9;            //Инициализация кол-ва строк
    const unsigned int COLS = 2;            //Инициализация кол-ва столбцов

    double* Array1D = new double[Length];   //Выделение памяти под одномерный массив
    initializeArray1D(Array1D, Length);     //Вызов метода для его заполнения

    printArray1D(Array1D, Length);          //Вывод одномерного массива на консоль

    double** Array2D = makeArray2D(Array1D, Length, ROWS, COLS);    //Вызов метода возвращающего двухмерный массив

    printArray2D(Array2D, ROWS, COLS);      //Вывод двухмерного массива на консоль

    freeArray1D(Array1D);                   //Удаление из памяти одномерного массива
    freeArray2D(Array2D, ROWS);             //Удаление из памяти двухмерного массива
    return 0;                               //Конец
}
