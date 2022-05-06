#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main (int argc,char *args[]) {
	int ch, count = 1;
	FILE *file;//文件指针
// 判断是否输入文件
	if (argc != 3) {
		printf("使用格式错误");
		exit(1);    //非正常退出
	}
	// 判断能否成功打开文件
	if ((file = fopen(args[2],"r")) == NULL) {
		printf("打开文件 %s 失败",args[2]);
		exit(1);
	}

	if (strcmp(args[1], "-c") == 0) {
		count = 0;
		while((ch = getc(file)) != EOF) {
			//EOF 表示文件结束
			count++;
		}
		printf("字符数%d个\n", count);
	} else {
		while((ch = getc(file)) != EOF) {
			if ((ch == ' ') || (ch == ',')) count++;
		}
		printf("单词数%d个\n", count);
	}
	fclose(file);
	return 0;
}
