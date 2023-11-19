#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define RECORDSIZE 512
#define NAMSIZ 100
#define TUNMLEN 32
#define TGNMLEN 32

// Structure representing the header of a tar file entry
struct header {
    char name[NAMSIZ];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char chksum[8];
    char linkflag;
    char linkname[NAMSIZ];
    char magic[8];
    char uname[TUNMLEN];
    char gname[TGNMLEN];
    char devmajor[8];
    char devminor[8];
};

// Function to print error messages and exit the program
void print_error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to add a file to a tar archive
void add_file_to_tar(FILE *tarfile, FILE *infile, char *filename) {
    // Create and initialize a tar header
    struct header header;
    memset(&header, 0, sizeof(header));
    strncpy(header.name, filename, NAMSIZ);

    // Get file stats
    struct stat sb;
    if (fstat(fileno(infile), &sb) == -1) {
        print_error("Error getting file stats");
    }

    // Fill in header fields with file information
    sprintf(header.mode, "%07o", (unsigned int)sb.st_mode);
    sprintf(header.uid, "%07o", (unsigned int)sb.st_uid);
    sprintf(header.gid, "%07o", (unsigned int)sb.st_gid);
    sprintf(header.size, "%011lo", (unsigned long)sb.st_size);
    sprintf(header.mtime, "%011lo", (unsigned long)sb.st_mtime);

    header.linkflag = sb.st_nlink > 1 ? '1' : '\0';

    strncpy(header.uname, "root", TUNMLEN);
    strncpy(header.gname, "root", TGNMLEN);

    memcpy(header.magic, "ustar\0", 8);

    // Read file content into data and calculate checksum
    unsigned char data[RECORDSIZE];
    memset(data, 0, RECORDSIZE);
    size_t filesize = sb.st_size;
    fread(data, 1, filesize, infile);

    int chksum = 0;
    for (int i = 0; i < sizeof(header); i++) {
        chksum += ((unsigned char *)&header)[i];
    }
    sprintf(header.chksum, "%06o", chksum);

    // Write header and data to tar file
    fwrite(&header, sizeof(header), 1, tarfile);
    fwrite(data, RECORDSIZE, filesize / RECORDSIZE + (filesize % RECORDSIZE != 0), tarfile);
}

// Main function to create a tar archive from input files
int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc < 3) {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    // Open tar file for writing
    FILE *tarfile = fopen("Result.tar", "wb");
    if (!tarfile) {
        print_error("Error opening Result.tar");
    }

    // Process each input file and add it to the tar file
    for (int i = 1; i < argc; i++) {
        FILE *infile = fopen(argv[i], "rb");
        if (!infile) {
            print_error("Error opening input file");
        }

        add_file_to_tar(tarfile, infile, argv[i]);
        fclose(infile);
    }

    // Close the tar file
    fclose(tarfile);
    return 0;
}
