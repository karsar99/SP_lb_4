#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int main(){
	int number, status;
	cout << "\nВведите номер шара: ";

	cin >> number;

	pid_t parrent = getpid();
	pid_t child;

	for(int i = 0; i < number; ++i){
		if(parrent == getpid()){
			child = fork();
		}
		switch(child){
			case -1: cout << "-1 Ошибка\n";
			case 0: cout << "case 0" << " PID:" << getpid() << "|" << getppid() << "\n";
			default: cout << "\n";	
		}
		if(child == 0){
			execl("child", "child", to_string(i+1).c_str(), NULL);
		}
		else if(child > 0){
			wait(&status);
		}
	}
	return 0;
}
