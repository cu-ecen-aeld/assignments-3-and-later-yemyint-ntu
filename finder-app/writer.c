#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    if ( argc < 3 ) {
        printf("arguments missing");
        exit(1);
    }

    const char *filename = argv[1];
    const char *writestr = argv[2];
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Cannot open file %s for writing: %d\n", filename, errno);
        perror("perror returned");
        syslog(LOG_ERR, "Cannot open file %s for writing: %d\n", filename, errno);
        exit(1);
    }

    openlog(NULL, 0, LOG_USER);

    fprintf(file, "%s", writestr);
    syslog(LOG_DEBUG, "Writing %s to %s\n", writestr, filename);

    fclose(file);
    return 0;
}