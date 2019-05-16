#include<iostream>
#include<string>
#include <windows.h>

using namespace std;

void main()
{
	/** Read Go-ICP output.txt */

	FILE *file = fopen("output.txt", "r");

	double t, parameter[12];

	if (file == NULL){
	printf("Files DOES NOT EXISTS!");
	}

	fscanf(file, "%lf", &t);
	fscanf(file, "%lf %lf %lf", &parameter[0], &parameter[1], &parameter[2]);
	fscanf(file, "%lf %lf %lf", &parameter[3], &parameter[4], &parameter[5]);
	fscanf(file, "%lf %lf %lf", &parameter[6], &parameter[7], &parameter[8]);
	fscanf(file, "%lf", &parameter[9]);
	fscanf(file, "%lf", &parameter[10]);
	fscanf(file, "%lf", &parameter[11]);

	printf("%.4f", t);

	fclose(file);

	/** Go-ICP execute */
	string str1 = "model.txt data.txt ";
	int nSample = 500;
	string str2 = " config.txt output.txt";

	string str = str1 + to_string(nSample) + str2;


	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "GoICP.exe";
	ShExecInfo.lpParameters = str.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_SHOW;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteExA(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
	CloseHandle(ShExecInfo.hProcess);

	//ShellExecuteA(NULL, "open", "GoICP.exe", "model.txt data.txt 500 config.txt output.txt", NULL, SW_SHOWDEFAULT);
}