#include<Windows.h>
#include<tchar.h>
#include <string>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
int APIENTRY _tWinMain(HINSTANCE This, //Дескриптор текущего приложения
    HINSTANCE Prev, //В современных системах всегда 0
    LPTSTR cmd, //Командная строка
    int mode) //Режим отображения окна

{
    HWND hWnd; //Дескриптор главного окна программы
    MSG msg; //Структура для хранения сообщения
    WNDCLASS wc;//Класс окна
    //Определение класса окна
    wc.hInstance = This;
    wc.lpszClassName = WinName; //Имя класса окна
    wc.lpfnWndProc = WndProc; //Имя класса окна
    wc.style = CS_HREDRAW | CS_VREDRAW; //Стиль окна
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //Стандартная иконка
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); //Стандартный курсор
    wc.lpszMenuName = NULL; //Нет меню
    wc.cbClsExtra = 0; //Нет дополнительных данных класса
    wc.cbWndExtra = 0; //Нет дополнительных данных окна
    //Заполнение окна белым цветом
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    if (!RegisterClass(&wc)) return 0;//Регистрация класса окна
    //Создание окна
    hWnd = CreateWindow(WinName,//Имя класса окна
        _T("Каркас Windows-приложения"),//Заголовок окна
        WS_OVERLAPPEDWINDOW, //Стиль окна
        CW_USEDEFAULT,//x
        CW_USEDEFAULT,//y Размеры окна
        CW_USEDEFAULT,//Width
        CW_USEDEFAULT,//Height
        HWND_DESKTOP,//Дескриптор родительской информации нет
        NULL,//Нет меню
        This,//Дескриптор приложения
        NULL);//Дополнительной информации нет
    ShowWindow(hWnd, mode);//Показать окно
    //Цикл обработки сообщений
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);//Функция трансляции кодов нажатой клавиши
        DispatchMessage(&msg);//Посылает сообщение функции WndProc()
    }
    return 0;

}
//Оконная функция вызывается операционной системой
//и получает сообщения из очереди для данного приложения
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //Обработчик сообщений
    PAINTSTRUCT ps;
    HDC hdc;

    DWORD dwFileAttr = GetFileAttributes(_T("N:\\test.txt"));
    std::string str;
    std::wstring stemp;
    LPCWSTR sw;
    switch (message)
    {
    case WM_PAINT:


        if (dwFileAttr & FILE_ATTRIBUTE_READONLY) str += "READONLY ";
        if (dwFileAttr & FILE_ATTRIBUTE_HIDDEN) str += "HIDDEN ";
        if (dwFileAttr & FILE_ATTRIBUTE_SYSTEM) str += "SYSTEM ";
        if (dwFileAttr & FILE_ATTRIBUTE_DIRECTORY) str += "DIRECTORY ";
        if (dwFileAttr & FILE_ATTRIBUTE_ARCHIVE) str += "ARCHIVE ";
        if (dwFileAttr & FILE_ATTRIBUTE_ENCRYPTED) str += "ENCRYPTED ";
        if (dwFileAttr & FILE_ATTRIBUTE_NORMAL) str += "NORMAL ";
        if (dwFileAttr & FILE_ATTRIBUTE_TEMPORARY) str += "TEMPORARY ";
        if (dwFileAttr & FILE_ATTRIBUTE_SPARSE_FILE) str += "SPARSE_FILE ";
        if (dwFileAttr & FILE_ATTRIBUTE_REPARSE_POINT) str += "REPARSE_POINT ";
        if (dwFileAttr & FILE_ATTRIBUTE_COMPRESSED) str += "COMPRESSED ";
        if (dwFileAttr & FILE_ATTRIBUTE_OFFLINE) str += "OFFLINE ";
        if (dwFileAttr & FILE_ATTRIBUTE_NOT_CONTENT_INDEXED) str += "NOT_CONTENT_INDEXED ";

        stemp = std::wstring(str.begin(), str.end());
        sw = stemp.c_str();

        hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc,
            5, 5,
            sw, _tcslen(sw));

        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:PostQuitMessage(0);
        break;//Завершение программы
        //Обработка сообщений по умолчанию
    default: return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
/*
#include <Windows.h>
#include <iostream>
#include <tchar.h>

using namespace std;

int main() {
    DWORD dwFileAttr = GetFileAttributes(_T("D:\\test.txt"));
    if (dwFileAttr & FILE_ATTRIBUTE_READONLY) str+= "READONLY ";
    if (dwFileAttr & FILE_ATTRIBUTE_HIDDEN) str+= "HIDDEN ";
    if (dwFileAttr & FILE_ATTRIBUTE_SYSTEM) str+= "SYSTEM ";
    if (dwFileAttr & FILE_ATTRIBUTE_DIRECTORY) str+= "DIRECTORY ";
    if (dwFileAttr & FILE_ATTRIBUTE_ARCHIVE) str+= "ARCHIVE ";
    if (dwFileAttr & FILE_ATTRIBUTE_ENCRYPTED) str+= "ENCRYPTED ";
    if (dwFileAttr & FILE_ATTRIBUTE_NORMAL) str+= "NORMAL ";
    if (dwFileAttr & FILE_ATTRIBUTE_TEMPORARY) str+= "TEMPORARY ";
    if (dwFileAttr & FILE_ATTRIBUTE_SPARSE_FILE) str+= "SPARSE_FILE ";
    if (dwFileAttr & FILE_ATTRIBUTE_REPARSE_POINT) str+= "REPARSE_POINT ";
    if (dwFileAttr & FILE_ATTRIBUTE_COMPRESSED) str+= "COMPRESSED ";
    if (dwFileAttr & FILE_ATTRIBUTE_OFFLINE) str+= "OFFLINE ";
    if (dwFileAttr & FILE_ATTRIBUTE_NOT_CONTENT_INDEXED) str+= "NOT_CONTENT_INDEXED ";
    return 0;
}
*/