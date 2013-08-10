#include <iostream>

template<typename T> 
class stack_element 
{
public:
    stack_element() :next(NULL) {}
    T data;
    stack_element<T>* next;
};

template<typename T> 
class stack 
{
public:
    stack() :m_size(0), m_begin_element(NULL), m_current_element(NULL), 
    m_top_element(NULL) {}

    ~stack() 
    {
        stack_element<T>* tmp = m_begin_element;                                     
                                                                                
        while (tmp)                                                                 
        {                                                                           
            delete tmp;                                                              
            tmp = tmp->next;                                                        
        }                                                                           
        
        m_begin_element = NULL;                                                     
        m_current_element = NULL;                                                   
        m_top_element = NULL;
    }

    int size() 
    {
        return m_size;
    }

    stack_element<T>* top() 
    {
        if (m_top_element == NULL)                                                  
            m_top_element = m_begin_element;                                        
        else                                                                        
            m_top_element = m_top_element->next;                                    
                                                                                
        return m_top_element;
    }

    void push(T data) 
    {
        stack_element<T>* tmp = new stack_element<T>();                     
                                                                                
        if (tmp == NULL)                                                            
            return;                                                                 
                                                                                
        tmp->data = data;                                                           
        tmp->next = NULL;                                                           
                                                                                
        if (m_begin_element == NULL)                                                
            m_begin_element = tmp;                                                  
        else                                                                        
            m_current_element->next = tmp;                                          
                                                                                
        m_current_element = tmp;                                                    
        m_size++;
    }

    void pop() 
    {
        stack_element<T>* tmp = NULL;                                                
                                                                                
        if (m_begin_element == NULL || m_current_element == NULL)                   
            return;                                                                 
                                                                                
        tmp = m_begin_element;                                                      
        while (tmp)                                                                 
        {                                                                           
            if (tmp->next == m_current_element)                                     
            {                                                                       
                delete tmp->next;                                                    
                tmp->next = NULL;                                                   
                m_current_element = tmp;                                            
                m_size--;                                                          
                break;                                                              
            }                                                                       
            tmp = tmp->next;                                                        
        }
    }

    void travel() 
    {
        stack_element<T>* tmp = m_begin_element;                                     
                                                                                
        while (tmp)                                                                 
        {                                                                           
            std::cout << tmp->data << '\t';
            tmp = tmp->next;                                                        
        }
        std::cout << std::endl;
    }

private:
    int m_size;
    stack_element<T>* m_begin_element;
    stack_element<T>* m_current_element;
    stack_element<T>* m_top_element;
};

int main(int argc, char* argv[]) 
{
    stack<int> stack_obj;
    int i;
    
    for (i = 0; i < 10; i++) 
    {
        stack_obj.push(i);
    }
    std::cout << "DEBUG: top " << stack_obj.top()->data << std::endl;
    std::cout << "DEBUG: top " << stack_obj.top()->data << std::endl;
    std::cout << "DEBUG: top " << stack_obj.top()->data << std::endl;
    std::cout << "DEBUG: travel" << std::endl;
    stack_obj.travel();
    std::cout << "DEBUG: pop" << std::endl;
    stack_obj.pop();
    std::cout << "DEBUG: travel" << std::endl;
    stack_obj.travel();
    std::cout << "DEBUG: push 66" << std::endl;
    stack_obj.push(66);
    std::cout << "DEBUG: travel" << std::endl;
    stack_obj.travel();

    return 0;
}
