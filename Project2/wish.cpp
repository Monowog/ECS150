//Programmer: Jackson Cmelak
//ID #: 921447247

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 150

char error_message[30] = "An error has occurred\n";

int main(int argc, char* argv[]){

	char mode;
	char line[MAX_LEN] = "";
	char* result = NULL;
	
	
	//determine whether interactive or batch mode
	if(argc == 1){
	
		mode = 'i';
		printf("Interactive\n");
		
	}
	else if(argc == 2){
	
		mode = 'b';
		printf("%s\n", argv[1]);
		
	}
	else{

		write(STDERR_FILENO, error_message, strlen(error_message));
		exit(1);

	}
	
	//interactive loop
	while(mode == 'i'){

		printf("wish> ");
		result = fgets(line, MAX_LEN, stdin);

		strtok(result, "\n");
		
		printf("%s\n", result);
	

		//parseCommand(result);


	}
	
	return 0;
}

