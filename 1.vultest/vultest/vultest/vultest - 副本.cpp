// vulTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

// mywps.cpp : 定义控制台应用程序的入口点。
//

#include <windows.h>
 HANDLE h;
class Test
{
  private:
    int a;
    void foo(void);

  public:
    Test(int num) { this->a = num; };
    ~Test() {};
    virtual void wrapper(void);
};

void Test::foo(void) {
  cout << this->a << std::endl;
}

 void Test::wrapper(void) {
  this->foo();
}

 void stack_overflow(char*chBuffer1)
 {
	printf("liu stack overflow 15\n");
	char buff_stack[10];
	unsigned int sizestack=*(unsigned int*)(&chBuffer1[11]);
	if(sizestack>14)
		printf("%d is too large!\n",sizestack);
	memcpy(buff_stack,(char*)(&chBuffer1[20]),sizestack);
	printf("%s",buff_stack);

 }
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
	bRet = ReadFile(h,chBuffer1,100,&dwReadSize,NULL);  

	CloseHandle(h);
	if((chBuffer1[0]=='v')&&(chBuffer1[1]='u')&&(chBuffer1[2]=='l'))
	{
		if(chBuffer1[3]=='1')
		{
			if(chBuffer1[4]=='5')
			{
				///liu stack overflow 15
				stack_overflow(chBuffer1);
				/*printf("liu stack overflow 15\n");
				char buff_stack[10];
				unsigned int sizestack=*(unsigned int*)(&chBuffer1[11]);
				if(sizestack>14)
					printf("%d is too large!\n",sizestack);
				memcpy(buff_stack,(char*)(&chBuffer1[20]),sizestack);
				printf("%s",buff_stack);*/
			}
			else if(chBuffer1[4]=='6')
			{
				if(chBuffer1[5]=='3')
				{
					///liu heap overflow 163
					printf("liu heap overflow 163\n");
					char* buff_heap=(char*)malloc(8);
					unsigned int sizeheap=*(unsigned int*)(&chBuffer1[11]);
					if(sizeheap>14)
						printf("%d is too large!\n",sizeheap);
					memcpy(buff_heap,(char*)(&chBuffer1[20]),sizeheap);
					printf("%s",buff_heap);
					free(buff_heap);
				}
				else if(chBuffer1[5]=='4'){
					if(chBuffer1[6]=='3')
					{
						///liu divides 0 1643
						printf("liu divides 0 1643\n");
						int sizedevide=*( int*)(&chBuffer1[11]);
						if(sizedevide==0)
							printf("%d can not be devided!\n",sizedevide);
						int result=100/sizedevide;
						printf("result=%d",result);
						
					}
					else if(chBuffer1[6]=='4'){
						if(chBuffer1[7]=='3')
						{
							///liu uaf 16443
							printf("liu uaf 16443\n");
							Test *ptr = new Test(1234);
							ptr->wrapper();
							int iffree=*( int*)(&chBuffer1[11]);
							if(iffree==0)
							{
							delete ptr;
							}
							ptr->wrapper();
							
						}
						else if(chBuffer1[7]=='7'){
							if(chBuffer1[8]=='3')
							{
								///liu width overflow 164473
								printf("liu width overflow 164473\n");
										unsigned char s;
										unsigned int i;
										char *buf_width;
										buf_width=(char*)malloc(80);
										
										i = *(unsigned int *)(&chBuffer1[11]);
										s = i;
										if(s >= 80){            /* [w1] */
										   printf("Oh length too long!\n");
										   return 1;
										 }
										else
										{
											if(i>100)
												printf("%d length too long!\n",i);
											memcpy(buf_width,(char*)(&chBuffer1[20]),i);
											printf("%s",buf_width);
										}
							}
							else if(chBuffer1[8]=='4'){
								if(chBuffer1[9]=='2')
								{
									///liu calc overflow 1644742
									printf("liu calc overflow 1644742\n");
									char *myarray1;
									unsigned char size=chBuffer1[11];
									unsigned char count=size;
									size=size+4;
									myarray1=(char*)malloc(size);
									if(count>0xfe)
										printf("%d length too long!\n",count);
									memcpy(myarray1,(char*)(&chBuffer1[20]),count);
									printf("%s",myarray1);
									free(myarray1);
								}
								else if(chBuffer1[9]=='1'){
									if(chBuffer1[10]=='3')
									{
										///liu signed overflow 16447413
										printf("liu signed overflow 16447413\n");
										char* signedbuff;
										signedbuff=(char*)malloc(10);
										char signedsize=*( char *)(&chBuffer1[11]);
										if(signedsize<10)
										{
											if((unsigned int)signedsize>0x80)
												printf("%d length too long!\n",signedsize);
											memcpy(signedbuff,(char*)(&chBuffer1[20]),signedsize);
											printf("%s",signedbuff);
										}
										else{
											printf("size illegal!\n");
										}
									}
									
									else{
										printf("no vul!\n");
									}
									
								}
								else{
									printf("no vul!\n");
								}
								
							}
							else{
								printf("no vul!\n");
							}
							
						}
						else{
							printf("no vul!\n");
						}
						
					}
					else{
						printf("no vul!\n");
					}
					
				}
				else{
					printf("no vul!\n");
				}
			}
			else{
				printf("no vul!\n");
			}
		}
		else
		{
			printf("no vul!\n");
		}
	}
	else
	{
		printf("error file magic!\n");
		exit(0);
	}

	
	//fclose(fp); //关闭文件
	FindClose(h);
}
return 0;
}