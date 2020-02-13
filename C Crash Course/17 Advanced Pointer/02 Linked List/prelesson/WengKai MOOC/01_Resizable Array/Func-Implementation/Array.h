#ifndef _ARRAY_H_
#define _ARRAY_H_

#define BLOCK_SIZE 20

typedef struct {
	int* array;
	int size;
}Array;

Array array_creat(int init_size);//��ʼ������
void array_free(Array* a);//�ͷŶ��Ͽռ�
int array_size(const Array* a);//�鿴����Ĵ�С
int* array_at(Array* a, int index);
void array_inflate(Array* a, int more_size);

#endif