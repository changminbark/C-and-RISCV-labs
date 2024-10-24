/*
 * Compute the sha256 sum of a file
 * Chang Min
 * */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "sha256.h"

int main(int argc, char* argv[])
{
    if (argc < 2){
        // missing required file argument
        printf("Usage %s FILE\n", argv[0]);
        return(1);
    }

    // SHA256 context
    SHA256_CTX ctx;
    // buffer size to read from the file
    const int BS = 1024;
    // buffer to hold the data read from the file
    unsigned char block[BS];
    // store the final block
    unsigned char hash[SHA256_BLOCK_SIZE];

    // initialize the SHA256 context
    sha256_init(&ctx);
    
    // open the file for reading
    int f = open (argv[1], O_RDONLY);
    if (f <  0){
        perror("error");
        return(2);
    }

    // TODO: Read from the file using the "read" function into "block"
    // pass all read data to sha256_update
    // repeat until you have processed the entire file

    // Pseudo code:
    // while ( (bytes_read = read_data_from_file) > 0 )
    //     sha256_update(&ctx, data, bytes_read)
    
    // YOUR CODE BEGINS HERE
    ssize_t bytes_read;

    while ((bytes_read = read(f, block, BS)) > 0){
        sha256_update(&ctx, block, bytes_read);
    }

    // YOUR CODE ENDS HERE
    // once you have read all of the file and passed it to sha256_update 
    // we have to call sha256_final to copy the final hash value into 
    // the block hash
    sha256_final(&ctx, hash);

    // now we can print the final hash that we just computed
    for (int i=0; i < SHA256_BLOCK_SIZE; i++){
        printf("%02x", hash[i]);
    }
    printf("  %s\n", argv[1]);

}
