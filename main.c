#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
	int pipefd[2];
		if (pipe(pipefd) == -1){
		perror("Error");
		return 1;
		}

		pid_t pid =  fork();
	
		if (pid < 0){
		perror("Error al ejecutar()");
		return  1;} 
		
		else if (pid == 0){
			close(pipefd[1]);
			char señal;
			read(pipefd[0], &señal, 1);

		for (int i =  10000; i >=  1; i--){
			printf("HIJO %d\n", i);
			}
		close(pipefd[0]);
				}
		else {
		close(pipefd[0]);
		for (int i =  1; i <= 10000; i++){
		printf("Padre %d\n", i);
			}

		char señal ='X';
		write(pipefd[1], &señal,1);

		waitpid(pid, NULL, 0);
		close(pipefd[1]);
		}
		return 0; 
		}
