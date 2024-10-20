//Programmer: Jackson Cmelak
//ID #: 921447247

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 150

char error_message[30] = "An error has occurred\n";

//Determines which command is input, then executes
void parseCommand(char* input, int args){

	char* token = NULL;

	token = strtok(input, " \t\v"); //take first word

	if(strcmp(token, "exit") == 0){
	
		if(args > 1){
		
			write(STDERR_FILENO, error_message, strlen(error_message));
			
		} else {
		
			exit(0); 
			
		}
		
	} else if (strcmp(token, "cd") == 0 && args == 2){
	
		token = strtok(input, " \t\v");
		
		if (chdir(token) == 0){
			printf("success\n");
		} else {
			write(STDERR_FILENO, error_message, strlen(error_message));
		}
	
	} else if (strcmp(token, "path") == 0){
	
	
	
	} else {

		write(STDERR_FILENO, error_message, strlen(error_message));

	}
}


int main(int argc, char* argv[]){

	char mode;
	char line[MAX_LEN] = "";
	char* result = NULL;
	
	
	//determine whether interactive or batch mode
	if(argc == 1){
	
		mode = 'i';
		
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

		int args = 0;
		char* tmp = NULL;

		printf("wish> ");
		result = fgets(line, MAX_LEN, stdin);

		strtok(result, "\n");
		
		tmp = result;

    		char* token = strtok(tmp, " \t\v");

				
		//find # of args past the first
    		while (token != NULL) {
        		args++;
       			token = strtok(NULL, " \t\v"); 
    		}

		parseCommand(result, args);

	}
	
	return 0;
}

