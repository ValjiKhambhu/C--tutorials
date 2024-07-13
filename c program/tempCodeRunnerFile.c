nt num;
    int ch;
    while(1){
       printf("\nFollowing are operations of Queue\n");
       printf("1. Enqueue\n");
       printf("2. Dequeue\n");
       printf("3. Show queue\n");
       printf("4. Exit\n");
       printf("Choose operation :");
       scanf("%d", &ch);
        
        switch(ch){
           case 1:
               printf("Enter a number in Queue : ");
               scanf("%d", &num);
                enqueue(num);
           break;
           case 2:
               num = dequeue();
               printf("Delement element is %d\n", queue[num]);
           break;
           case 3:
               showQueue();
           break;
            case 4:
               exit(0);
           break;
           default:
               printf("Please choose currect operation\n");
       }
   }