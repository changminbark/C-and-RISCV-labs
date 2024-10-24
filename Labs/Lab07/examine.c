/*
 * A Linux file examiner
 * CSCI306
 * Chang Min
 */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Usage: %s FILE\n", argv[0]);
		return 1;
	}

	int f = open(argv[1], O_RDONLY);

	if (f < 0){
		perror("error");
		return 2;
	}

	// use fstat to examine file status
    
    struct stat fileStat;
    if (fstat(f, &fileStat) == -1) {
        perror("fstat error");
        close(f);
        return 1;
    }

    printf("st_dev:     %ld\n", (long)fileStat.st_dev);
    printf("st_ino:     %ld\n", (long)fileStat.st_ino);
    printf("st_mode:    %o\n", fileStat.st_mode);
    printf("st_nlink:   %ld\n", (long)fileStat.st_nlink);
    printf("st_uid:     %ld\n", (long)fileStat.st_uid);
    printf("st_gid:     %ld\n", (long)fileStat.st_gid);
    printf("st_rdev:    %ld\n", (long)fileStat.st_rdev);
    printf("st_size:    %ld\n", (long)fileStat.st_size);
    printf("st_blksize: %ld\n", (long)fileStat.st_blksize);
    printf("st_blocks:  %ld\n", (long)fileStat.st_blocks);
    
    printf("st_atime:   %s", ctime(&fileStat.st_atime));
    printf("st_mtime:   %s", ctime(&fileStat.st_mtime));
    printf("st_ctime:   %s", ctime(&fileStat.st_ctime));

	close (f);
	return 0;
}
