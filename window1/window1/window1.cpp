#include <windows.h>
#include <tchar.h>
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	MessageBox(NULL, _T("Привет всем!"),
		_T("Программа"), MB_OK);
	return 0;
}