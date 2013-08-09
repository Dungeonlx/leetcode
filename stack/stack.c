#include <stdio.h>
#include <stdlib.h>

typedef struct stack_element {
    int data;
    struct stack_element *next;
} stack_element_t;

typedef struct {
    /* Return size */
    int (*size)();
    /* Access next element */
    void (*top)();
    /* Insert element */
    void (*push)();
    /* Remove top element */
    void (*pop)();
    void (*travel)();
} stack_t;

/* Construct */
stack_t *stack_init();
/* Destruct */
void stack_cleanup(stack_t *stack);

static int m_count = 0;
/* Begin && Current element */
static stack_element_t *m_begin_element = NULL;
static stack_element_t *m_current_element = NULL;

static int m_size();
static void m_top();
static void m_push(int data);
static void m_pop();
static void m_travel();
static void m_cleanup();

stack_t *stack_init() 
{
    stack_t *stack = malloc(sizeof(stack_t));
    
    if (stack == NULL) 
    {
        printf("%s fail to malloc\n", __PRETTY_FUNCTION__);
        return NULL;
    }
    stack->size = m_size;
    stack->top = m_top;
    stack->push = m_push;
    stack->pop = m_pop;
    stack->travel = m_travel;

    return stack;
}

static int m_size() 
{
    return m_count;
}

static void m_top() 
{

}

static void m_push(int data) 
{
    stack_element_t *tmp = malloc(sizeof(stack_element_t));
    
    if (tmp == NULL) 
        return;

    tmp->data = data;
    tmp->next = NULL;

    if (m_begin_element == NULL) 
        m_begin_element = tmp;
    else
        m_current_element->next = tmp;

    m_current_element = tmp;
    m_count++;
}

static void m_pop() 
{
    stack_element_t *tmp = NULL;

    if (m_begin_element == NULL || m_current_element == NULL) 
        return;

    tmp = m_begin_element;
    while (tmp) 
    {
        if (tmp->next == m_current_element) 
        {
            free(tmp->next);
            tmp->next = NULL;
            m_current_element = tmp;
            break;
        }
        tmp = tmp->next;
    }
}

static void m_travel() 
{
    stack_element_t *tmp = m_begin_element;

    while (tmp) 
    {
        printf("DEBUG: %d\n", tmp->data);
        tmp = tmp->next;
    }
}

static void m_cleanup() 
{
    stack_element_t *tmp = m_begin_element;

    while (tmp) 
    {
        free(tmp);
        tmp = tmp->next;
    }
    m_begin_element = NULL;
    m_current_element = NULL;
}

void stack_cleanup(stack_t *stack) 
{
    if (stack == NULL) 
        return;

    m_cleanup();
    stack->size = NULL;
    stack->top = NULL;
    stack->push = NULL;
    stack->pop = NULL;
    stack->travel = NULL;
    free(stack);
    stack = NULL;
}

int main(int argc, char *argv[]) 
{
    stack_t *stack = stack_init();
    int i;
    
    for (i = 0; i < 10; i++) 
    {
        stack->push(i);
    }
    printf("DEBUG: travel ......\n");
    stack->travel();
    printf("DEBUG: pop ......\n");
    stack->pop();
    printf("DEBUG: travel ......\n");
    stack->travel();
    printf("DEBUG: push ......\n");
    stack->push(66);
    printf("DEBUG: travel ......\n");
    stack->travel();
    stack_cleanup(stack);

    return 0;
}
