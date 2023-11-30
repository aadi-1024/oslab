#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct {
    long msg_type;
    char msg_txt[100];
} message;

int main() {
    key_t key;
    int msg_id;
    message msg;

    key = ftok("ipc", 65);

    msg_id = msgget(key, 0666|IPC_CREAT);

    msgrcv(msg_id, &msg, sizeof(msg), 1, 0);

    printf("Data received: %s\n", msg.msg_txt);
    msgctl(key, IPC_RMID, NULL);
    return 0;
}