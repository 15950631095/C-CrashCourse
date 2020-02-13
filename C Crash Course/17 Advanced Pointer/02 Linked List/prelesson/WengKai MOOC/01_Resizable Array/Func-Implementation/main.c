#define _CRT_SECURE_NO_WARNINGS 1

#include"Array.h"
#include<stdio.h>
#include<stdlib.h>
//typedef struct {
//	int* array;
//	int size;
//}Array;

Array array_creat(int init_size) {

	Array a;

	a.array = (int*)malloc(sizeof(int) * init_size);
	a.size = init_size;

	return a;
}
//Ϊ�β�����ָ�룿
//���磺Array array_creat(Array* a, int init_size)
//�������£�
//1.���a == NULL��
//2.���aָ������Ѿ�malloc���Ŀռ䣬������Ҫ��freeһ��

void array_free(Array* a) {

	free(a->array);
	a->array = NULL;//��ֹ�˺������������Ρ�free(NULL)�ǿ��Ե�
	a->size = 0;
}

int array_size(const Array* a) {

	return a->size;
}

int* array_at(Array* a, int index) {

	if (index >= a->size)
		array_inflate(&a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
	//Ϊʲô��ֱ�Ӽ���һ�� BLOCK_SIZE�������� index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size) ��ô���ӵĹ�ʽ��
	//������ǿ�˳���Ŀɱ��ԣ����ĳһ���������ӵĴ�С�㲻���������� 100 ���ӵ� 150
	//ֱ�Ӽ� BLOCL_SIZE ���ܲ������ã����Ÿ���ʽ���ӵĴ�Сһ�� ���ڵ��� ��Ҫ���ӵĴ�С��
	//Ϊʲô���� BLOCKJ_SIZE ��
	//һ���� �����˳������չ�ԣ����Է�����ģ��Ϳɶ��ԣ���һ���� 
	//��������õ� BLICK_SIZE ���������С��ʱ������ 1������̫�˷��ڴ�
	//������õĹ�С�Ͳ��������������ĸ���
	//�ñ��� BLOCK_SIZE = 20 Ϊ����һ���������� 19 �� int �Ĵ�С����Ҳ����ζ��
	//���ַ����˷ѵ��ڴ����ֻ�� 19*sizeof(int) ���ֽ�

	return &(a->array[index]);
}

////�������Ԫ��
//int array_get(const Array a, int index) {
//
//	return a.array[index];
//}
////�޸�����Ԫ��
//int array_set(Array* a, int index, int value) {
//	
//	return (a->array[index] = value);
//}

void array_inflate(Array* a, int more_size) {

	int* p = (int*)malloc(sizeof(int) * (a->size + more_size));
	int i = 0;

	//�ɻ���memcpy
	for (i = 0; i < a->size; i++) {
		p[i] = a->array[i];
	}
	free(a->array);

	a->array = p;
	a->size += more_size;
}


int main(void) {

	Array a;
	int size = 0;

	printf("��ʼ�������С,�����룺\n");
	scanf("%d", &size);

	a = array_creat(size);

	printf("%d members in array\n", array_size(&a));
	//Ϊʲô��ֱ���� a.size �������Ĵ�С��
	//�����ú��������������С�ķ�ʽ�ͽ��� ��װ
	//�պ�����а汾���£��㷨�Ż��ȵȣ������ú�����ʵ�֣���ʵ�ֵĴ��뱣������

	//array_at(&a, 1) ���� &(a.array[1]) �����ü�ʹ������� array[1]
	//��Ȼ����������Բ𿪣�ʵ����array_at ��
	*array_at(&a, 1) = 10;
	printf("a.array[1] = %d\n", *array_at(&a, 1));


	return 0;
}




