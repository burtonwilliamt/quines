#include <stdio.h>
#include <string.h>

void quineify(char* string){
	int len = strlen(string);
	for( int i = 0; i < len; ++i){
		if(string[i] == '"'){
			printf("\\\"");
		}else if(string[i] == '\n'){
			printf("\\n");
		}else if(string[i] == '\t'){
			printf("\\t");
		}else if(string[i] == '%'){
			printf("\\%%");
		}else if(string[i] == '\\'){
			printf("\\\\");
		}else{
			printf("%c", string[i]);
		}
	}
}

int main(int argc, char* argv[]){
	char* x = "#include <stdio.h>\n#include <string.h>\n\nvoid quineify(char* string){\n\tint len = strlen(string);\n\tfor( int i = 0; i < len; ++i){\n\t\tif(string[i] == '\"'){\n\t\t\tprintf(\"\\\\\\\"\");\n\t\t}else if(string[i] == '\\n'){\n\t\t\tprintf(\"\\\\n\");\n\t\t}else if(string[i] == '\\t'){\n\t\t\tprintf(\"\\\\t\");\n\t\t}else if(string[i] == '\%'){\n\t\t\tprintf(\"\\\\\%\%\");\n\t\t}else if(string[i] == '\\\\'){\n\t\t\tprintf(\"\\\\\\\\\");\n\t\t}else{\n\t\t\tprintf(\"\%c\", string[i]);\n\t\t}\n\t}\n}\n\nint main(int argc, char* argv[]){\n\tchar* x = \"\";\n\tchar first[512];\n\tchar second[512];\n\tstrncpy(first, x, 461);\n\tfirst[461] = '\\0';\n\tstrncpy(second, x+461, 200);\n\tprintf(\"\%s\", first);\n\tquineify(x);\n\tprintf(\"\%s\", second);\n}";
	char first[512];
	char second[512];
	strncpy(first, x, 461);
	first[461] = '\0';
	strncpy(second, x+461, 200);
	printf("%s", first);
	quineify(x);
	printf("%s", second);
}
