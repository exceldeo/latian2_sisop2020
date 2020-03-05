#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t child_id;

  child_id = fork();
  
  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child
    
    // char *argv[] = {"cp", "/home/excel/Musik", "/home/excel/coba", NULL};
    // execv("/bin/cp", argv);
  } else {
    // this is parent
    char *argv[] = {"date", "+%d-%m-%y_%H:%M:%S", NULL};
    execv("/bin/date", argv);
    // ren somefile.txt  somefile_%time:~0,2%%time:~3,2%-%DATE:/=%.txt
    // char *argv[] = {"mv", "/home/excel/coba", "/home/excel/", NULL};
    // execv("/bin/mv", argv);
  }
}