#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 10

typedef struct {
    long msg_type;
    char msg_txt[100];
} message;

int main() {
    key_t key;
    key = ftok("ipc", 65);

    int msg_id = msgget(key, 0666|IPC_CREAT);
    message msg;
    msg.msg_type = 1;
    printf("Write data: ");
    fgets(msg.msg_txt, 100, stdin);

    msgsnd(msg_id, &msg, sizeof(msg), 0);
    printf("Sent %s\n", msg.msg_txt);
    return 0;
}