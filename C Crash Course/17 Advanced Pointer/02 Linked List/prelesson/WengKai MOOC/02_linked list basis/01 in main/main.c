#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"Array.h"

//typedef struct _node {
//
//	char name[20];
//	char gender[5];
//	int age;
//	long long ID;
//}node;

int main(void) {

	node* head = NULL;
	int count = 1;
	int Exit = 0;

	do {
		printf("�Ƿ���������� 0 �˳�\n");
		scanf("%d", &Exit);

		if (Exit) {
			printf("������� %d ��ѧ����Ϣ\n", count++);
			node* p = (node*)malloc(sizeof(node));
			printf("\t\t����: ");
			scanf("%s", p->Name);
			printf("\t\t�Ա�: ");
			scanf("%s", p->Gender);
			printf("\t\t����: ");
			scanf("%d", &(p->Age));
			printf("\t\tѧ��: ");
			scanf("%lld", &(p->ID));

			p->next = NULL;

			node* last = head;//�����µĽڵ���ҪѰ�����һ���� NULL �Ľڵ�

			//�����ͷ�ǿ�ָ��
			if (last) {
				//�ڵ� ָ����ΪNULL �ҵ���
				while (last->next)
					last = last->next;
				last->next = p;
			}
			else
				head = p;
		}
	} while (Exit);


	return 0;
}




