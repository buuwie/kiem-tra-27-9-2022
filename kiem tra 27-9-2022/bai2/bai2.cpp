#include <iostream>
#include <conio.h>
#include <pthread.h>
#include <windows.h>
#include <string.h> 
using namespace std; 
string st; 
void ham1()
{
	while(1)
	{
		getline(cin, st);
		if(st.compare("quit") == 0)
			break;
		Sleep(1000);
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
		cout << st; 
		if(st.compare("quit") == 0)
			break;
		Sleep(1000);
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
	
   	printf("Hello: \n");

    pthread_create(&thrd_1,NULL,fun_thread1,NULL);
	pthread_create(&thrd_2,NULL,fun_thread2,NULL);
    pthread_join(thrd_1, (void **)&status);
    pthread_join(thrd_2, (void **)&status);
    system("PAUSE");
    return 1;
}
