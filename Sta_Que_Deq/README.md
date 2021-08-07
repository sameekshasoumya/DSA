

STACKS --> LIFO : Last In First Out 

|  F+4   | ---> LAST IN,  FIRST TO GET OUT
|--------|
|  F+3   |
|--------|
|  F+2   |
|--------|
|  F+1   |
|--------|
|   F    |
|--------|

Time Complexities : 
1. s.top() --> O(1)
2. s.push() -> O(1)
3. s.pop() --> O(1)


----------------------------------------------------------------------------------------------------------------------------------------------


QUEUE --> FIFO : First In First Out

                                       ---------------------------------------
        DELETIONS FROM THIS END <--    |  F  |  F+1  |  F+2  |  F+3  |  F+4  |      --> LAST IN, LAST ONE TO GET OUT
           FRONT END                   ---------------------------------------      --> INSERTION FROM REAR END

Time Complexities : 
1. q.front() --> O(1)
2. q.push()  --> O(1) : By default push_back
3. q.pop()   --> O(1) : By default pop_front


----------------------------------------------------------------------------------------------------------------------------------------------


DEQUE --> Doubly Ended Queue
Deletions and insertions from both the ends
