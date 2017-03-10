// console_template.cpp : Defines the entry point for the console application.
//

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#include <iostream>
#include <physfs.h>

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
    _tsetlocale(LC_ALL, _T(""));
    std::wcout.imbue(std::locale(""));
    //_tprintf_s(_T("%s\n"), _T("hello world. 中文测试"));
    //std::wcout << L"中文测试" << std::endl;

    PHYSFS_init(NULL);

	PHYSFS_addToSearchPath("myfile.7z", 1);

	PHYSFS_setWriteDir("./");


	if (PHYSFS_exists("myfile.txt")) {
		// open a file for reading
		PHYSFS_file* myfile = PHYSFS_openRead("myfile.txt");
		PHYSFS_sint64 file_size = PHYSFS_fileLength(myfile);
		char* myBuf = new char[file_size];
		int length_readed = PHYSFS_read(myfile, myBuf, 1, file_size);
		printf(myBuf);


		// open a file for writing
		PHYSFS_file* myfile2 = PHYSFS_openWrite("myfile2.txt");
		int length_writed = PHYSFS_write(myfile2, myBuf, 1, file_size);
		PHYSFS_close(myfile2);

		delete[] myBuf;
		
		PHYSFS_close(myfile);
		
		
	}


	PHYSFS_deinit();

	
    getchar();
    return 0;
}

