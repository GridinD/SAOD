#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
    node *head = NULL;

} Node;

void push(Node **head, int data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node **head)
{
    Node *prev = NULL;
    int val;
    if (head == NULL)
    {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*haed) = (*head)->next;
    free(prev);
    return val;
}

Node *getNht(Node *head, int n)
{
    int counter = 0;
    while (counter < n && head)
    {
        head = head->next;
        counter++;
    }
    return head;
}

Node *getLast(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

void pushBack(Node *head, int value)
{
    Node *last = getLast(head);
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    tmp->next = tmp;
}

Node *getLastButOne(Node *head)
{
    if (head == NULL)
    {
        exit(-2);
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    while (head->next->next)
    {
        head = head->next;
    }
    return head;
}

void popBack(Node **head)
{
    Node *lastbn = NULL;
    if (!head)
    {
        exit(-1);
    }
    if (!(*head))
    {
        exit(-1);
    }
    lastbn = getLastButOne(*head);
    if (lastbn == NULL)
    {
        free(*head);
        *head == NULL;
    }
    else
    {
        free(lastbn->next);
        lastbn->next = NULL;
    }
}

void insert(Node *head, unsigned n; int val)
{
    unsigned i = 0;
    Node *tmp = NULL;
    while (i < n && head->next)
    {
        head = head->next;
        i++;
    }
    tmp = (Node *)malloc(sizeof(Node));
    tmp->value = val;
    if (head->next)
    {
        tmp->next = head->next;
    }
    else
        (
            tmp->next = NULL;)
            head->next = tmp;
}

int deleteNth(Node **head, int n)
{
    if (n == 0)
    {
        return pop(head);
    }
    else
    {
        Node *prev = getNth(*head, n - 1);
        Node *elm = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        fgee(elm);
        return val;
    }
}

void deleteList(Node **head)(
    while ((*head)->next) {
        pop(head);
        *head = (*head)->next;
    } free(*head);)

    void fromArray(Node **head, int *arr, size_t size)
{
    size_t i = size - 1;
    if (arr == NULL || size == 0)
    {
        return;
    }
    do
    {
        push(head, arr[i]);
    } while (i-- != 0);
}

int *toArray(const Node *head)
{
    int leng = lendth(head);
    int *values = (int *)malloc(leng * sizeof(int));
    while (head)
    {
        values[--leng] = head->value;
        head = head->next;
    }
    return values;
}

void printLinkedList(const Node *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //Создаём список из массива
    fromArray(&head, arr, 10);

    printLinkedList(head);

    //Вставляем узел со значением 333 после 4-го элемента (станет пятым)
    insert(head, 4, 333);
    printLinkedList(head);

    pushBack(head, 11);
    pushBack(head, 12);
    pushBack(head, 13);
    pushBack(head, 14);
    printLinkedList(head);

    printf("%d\n", pop(&head));
    printf("%d\n", popBack(&head));

    printLinkedList(head);
    //Удаляем пятый элемент (индексация с нуля)
    deleteNth(&head, 4);
    printLinkedList(head);
    deleteList(&head);

    getch();
}
