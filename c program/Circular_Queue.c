#include<stdio.h>
#include<stdlib.h>

struct Edge{
    int src;
    int dest;
};

struct array_list{
    struct Edge *ptr;
    int totalEdge;
};

void graphTraversal(struct array_list graph[], int s_vertex);

int queue[10];
int rear = -1;
int front = -1;
int size = 10;
int visitedArr[7];

int isFull(){
    if(rear == front-1 || (front == 0 && rear == size-1)){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }
    return 0;
}

void enqueue(int val){
    if(isFull()){
        printf("Queue is full\n");
    }
    else{
        if(front == -1){
            front = 0;
            rear = 0;
        }
        else if(rear == size-1)
            rear = 0;
        else
            rear++;
            
        queue[rear] = val;
        // printf("\nAdded element is %d\n", val);
    }
}

int dequeue(){
    int return_val = -1;
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    else{
        return_val = front;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
    }
    return return_val;
}

void showQueue(){
    int f = front;
    int r = rear;
    
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    else{
        while(!(f == r+1) && !(r == size-1 && f == 0)){
            printf("%d\t",queue[f]);
            
            if(f == size-1){
                f = 0;
            }
            else{
                f++;
            }
        }
    }
}

int main(){
//    int num;
//     int ch;
//     while(1){
//        printf("\nFollowing are operations of Queue\n");
//        printf("1. Enqueue\n");
//        printf("2. Dequeue\n");
//        printf("3. Show queue\n");
//        printf("4. Exit\n");
//        printf("Choose operation :");
//        scanf("%d", &ch);
        
//         switch(ch){
//            case 1:
//                printf("Enter a number in Queue : ");
//                scanf("%d", &num);
//                 enqueue(num);
//            break;
//            case 2:
//                num = dequeue();
//                printf("Delement element is %d\n", queue[num]);
//            break;
//            case 3:
//                showQueue();
//            break;
//             case 4:
//                exit(0);
//            break;
//            default:
//                printf("Please choose currect operation\n");
//        }
//    }

    // Following is loop to set all vertieces as an visited
    for(int i = 0; i < size; i++){
        visitedArr[i] = 0;
    }

    struct array_list graph[size];

    // Vertes 0 :
    graph[0].totalEdge = 2;
    graph[0].ptr = (struct Edge*) malloc (sizeof(struct Edge)*2);
    graph[0].ptr[0].src = 0;      //Edge 1
    graph[0].ptr[0].dest = 1;
    graph[0].ptr[1].src = 0;       // Edge 2
    graph[0].ptr[1].dest = 2;

    // printf("Size of ptr is %d\n", sizeof(graph[0].ptr));
    // printf("Size of ptr[0] is %d\n", sizeof(graph[0].ptr[0]));
    // printf("Size of ptr[1] is %d\n", sizeof(graph[0].ptr[1]));
    // printf("Size of graph is %d\n", sizeof(graph[0]));
    // printf("graph[0].ptr[0].src : %d\n", graph[0].ptr[0].src);
    // printf("graph[0].ptr[0].dest : %d\n", graph[0].ptr[0].dest);
    // printf("graph[0].ptr[1].src : %d\n", graph[0].ptr[1].src);
    // printf("graph[0].ptr[1].dest : %d\n", graph[0].ptr[1].dest);

    // Pointer is actually work like follows
    // printf("graph[0].ptr : %d\n", graph[0].ptr);
    // printf("(graph[0].ptr) + 0 : %d\n", (graph[0].ptr) + 0);
    // printf("(graph[0].ptr) + 1 : %d\n", (graph[0].ptr) + 1);
    // printf("((graph[0].ptr) + 1)->src : %d\n", ((graph[0].ptr) + 1)->src);
    // printf("((graph[0].ptr) + 1)->dest : %d\n", ((graph[0].ptr) + 1)->dest);

    // Vertes 1 :
    graph[1].totalEdge = 2;
    graph[1].ptr = (struct Edge*) malloc (sizeof(struct Edge)*2);
    graph[1].ptr[0].src = 1;      //Edge 1
    graph[1].ptr[0].dest = 0;
    graph[1].ptr[1].src = 1;       // Edge 2
    graph[1].ptr[1].dest = 3;
    
    // Vertes 2 :
    graph[2].totalEdge = 2;
    graph[2].ptr = (struct Edge*) malloc (sizeof(struct Edge)*2);
    graph[2].ptr[0].src = 2;      //Edge 1
    graph[2].ptr[0].dest = 0;
    graph[2].ptr[1].src = 2;       // Edge 2
    graph[2].ptr[1].dest = 4;

    // Vertes 3 :
    graph[3].totalEdge = 3;
    graph[3].ptr = (struct Edge*) malloc (sizeof(struct Edge)*3);
    graph[3].ptr[0].src = 3;      //Edge 1
    graph[3].ptr[0].dest = 1;
    graph[3].ptr[1].src = 3;       // Edge 2
    graph[3].ptr[1].dest = 4; 
    graph[3].ptr[2].src = 3;      //Edge 3
    graph[3].ptr[2].dest = 5; 
 
    // Vertes 4 :
    graph[4].totalEdge = 3;
    graph[4].ptr = (struct Edge*) malloc (sizeof(struct Edge)*3);
    graph[4].ptr[0].src = 4;      //Edge 1
    graph[4].ptr[0].dest = 2;
    graph[4].ptr[1].src = 4;       // Edge 2
    graph[4].ptr[1].dest = 3; 
    graph[4].ptr[2].src = 4;      //Edge 3
    graph[4].ptr[2].dest = 5; 

    // Vertes 5 :
    graph[5].totalEdge = 3;
    graph[5].ptr = (struct Edge*) malloc (sizeof(struct Edge)*3);
    graph[5].ptr[0].src = 5;      //Edge 1
    graph[5].ptr[0].dest = 3;
    graph[5].ptr[1].src = 5;       // Edge 2
    graph[5].ptr[1].dest = 4; 
    graph[5].ptr[2].src = 5;      //Edge 3
    graph[5].ptr[2].dest = 6; 

    // Vertes 6 :
    graph[6].totalEdge = 1;
    graph[6].ptr = (struct Edge*) malloc (sizeof(struct Edge));
    graph[6].ptr[0].src = 6;      //Edge 1
    graph[6].ptr[0].dest = 5;
 
    graphTraversal(graph, 6);
    return 0;
}

void graphTraversal(struct array_list graph[], int s_vertex){
    int i, vertex;
    enqueue(s_vertex);

    while(!(isEmpty())){
        vertex = dequeue();
        vertex = queue[vertex];
        if(visitedArr[vertex] == 0){
            printf("%d\t", vertex);
            visitedArr[vertex] = 1;
            for(i = 0; i < graph[vertex].totalEdge; i++){
                enqueue(graph[vertex].ptr[i].dest);
            }
        }
    }
}