#include <windows.h>
#include<iostream>
#include <stdio.h>



int main(void)

{


	
	LPCTSTR cFileName = L"randomLargeFile.txt";

	int cSize = WideCharToMultiByte(CP_ACP, 0, cFileName, wcslen(cFileName), NULL, 0, NULL, NULL);
	std::string StringFilename(static_cast<size_t>(cSize), '\0');
	WideCharToMultiByte(CP_ACP, 0, cFileName, wcslen(cFileName),
		reinterpret_cast<char*>(&StringFilename[0]), cSize, NULL, NULL);

	LARGE_INTEGER filesize;

	HANDLE FH = CreateFile(cFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);


	
	std::cout << "Filename: " << StringFilename << "\nFile Size: " << GetFileSizeEx(FH, &filesize) << std::endl;
	return 0;







	//// the files' handles
	//HANDLE hFile;// hFile1;
	//// filenames, the file is not there...
	//LPCWSTR fname = L"Filey-File.txt";
	//// the file is there...
	//LPCWSTR fname1 = L"randomLargeFile.txt";
	//// temporary storage for file sizes
	//DWORD dwFileSize;
	//DWORD dwFileType;
	//// Create the test file. Open it "Create Always" to overwrite any existing file...
	//hFile = CreateFile(fname, GENERIC_READ | GENERIC_WRITE, 0, NULL,
	//		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);



	//if (hFile == INVALID_HANDLE_VALUE)

	//{
	//	printf("hFile is NULL\n");
	//	printf("Could not create %S\n", fname);
	//	// return error
	//	return 4;
	//}
	//else
	//	printf("%S file was created successfully!\n", fname);

	//// Get the file type...

	//dwFileType = GetFileType(hFile);
	//// Verify that the correct file size was written.
	//dwFileSize = GetFileSize(hFile1, NULL);
	//printf("%S size is %d bytes and file type is %d\n", fname, dwFileSize, dwFileType);
	//CloseHandle(hFile); // close the file handle and the file itself

	//// Opening the existing file

	////hFile1 = CreateFile(fname1, // file to open
	////	GENERIC_READ, // open for reading
	////	FILE_SHARE_READ, // share for reading
	////	NULL, // default security
	////	OPEN_EXISTING, // existing file only
	////	FILE_ATTRIBUTE_NORMAL,// normal file
	////	NULL); // no attribute template

	////if (hFile1 == INVALID_HANDLE_VALUE)
	////{
	////	printf("Could not open %S file, error %d\n", fname1, GetLastError());
	////	return 1;
	////}

	////dwFileType = GetFileType(hFile1);
	////dwFileSize = GetFileSize(hFile1, NULL);

	////printf("%S size is %d bytes and file type is %d\n", fname1, dwFileSize, dwFileType);

	////// close the file's handle and itself
	////CloseHandle(hFile1);

}