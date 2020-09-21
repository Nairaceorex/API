#include <windows.h>
#include <tchar.h>
#include <string>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
int APIENTRY _tWinMain(HINSTANCE hInstance, // Дескрипотор текущего приложения
	HINSTANCE Prev, // В современных системах всегда 0
	LPTSTR cmd, // Командная строка
	int mode) // Режим отображения окна
{
	HWND hMainWnd; // Дескриптор главного окна программы
	TCHAR szClassName[] = _T("MyClass");
	MSG msg; // Структура для хранения сообщения
	WNDCLASS wc; // Класс окна
	wc.hInstance = hInstance; // Определение класса окна
	wc.lpszClassName = szClassName; // Имя класса окна
	wc.lpfnWndProc = WndProc; // Функция окна
	wc.style = CS_HREDRAW | CS_VREDRAW; // Стиль окна
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Стандартная икона
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Стандартный курсор
	wc.lpszMenuName = NULL; // Нет меню
	wc.cbClsExtra = 0; // Нет дополнительных данных класса
	wc.cbWndExtra = 0; // Нет дополнительных данных окна
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, _T("Cannot register class"), _T("Error"), MB_OK);
		return 0;
	}// Регистрация класса окна
	// Создание окна
	hMainWnd = CreateWindowEx(WS_EX_TOPMOST,
		szClassName, // Имя класса окна
		_T("A Hello1 Application"), // Заголовок окна
		WS_OVERLAPPEDWINDOW, // Стиль окна
		CW_USEDEFAULT, // х
		CW_USEDEFAULT, // у
		CW_USEDEFAULT, // Width
		CW_USEDEFAULT, // Height
		NULL, // Дескрипт приложения
		NULL, // Нет меню
		hInstance, // Дескриптор приложения
		NULL); // Дополнительной информации нет
	if (!hMainWnd)
	{
		MessageBox(NULL, _T("Cannot create main window"), _T("Error"), MB_OK);
		return 0;
	}
	ShowWindow(hMainWnd, mode); // Показать окно
	// Цикл обработки сообщений
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); // Функция трансляции кодов нажатой клавиши
		DispatchMessage(&msg); // Посылает сообщения функции WndProc
	}
	return msg.wParam;
}
// Оконная функция вызывается ОС
// и получает сообщение из очереди для данного приложения
LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam) {
	//Обработчик сообщений
	PAINTSTRUCT ps;
	HDC hdc;

	DWORD dwFileAttr = GetFileAttributes(_T("D:\\test.txt"));
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
	}
}