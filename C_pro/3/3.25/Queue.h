struct Queue_record;
typedef struct Queue_record *Queue;

int Isempty( Queue Q );
int IsFull( Queue Q );
Queue Create_queue( int MaxElement );
void Dispose_queue( Queue Q );
void Mkae_empty( Queue Q );
void Enqueue( ElementType X,Queue Q );
Element_type Front( Queue Q );
void Dequeue( Queue Q );
Element_type Front_and_Dequeue( Queue Q );



#define MinQueueSize (5)

struct Queue_record{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    Element_type *array;
}
