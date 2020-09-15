#include <windows.h>
#include <tchar.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("MainFrame");
int APIENTRY _tWinMain(HINSTANCE This, // WeckpuntTop TeKyulero NpusIoKXeHUAa
	HINSTANCE Prev, // B COBpeMeHHEIX CUcTeMax BCerga 0
	LPTSTR cmd, // KoMaHgHaa crpoKa
	int mode) // PexyvM oTO6paxeHua OKHAa
{
	HWND hWnd; // Weckpuntop miaBHOTO OKHa MporpaMmmel
	MSG msg; // CTpykTypa JIA xpaHeHuaA COOobleHNA

	WNDCLASS wc; // Kmnacc oKHa
	// OmpeneneHue Kiacca oKHa

	wc.hInstance = This;

	wc.lpszClassName = WinName; // Vima Klacca OKHa
	wc.lpfnWndProc = WndProc; // SYHKUNA OKHa
	wc.style = CS_HREDRAW | CS_VREDRAW; // CTUIIb OKHa

	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // CTaHDaptHad UKOHKa
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // CTaHaptTHpm Kypcop
	wc.lpszMenuName = NULL; // Het meHto

	wc.cbClsExtra = 0; // Hert DONONHVTeEIbHBIX DAHHbIX KyIaCCca
	wc.cbWndExtra = 0; // Het DONONHMTeIbHBIX TaHHbIX OKHAa

	// 3anosHeHVe OKHa 6esIbIM LIBeETOM

	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	if (!RegisterClass(&wc)) return 0; // PeructpaluMa Kiacca OKHa
	// CosqaHue oKHa

	hWnd = CreateWindow (WinName, _T("KapKac Windows-npunoxeHua"), 

		WS_OVERLAPPEDWINDOW, // CTVJIb OKHA
		CW_USEDEFAULT, // x
		CW_USEDEFAULT, // y —- PasmepbI OKHa
		CW_USEDEFAULT, // Width
		CW_USEDEFAULT, // Height
		HWND_DESKTOP, // Jleckpuntop ponutTenbcKorTo oKHa

		NULL, // Het meuro
		This, // Teckpuntop npunoxennua
		NULL); // JononHYTeNnbHOU unbopmauyu HeT

	ShowWindow(hWnd, mode); //Hoxa3atTb OKHO
	// UKs o6pa6otKu coobuexun
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);// ®yHKUMA TpaHCNAWMM KONOB HaxaTON KnaBMUN
		DispatchMessage(&msg); // Tocbmaer coobmenue oyHKuMM WndProc ()

	}

	return 0;
}
// OKOHHaA OYHKUMA BEISIBAeCTCA OMepalMOHHOM cucTeMoi
// w“ nosmyuaeT coobileHua “3 OUepenU TIA DaHHOro mpunoxeHua
LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{ // O6pa6oTuuk coobueHun
	switch (message)
	{
	case WM_DESTROY: PostQuitMessage(0);
		break; // 3aBepuieHvue nporpammsl
		// O6pa6orKa coobmeHuA nO ymMonuaHMo
	default: return DefWindowProc(hWnd, message, wParam, lParam);

	}

	return 0;
}