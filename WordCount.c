#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main (int argc,char *args[]) {
	int ch, count = 1;
	FILE *file;//�ļ�ָ��
// �ж��Ƿ������ļ�
	if (argc != 3) {
		printf("ʹ�ø�ʽ����");
		exit(1);    //�������˳�
	}
	// �ж��ܷ�ɹ����ļ�
	if ((file = fopen(args[2],"r")) == NULL) {
		printf("���ļ� %s ʧ��",args[2]);
		exit(1);
	}

	if (strcmp(args[1], "-c") == 0) {
		count = 0;
		while((ch = getc(file)) != EOF) {
			//EOF ��ʾ�ļ�����
			count++;
		}
		printf("�ַ���%d��\n", count);
	} else {
		while((ch = getc(file)) != EOF) {
			if ((ch == ' ') || (ch == ',')) count++;
		}
		printf("������%d��\n", count);
	}
	fclose(file);
	return 0;
}
