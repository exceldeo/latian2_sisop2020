#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main() {
  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  int count = 1 ;
  while (1) {
    FILE *fp, *fb;
    char c,nama[100];
    fp = fopen("/home/excel/Desktop/kuliah/smt4/sisop2020/sesi lab/2/latian2_sisop2020/diary.txt","r");
    if(fp == NULL)
    {
      printf("Invalid Input\n");
      exit(0);
    }
    snprintf(nama, 100, "/home/excel/Desktop/kuliah/smt4/sisop2020/sesi lab/2/latian2_sisop2020/diary.log.%d",count);
    count++;
    fb=fopen(nama, "w+");
    while(1) {
        c = fgetc(fp);
        if( feof(fp) ) { 
            break;
        }
        fputc(c,fb);
        // printf("%c", c);
    }
    fclose(fp);
    fclose(fb);
    
    fp = fopen("/home/excel/Desktop/kuliah/smt4/sisop2020/sesi lab/2/latian2_sisop2020/diary.txt", "w");
    fclose(fp);

    sleep(10);
  }
}