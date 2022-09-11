#include <iostream>

char* MyStrCopy(const char* src)		//����� ����������� ������ ��������, � ������� ������� (������ ������������ � �����)
{
	char* dest = new char[strlen(src)];			//��������� ������ ��� ������ ������� ������� src
	for (int i = 0; i < strlen(dest); ++i)
		dest[i] = src[i];						//��������� ����������� � ������ dest.
	return dest;				//������� ����������� ������
}

int main() {
	const char* src = "Hi! Join our group - 'www.some_link.com'";		//������ �������� � ������� ����� ������
	char* dest = new char[strlen(src)];								//���������� ����������� ������ desc (stlen(src)+1 ������� ��-�� ����������� strcpy)
	
	strcpy_s(dest, strlen(src)+1, src);					//����������� ����� ���������� � ���������� �++. ������ ��� ����������
	
	char* MyMethod = MyStrCopy(src);		//��� ����� ��������� ���� . ������ ������ ����������. dest �������� ������ ������, ����� ������������� ��� �� ���� ��������������(�������� dest ��� ��������)

	printf("Initial string: %s\nStandard: %s\nMy version: %s\n",	//����� ����������� �� ������� %s - ������ ��������
		src, dest, MyMethod);
	return 0;														//����� ���������
}