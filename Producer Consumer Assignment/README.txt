Programming Assignment #1
Operating Systems

This code includes producer.c and consumer.c which run simultaneosuly to simulate the producer consumer problem. 

Instructions to run the code:

$ gcc producer.c -pthread -lrt -o producer
$ gcc consumer.c -pthread -lrt -o consumer
$ ./producer & ./consumer &

The producer will generate items and put items onto the table. It will then pick up items.
The table can only hold two items at the same time.
When the table is complete, the producer will wait. When there are no items, the consumer will wait.
This assignment uses semaphores to synchronize producer and consumer considering mutual exlusion.
The table uses shared memory, and threads are used in both consumer.c and producer.c
