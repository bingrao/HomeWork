#include "../include/scanner.h"

int main(int argc, char* argv[]){
	char *path = NULL;
	switch(argc){
		case 1:{
			path = "../input/dfa.txt";
		}break;
		case 2:{
			
		}break;
		case 3:{
			path = argv[2];
		}break;
		default:{
			logerror("The input parameters error\n");
			return -1;
		}
	}


	
	FILE* fin = fopen(path,"r");
	if(fin == NULL){
		logerror("Open file failed, please double check: %s\n",path);
		return -1;
	}
	loginfo("read file successfuly\n");
	fclose(fin);


	
	Scanner_t *scanner = scanner_init(NULL);
	if(scanner == NULL){
		logerror("init a scanner failed\n");
		return -1;
	}
	scanner->run(scanner,path);

	scanner->printLexmeList(scanner,path);

	struct SymTable *symbolTable = scanner->symbolTable;

	symbolTable->printinfo(symbolTable,2);

	scanner->exit(scanner);

	free(scanner);

	return 0;
}

