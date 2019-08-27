// C program to demonstrate use of fork() and pipe() 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main() 
{ 
	char fixed_str[] = "_________ before underscores is sample of input string from other process..."; 
	const int BUF_SIZE = 100;
	char input_str[BUF_SIZE+sizeof(fixed_str)]; //TODO need to fix it
	pid_t p; 

	int fd1[2]; //two ends of first pipe. Used to send input string from parent
	if (pipe(fd1)==-1) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	}

	int fd2[2]; //store two ends of second pipe. Used to send concatenated string from child
	if (pipe(fd2)==-1) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 

	scanf("%s", input_str); 
	p = fork(); 

	if (p < 0) 
	{ 
		fprintf(stderr, "fork Failed" ); 
		return 1; 
	} else if (p > 0) { //parent process
		char concat_str[BUF_SIZE]; 

		close(fd1[0]); // Close reading end of first pipe 

		// Write input string and close writing end of first pipe 
		write(fd1[1], input_str, strlen(input_str)+1); 
		close(fd1[1]); 

		// Wait for child to send a string 
		wait(NULL); 

		close(fd2[1]); // Close writing end of second pipe 

		// Read string from child, print it and close reading pipe.
		read(fd2[0], concat_str, BUF_SIZE); 
		printf("Concatenated string: \n%s\n", concat_str); 
		close(fd2[0]); 
	} else { //child process
		close(fd1[1]); // Close writing end of first pipe 

		// Read a string using first pipe 
		char concat_str[BUF_SIZE]; 
		read(fd1[0], concat_str, BUF_SIZE); 

		// Concatenate a fixed string with it 
		int k = strlen(concat_str); 
		int i; 
		for (i=0; i<strlen(fixed_str); i++) 
			concat_str[k++] = fixed_str[i]; 

		concat_str[k] = '\0'; // string ends with '\0' 

		// Close both reading ends 
		close(fd1[0]); 
		close(fd2[0]); 

		// Write concatenated string and close writing
		write(fd2[1], concat_str, strlen(concat_str)+1); 
		close(fd2[1]); 

		exit(0); 
	} 
} 

