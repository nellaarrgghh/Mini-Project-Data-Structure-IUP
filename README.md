## Struktur Strukdat Data
Name : Naila Sa'ada Cahyani
NRP : 5025251258

## Case Explanation
I was tasked to create a mini project implementing data structures such as Queue, Dequeue, and Stack in C program. I decided to create a playlist simulator for this project. The title of the project is *Nel's Playlist*. In the program,  user can add, skip, and go back to which songs they want to hear. 

## Implementation
Let's take a look on the code
Inside:
 - ```C
   typedef struct {
    char title[50];
} Song;
   ```
This struct is used to make a Song type, so the program can store a song title in one variable. 

```C
// Queue

Song queue[100];

int front = -1, rear = -1;
```
- `Song queue[100];` means this program stores up to 100 songs in order.
- `front` points to the first song in the queue.
- `rear` points to the last song in the queue.
Both start at -1, which means the queue is empty at the beginning.

```C
// Stack

Song stack[100];

int top = -1;
```
This part creates the history stack. `top = -1` means the stack is empty from the beginning. 

```C
// Enqueue

void enqueue(Song song_stack) {

if (rear == 99)

return;

if (front == -1)

front = 0;

queue[++rear] = song_stack;

}
```
This function adds a song to the end of the queue or put new song at the back of the playlist.
- `rear == 99` checks if the queue is full. If so, it will stop.
- `front == -1` means the queue is empty. If it is empty, it sets `front = 0` to start the queue.
- Then it moves `rear` one step and stores the new song there.

```C
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
```
This part of the code takes the first song form the queue. Firstly, it creates a default song value, `"None"` just in case there is no song available. Then it checks whether the queue is empty `(front == -1)`. If it is empty, the function immediately returns `"None"`.  If the queue has data, the function gets the song at the front position. After taking that song, it checks whether it was the last item in the queue. If it was the last one, both front and rear are reset to -1 to mark the queue as empty again. If not, front is moved one step forward. Finally, the function returns the removed song.

```C
void push(Song song_stack) { //Push

if (top == 99)

{

//printf("Full stack\n");

return;

}

stack[++top] = song_stack;

}
```

This function adds a song to the top of the history stack using push implementation
-  `if (top == 99)` checks if the stack is full
- `return;` if full the program stops and does nothing. 
- `stack[++top] = s;` if there is still space, it increases top by one and saves the new song at song_stack.
So, push means: store the latest played song into history.

```C
Song pop() {//Pop

Song song_stack = {"None"};

if (top == -1) return song_stack;

return stack[top--];

}
```

This is the function that removes and returns the most recent song from the history stack.
- First, it creates a default song value named `"None"`. 
- `if (top == -1) return song_stack;`Then, it checks if the stack is empty, if yes it will returns `"None"`.
- If the stack contains data it returns the song at the current top position. At the same time, it decreases top by 1 `return stack[top--];`. 

```C
int main() {

int option;

Song current;
```
Finally, the main function!
- `int option;` stores the menu choice the user enters (1, 2, 3, or 4).
- `Song current;` stores the song that is currently playing or being replayed.

```C
while (1) {

printf("\n=== Nel's Playlist ===\n");

printf("1. Add Song\n");

printf("2. Next\n");

printf("3. Prev\n");

printf("4. Exit\n");

printf("What's for today, Nel?: ");

scanf("%d", &option);
```
While loop for the user's input. `while (1)` means the loop runs forever. It will not stop unless the program returns (which happens when the user chooses option 4).

```C
switch (option) {

case 1: {

Song s;

printf("Song title: ");

scanf(" %[^\n]", s.title);

enqueue(s);

printf("Song added!\n");

break;

}
```
This is the "Add Song" feature. When the user chooses option 1, this code runs.
 - First, it creates a new song variable `Song s`. Then it asks the user to enter a song title with `printf("Song title: ").`
- `scanf(" %[^\n]", s.title)` reads the text the user types and stores it in s.title. The `%[^\n]` means "read everything until a newline (Enter key)".
- `Then enqueue(s)` adds the new song to the end of the playlist queue.
- `printf("Song added!\n")` confirms to the user that the song was added, and break exits the switch statement to go back to the menu.

```C
case 2:

current = dequeue();

if (strcmp(current.title, "None") == 0) {

printf("No songs available :(\n");

} else {

printf("Now Playing: %s\n", current.title);

push(current);

}

break;
```
This is the Play Next or the skip feature. 
- When user picks option 2, the program calls dequeue() to take the first song from the playlist queue and store it in current. 
- Then it checks `current.title.` If the value is `"None"`, it means the queue was empty, so it prints `“No songs available :(”.`
- If there is a song, it prints `“Now Playing: ...”` and then calls `push(current)` to save that song into the history stack, so it can be replayed later with option 3.

```C
case 3:

current = pop();

if (strcmp(current.title, "None") == 0) {

printf("No song to replay :(\n");

} else {

printf("Replaying: %s\n", current.title);

}

break;
```
This is the Replay button! When the user chooses option 3, the program calls `(pop)` to take the most recent song from the history stack and store in the `current`.
- `if (strcmp(current.title, "None") == 0) {` it checks current.title. If it is "None", the stack was empty, so there is no song to replay.
- `else {printf("Replaying: %s\n", current.title);` the program will display the output if the song title is saved in the stack. 

```C
case 4:

printf("Thanks for listening, Nel! Have a pleasant day!\n");

return 0;
```
This is the Exit feature! When the user chooses option 4, the program prints a goodbye message, then return 0; immediately ends the program.

```C
default:

printf("Error. Invalid option.\n");

break;
```
This default block runs when the user enters a number that is not in cases 1-4. It prints `"Error. Invalid option."`

```C
return 0;

}
```
The program ends successfully.

## How to Run
1. Run in your terminal
   ![Terminal Start](assets/Pasted%20image%2020260324215709.png)
	
2. Add song to playlist
   ![Add Song](assets/Pasted%20image%2020260324215943.png)
   
3. Keep adding!
   ![Keep adding](assets/Pasted%20image%2020260324220737.png)
   
4. Since you don't have anything played in your playlist, if u press 2:
   ![Empty Queue](assets/Pasted%20image%2020260324221123.png)
   
   And if u press 3:
   ![Empty Stack](assets/Pasted%20image%2020260324221207.png)
   
5. After pressing 2, you are currently listening to "No Batidao". you can press 2 to listen to "Ambatakam Ambashing".
   ![Play Next](assets/Pasted%20image%2020260324222006.png)
   
6. Now, for the replay feature
   ![Replay feature](assets/Pasted%20image%2020260324222056.png)
   
   As you can see here, if u pick 3 once, it will replay the currently played song. Just like how irl replay button works! If u chose 3 again, it will play to the previous song.
   
7. Finish listening? Pick option 4 to exit.
   ![Exit program](assets/Pasted%20image%2020260324222708.png)

## Demonstration 
[Watch the Demonstration Video Here](https://drive.google.com/file/d/1PKWWcdX5mGecjfOf4YFzmPV_3R9bx4bj/view?usp=sharing)
