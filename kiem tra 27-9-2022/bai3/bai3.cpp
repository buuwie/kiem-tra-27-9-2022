#include <iostream>
#include <conio.h>
#include <pthread.h>
#include <windows.h>
char c;
void ham1()
{
	while(1)
	{
		c=getch();
		printf("%c",c);
		if(c=='!')
			break;
		Sleep(7);
	}
}

void * fun_thread1(void *data)
{
    ham1(); 
}

void ham2()
{
	while(1)
	{
		if(c=='!')
			break;
		Beep(2000, 1000);
		
		Sleep(1);
	}
}

void * fun_thread2(void *data)
{
    ham2(); 
}
int main(int argc, char *argv[])
{
    int status;
    pthread_t thrd_1;
	pthread_t thrd_2;
	
   	printf("Hello:\n");
    pthread_create(&thrd_1,NULL,fun_thread1,NULL);
    pthread_join(thrd_1, (void **)&status);
    
    pthread_create(&thrd_2,NULL,fun_thread2,NULL);
    pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
}
