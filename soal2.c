#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>

int main() {
  pid_t child_id;
  int status;

  child_id = fork();
  
  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child
    
    char *argv[] = {"cp","-r", "/home/excel/Music", "/home/excel/Desktop/coba1", NULL};
    execv("/bin/cp", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    char *argv[] = {"bash", "time.sh", NULL};
    execv("/bin/bash", argv);

  }
}