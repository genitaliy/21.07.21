//#include <iostream>
//#include <windows.h>
//#include <io.h>
//#include <stdio.h>
//using namespace std;
//
//wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
//{
//	wchar_t* wString = new wchar_t[4096];
//	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
//	return wString;
//}
//
////Функция, выводящая на экран строку
//void RussianMessage(const char* str) {
//	char message[100];
//	//перевод строки из кодировки Windows
//	//в кодировку MS DOS
//	CharToOem(convertCharArrayToLPCWSTR(str), message);
//	cout << message;
//}
////Функция копирования файла
//bool CopyFile(char* source, char* destination) {
//	const int size = 65536;
//	FILE* src, * dest;
//	//Открытие Файла
//	if (!(src = fopen(source, "rb"))) {
//		return false;
//	}
//	//Получение дескриптора файла
//	int handle = _fileno(src);
//	//выделение памяти под буффер
//	char* data = new char[size];
//	if (!data) {
//		return false;
//	}
//	//Открытие файла, куда будет производиться копирование
//	if (!(dest = fopen(destination, "wb"))) {
//		delete[]data;
//		return false;
//	}
//	int realsize;
//	while (!feof(src)) {
//		//Чтение данных из файла
//		realsize = fread(data, sizeof(char), size, src);
//
//		//Запись данных в файл
//		fwrite(data, sizeof(char), realsize, dest);
//	}
//	//Закрытие файлов
//	fclose(src);
//	fclose(dest);
//	return true;
//}
//void main() {
//	//MAX_PATH - Константа, определяющая
//	//максимальный размер пути.
//	//Даная константа содержится в stdlib.h
//	char source[_MAX_PATH];
//	char destination[_MAX_PATH];
//	char answer[20];
//	RussianMessage("\nВведите путь и название копируемого файлу : \n");
//		//Получение пути к первому файлу
//		cin.getline(source, _MAX_PATH);
//	//Проверка Существует ли файл
//	if (_access(source, 00) == -1) {
//		RussianMessage("\nУказан неверный путь или название файла\n");
//			return;
//	}
//	RussianMessage("\nВведите путь и название нового файла:\n");
//		//Получение пути к второму файлу
//		cin.getline(destination, _MAX_PATH);
//	//Проверка на существование файла
//	if (_access(destination, 00) == 0) {
//		RussianMessage("\nТакой Файл уже существует перезаписать его(1 - Да / 2 - Нет) ? \n");
//
//			cin.getline(answer, 20);
//		if (!strcmp(answer, "2")) {
//			RussianMessage("\nОперация отменена\n");
//			return;
//		}
//		else if (strcmp(answer, "1")) {
//			RussianMessage("\nНеправильный ввод\n");
//			return;
//		}
//		if (_access(destination, 02) == -1) {
//			RussianMessage("\nНет доступа к записи.\n");
//			return;
//		}
//	}
//	//Копирование файла
//	if (!CopyFile(source, destination)) {
//		RussianMessage("\nОшибка при работе с файлом\n");
//	}
//}