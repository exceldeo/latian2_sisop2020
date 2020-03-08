#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <time.h>  
#include <string.h>
#define Size 50 

int main() {
  pid_t child_id;
  int status;

    time_t t ; 
    struct tm *tmp ; 
    char MY_TIME[Size]; 
    time( &t ); 
      
      
    tmp = localtime( &t ); 
      
    // using strftime to display time 
    strftime(MY_TIME, sizeof(MY_TIME), "%d-%m-%Y_%H:%M:%S", tmp);
    char coba[] = "/home/excel/Desktop/";
    strcat(coba,MY_TIME);

  child_id = fork();
  
  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child
    
    char *argv[] = {"mkdir","-p",coba, NULL};
    execv("/bin/mkdir", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    char apalah[] = "/home/excel/Music";

    puts(MY_TIME);
    
    char *argv[] = {"cp","-r",apalah,coba,NULL};
    execv("/bin/cp", argv);


 
  }
}