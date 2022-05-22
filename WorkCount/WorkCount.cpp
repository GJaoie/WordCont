
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdlib>
#include <string.h>
int main(int argc, char* argv[])
 {
	
		     
	         printf("main函数收到了%d个参数\n",argc);//第一个参数默认是可执行文件本身，第二个参数开始是接受到的参数
	         
		     if (argc == 3) {
		
			         //读取文件的内容
			         char data;
		         FILE *fp = fopen("E:\\git\\project\\WorkCount\\Debug\\test.txt", "r");
				 
			         if (fp==NULL) {
						 printf("open fail errno = % d reason = % s \n", errno, strerror(errno));
			            printf("错误：文件读取失败\n");
			            return -1;
			
		             }
		
			         
			
			         if (!strcmp(argv[1], "-c")) {//字符数
			            char temp;
			             int num = 0;
			             temp = fgetc(fp);
			             while (temp != EOF) {
					             temp = fgetc(fp);
				                 num++;
				
			}
			             printf("字符数为：%d\n", num);
			
				
		}
		         else if (!strcmp(argv[1], "-w")) {//单词数
			             int w = 0;
			            char a = fgetc(fp);
			            while (a != EOF) {
				                if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
					                     while ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
						                         a = fgetc(fp);
					                     w++;
					                     a = fgetc(fp);
					
				}
				                 else
					                     a = fgetc(fp);
				
			}
			             printf("单词数为：%d\n", w);
			
				
		}
	         else if (!strcmp(argv[1], "-l")) {//行数
			             char temp;
			             int num = 1;
			             temp = fgetc(fp);
			             while (temp != EOF) {
					             if (temp == '\n') {
					                 num++;
					
				}
				                 temp = fgetc(fp);
				
					
					
			}
			             printf("该文本文件的行数为：%d\n", num);
			
				
		}
		         else {
			            printf("错误：参数超出范围！");
			
		}
		         int n = fclose(fp);
		
	}
	     else {
	         printf("错误：运行参数必须要3个:WorkCount.exe [parameter] [file_name]\n");
	}
	     system("pause");
	     return 0;
	 }
