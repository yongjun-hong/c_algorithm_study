#include <stdio.h>

#define MAX_SIZE 1000
int list[MAX_SIZE];

//
//
//
init_list()
{
	int i;
	for(i=0;i<1000;i++)
		list[i] = 7*i;
}

//
int search_binary(int key, int low, int high)
{  
   int middle;
   if(low<=high){
      middle = (low+high)/2;
      if(key==list[middle])    // Ž�� ����
	   return middle;
      else if(key<list[middle]) // ���� �κи���Ʈ Ž�� 
	   return search_binary(key, low, middle-1);
      else                   // ������ �κи���Ʈ Ž�� 
	   return search_binary(key, middle+1, high);
     }
   return -1;        // Ž�� ����
}

int search_binary2(int key, int low, int high)	
{  
  int middle;   

	while( low <= high ){       // ���� ���ڵ��� ���� ������
	   middle = (low+high)/2;   
	   if( key == list[middle] )
			return middle;
		else if( key > list[middle] )
			low = middle+1;
		else 
			high = middle-1;
	}   
	return -1;   // �߰ߵ��� ���� 
}

//
int search_interpolation(int key, int n)
{
     int low, high, j;
     low = 0;
     high = n-1;
	 while ((list[high] >= key) && (key > list[low])){
          j = ((float)(key-list[low]) / (list[high]-list[low]) *
                         (high-low) ) + low;
          if( key > list[j] ) low = j+1;
          else if (key < list[j]) high = j-1;
          else low  = j;
	 }
     if (list[low] == key) return(low);  //found(r[low])
     else return -1;  // notfound(key)
}

//
void main()
{
		int i =0;
		init_list();
		i = search_binary2(49, 0, 999);
		if( i >= 0 ) {
			printf("Ž�� ���� i=%d\n", i);
		}
		else {
			printf("Ž�� ����\n");
		}
}


