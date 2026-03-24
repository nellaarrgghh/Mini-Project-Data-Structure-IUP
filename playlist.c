#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
} Song;
// Queue
Song queue[100];
int front = -1, rear = -1;
// Stack
Song stack[100];
int top = -1;
// Enqueue
void enqueue(Song song_stack) {
    if (rear == 99)  
    return;
    if (front == -1) 
    front = 0;
    queue[++rear] = song_stack;
}
// Dequeue
Song dequeue() {
    Song song_stack = {"None"};
    if (front == -1) 
    return song_stack;

    song_stack = queue[front];
    if (front == rear) 
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return song_stack;
}
void push(Song song_stack) { //Push
    if (top == 99) 
    {
        //printf("Full stack\n");
        return;
    }
    stack[++top] = song_stack;
}
Song pop() {//Pop
    Song song_stack = {"None"};
    if (top == -1) return song_stack;
    return stack[top--];
}

int main() {
    int option;
    Song current;

    while (1) {
        printf("\n=== Nel's Playlist ===\n");
        printf("1. Add Song\n");
        printf("2. Next\n");
        printf("3. Prev\n");
        printf("4. Exit\n");
        printf("What's for today, Nel?: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                Song s;
                printf("Song title: ");
                scanf(" %[^\n]", s.title);
                enqueue(s);
                printf("Song added!\n");
                break;
            }
            case 2:
                current = dequeue();
                if (strcmp(current.title, "None") == 0) {
                    printf("No songs available :(\n");
                } else {
                    printf("Now Playing: %s\n", current.title);
                    push(current);
                }
                break;
            case 3:
                current = pop();
                if (strcmp(current.title, "None") == 0) {
                    printf("No song to replay :(\n");
                } else {
                    printf("Replaying: %s\n", current.title);
                }
                break;
            case 4:
                printf("Thanks for listening, Nel! Have a pleasant day!\n");
                return 0;
            default:
                printf("Error. Invalid option.\n");
                break;
        }
    }
    return 0;
}