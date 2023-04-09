#include <stdio.h>

#define MAX_SIZE 1000
#define INDEX_SIZE 10

int list[MAX_SIZE] = {3, 9,15, 22, 31, 55, 67, 88, 91};
int n=9;
typedef struct { 
		int key;
		int index; 
} itable;
itable index_list[INDEX_SIZE]={ {3,0}, {15,3}, {67,6} };

int seq_search(int key, int low, int high)
{  
	int i;
    for(i=low; i<=high; i++)
       if(list[i]==key)
	   return i;  /* Ž���� �����ϸ� Ű ���� �ε��� ��ȯ */
    return -1;    /* Ž���� �����ϸ� -1 ��ȯ */
}

/* INDEX_SIZE�� �ε��� ���̺��� ũ��,n�� ��ü �������� �� */
int index_search(int key)
{  
   int i, low, high;
	/* Ű ���� ����Ʈ ���� ���� ���� �ƴϸ� Ž�� ���� */
   if(key<list[0] || key>list[n-1])
      return -1;

   /* �ε��� ���̺��� �����Ͽ� �ش�Ű�� ���� ���� */
   for(i=0; i<INDEX_SIZE; i++) 
      if(index_list[i].key<=key &&
			 index_list[i+1].key>key)
	 	break;
   if(i==INDEX_SIZE){  /* �ε������̺��� ���̸� */
      low = index_list[i-1].index;   
      high = n;
   }
   else{
      low = index_list[i].index;  
      high = index_list[i+1].index;
   }
   /* ����Ǵ� ������ ���� Ž�� */
   return seq_search(key, low, high);
}

//
void main()
{
		int i;
		i = index_search(67);
		if( i >= 0 ) {
			printf("Ž�� ���� i=%d\n", i);
		}
		else {
			printf("Ž�� ����\n");
		}
}


