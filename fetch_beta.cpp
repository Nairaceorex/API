#include <Windows.h>
#include <iostream>
#include <tchar.h>

/*
#define FILE_ATTRIBUTE_READONLY             0x00000001
#define FILE_ATTRIBUTE_HIDDEN               0x00000002
#define FILE_ATTRIBUTE_SYSTEM               0x00000004
#define FILE_ATTRIBUTE_DIRECTORY            0x00000010
#define FILE_ATTRIBUTE_ARCHIVE              0x00000020
#define FILE_ATTRIBUTE_ENCRYPTED            0x00000040
#define FILE_ATTRIBUTE_NORMAL               0x00000080
#define FILE_ATTRIBUTE_TEMPORARY            0x00000100
#define FILE_ATTRIBUTE_SPARSE_FILE          0x00000200
#define FILE_ATTRIBUTE_REPARSE_POINT        0x00000400
#define FILE_ATTRIBUTE_COMPRESSED           0x00000800
#define FILE_ATTRIBUTE_OFFLINE              0x00001000
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  0x00002000
*/

using namespace std;

int main() {
	DWORD dwFileAttr = GetFileAttributes(_T("N:\\test.txt"));
	
	if (dwFileAttr & FILE_ATTRIBUTE_READONLY) cout << "READONLY"<<endl;
	if (dwFileAttr & FILE_ATTRIBUTE_HIDDEN) cout << "HIDDEN" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_SYSTEM) cout << "SYSTEM" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_DIRECTORY) cout << "DIRECTORY" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_ARCHIVE) cout << "ARCHIVE" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_ENCRYPTED) cout << "ENCRYPTED" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_NORMAL) cout << "NORMAL" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_TEMPORARY) cout << "TEMPORARY" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_SPARSE_FILE) cout << "SPARSE_FILE" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_REPARSE_POINT) cout << "REPARSE_POINT" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_COMPRESSED) cout << "COMPRESSED" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_OFFLINE) cout << "OFFLINE" << endl;
	if (dwFileAttr & FILE_ATTRIBUTE_NOT_CONTENT_INDEXED) cout << "NOT_CONTENT_INDEXED" << endl;
	
	system("PAUSE");
}
