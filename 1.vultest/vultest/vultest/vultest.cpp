// vulTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

// mywps.cpp : 定义控制台应用程序的入口点。
//

#include <windows.h>
 HANDLE h;




 
int main(int argc, char *argv[])

{

//char ch;



//char fname[50]; //用于存放文件名

if(argc!=2)
{
	printf("argc should be 2!!!");
	exit(0);
}
else
{

	//fp=fopen(argv[1],"r"); //只供读取
	//__asm int 3
	h = CreateFileA(argv[1],  
                 GENERIC_READ,  
                0 ,  
                NULL,  
                OPEN_EXISTING,   
                FILE_ATTRIBUTE_NORMAL,  
                NULL);
	if (h != INVALID_HANDLE_VALUE)  
    {  
        
    }  
    else  
    {  
       printf("creatfile fail!!!\n");
	   exit(1);
    }  

	
	int bRet;
	DWORD dwReadSize;
	char chBuffer1[100];
	//__asm int 3
	bRet = ReadFile(h,chBuffer1,20,&dwReadSize,NULL);  

	CloseHandle(h);
	if((chBuffer1[0]=='v')&&(chBuffer1[1]='u')&&(chBuffer1[2]=='l'))
	{
		printf("vul\n");
	}
	else
	{
		printf("error file magic!\n");
		//exit(0);
	}

	
	//fclose(fp); //关闭文件
	FindClose(h);
}
return 0;
}