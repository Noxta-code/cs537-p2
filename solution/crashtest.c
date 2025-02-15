#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]){
    // Test if crash returns -1 with no write() call
    printf(1, "Test crash() without write() call\n");
    int result = crash();
    if(result == -1){
        printf(1, "Test passed\n");
    } else{
        printf(1, "Test failed\n");
    }

    // Test if crash returns -1 if a write() call was made with something other than crash string
    printf(1, "Test crash() after write() with non-crash string\n");
    write(1, "random test string\n", 21); // Write something that is not the crash string
    result = crash();
    if (result == -1) {
        printf(1, "Test passed\n");
    } else {
        printf(1, "Test failed\n");
    }

    // Test if crash crashes the system after write() WITH the crash string
    printf(1, "Test crash() after write() WITH correct crash string\n");
    write(1, "it's a feature, not a bug!\n", 29);  // Crash string
    result = crash();
    if (result == -1){
        printf(1, "Test FAILED\n");
    } else {
        printf(1, "Test PASSED\n");
    }
    exit();
}
