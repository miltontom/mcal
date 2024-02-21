#include <stdio.h>
#include <string.h>

#define ANSI_BOLD "\e[1m"
#define ANSI_GREEN ANSI_BOLD"\e[32m"
#define ANSI_RESET "\e[0m"

void print_numeric_permissions(char*);
void set_permission_number(char, int*);
void display_help(void);

// TODO: implement some error handling
int main(int argc, char* argv[]) {
    #define SYMBOLIC_PERMISSION_LENGTH 9

    char *symbolic_permissions = argv[1];

    if (argc == 2 && strlen(symbolic_permissions) == SYMBOLIC_PERMISSION_LENGTH) {
        print_numeric_permissions(symbolic_permissions);
    } else {
        display_help();
        return -1;
    }

    return 0;
}

void print_numeric_permissions(char *permissions) {
    #define END_OF_STRING '\0'

    int i = 0;
    int owner = 0;
    int group = 0;
    int public = 0;

    while (permissions[i] != END_OF_STRING) {
        if (i >= 0 && i <= 2) {
            set_permission_number(permissions[i], &owner);
        } else if (i >= 3 && i <= 5) {
            set_permission_number(permissions[i], &group);
        } else {
            set_permission_number(permissions[i], &public);
        }
        i++;
    }

    printf("%d%d%d\n", owner, group, public);
}

void set_permission_number(char permission, int *target) {
    #define READ 4
    #define WRITE 2
    #define EXECUTE 1

    switch (permission) {
        case 'r':
            *target += READ;
            break;
        case 'w':
            *target += WRITE;
            break;
        case 'x':
            *target += EXECUTE;
            break;
    }
}

void display_help() {
    puts(ANSI_GREEN"Usage"ANSI_RESET);
    puts("\tmcal <symbolic_permissions>\n");
    puts(ANSI_GREEN"Description"ANSI_RESET);
    puts("\tA command-line 'chmod' calculator.\n");
    puts(ANSI_GREEN"Notes"ANSI_RESET);
    puts("\t* Symbolic permission format: [owner][group][public]");
    puts("\t* Certain permissions can be omitted with '-'\n");
    puts(ANSI_GREEN"Examples"ANSI_RESET);
    puts("\tmcal rwxrwxrwx\t-> 777");
    puts("\tmcal rwxrw-rw-\t-> 766");
    puts("\tmcal rwx------\t-> 700");
}
