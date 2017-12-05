#include "sorts.h"
lab6::node *partition(lab6::node *start, lab6::node *end );
void quicksort(lab6::node *start,lab6::node *end);
int getMax(lab6::node *temp)
{
    unsigned max;
    max = temp->data;
    temp = temp->next;
    while(temp!= nullptr)
    {
        if(max<temp->data)
            max = temp->data;
        temp = temp->next;
    }
    int return_value=0;
    for(int x=1;(max/x) != 0;x*=10)
    {
        return_value++;
    }
    return return_value;
}
lab6::doubly_linked_list sorts::radix_sort(lab6::doubly_linked_list input) {
    lab6::doubly_linked_list working_list = input;
    lab6:: node *listPtr;
    int m=10;
    int n=1;
    int var;
    int max = getMax(working_list.get_head());
    for(int i=0;i<max;i++)
    {
        lab6::doubly_linked_list *tempList;
        tempList = new lab6::doubly_linked_list[10];
        listPtr = working_list.get_head();
        while(listPtr!= nullptr)
        {
            var = listPtr->data%m;
            var = var/n;
            switch(var)
            {
                case 0:tempList[0].append(listPtr->data);
                    break;
                case 1:tempList[1].append(listPtr->data);
                    break;
                case 2:tempList[2].append(listPtr->data);
                    break;
                case 3:tempList[3].append(listPtr->data);
                    break;
                case 4:tempList[4].append(listPtr->data);
                    break;
                case 5:tempList[5].append(listPtr->data);
                    break;
                case 6:tempList[6].append(listPtr->data);
                    break;
                case 7:tempList[7].append(listPtr->data);
                    break;
                case 8:tempList[8].append(listPtr->data);
                    break;
                case 9:tempList[9].append(listPtr->data);
                    break;
            }
            listPtr = listPtr->next;
        }
        while(!working_list.is_empty())
            working_list.remove(0);
        lab6::node *temp;
        for(int i=0;i<10;i++){
            temp = tempList[i].get_head();
            while(temp!= nullptr){
                working_list.append(temp->data);
                temp = temp->next;
            }
        }
        m = m*10;
        n = n*10;
        for(int i=0;i<10;i++) {

            while (!tempList[i].is_empty()) {
                tempList[i].remove(0);
            }
        }

    }



    return working_list;
}

lab6::doubly_linked_list sorts::insertion_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    lab6::node *current,*insertionPointer;
    unsigned key;
    current = working_list.get_head();
    insertionPointer = current->next;
    key = insertionPointer->data;
    for(int i=0;(i<iterations)&&insertionPointer!= nullptr;i++)
    {
        if(key<current->data)
        {
            lab6::node *temporary;
            temporary = current;
            //swap till ok
            do{
                if(temporary->data<key)
                    break;
                else
                {
                    unsigned temp;
                    temp = insertionPointer->data;
                    insertionPointer->data = temporary->data;
                    temporary->data = temp;
                }
                temporary = temporary->prev;
                insertionPointer = insertionPointer->prev;
            }while(temporary!= nullptr);
        }
        current = current->next;
        insertionPointer = current->next;
        if(insertionPointer!= nullptr)
            key = insertionPointer->data;
    }
    return working_list;
}

lab6::doubly_linked_list sorts::selection_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    lab6::node *current,*minimum,*temp;
    minimum = working_list.get_head();
    temp = working_list.get_head();
    current = temp->next;

    for(int i=0;(i<iterations)  && (current != nullptr);i++)
    {

        do{
            if(minimum->data>current->data)
                minimum = current;
            current = current->next;

        }while(current!= nullptr);
        unsigned swap_var = temp->data;
        temp->data = minimum->data;
        minimum->data = swap_var;
        temp = temp->next;
        current = temp->next;
        minimum = temp;
    }
    return working_list;
}

lab6::doubly_linked_list sorts::cocktail_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    lab6::node *current,*current_next,*current_prev;
    current = working_list.get_head();
    current_next = current->next;
    for(int i=0;(i<iterations)  && (current_next != nullptr);i++)
    {
        do
        {
            if(current->data > current_next->data)
            {
                unsigned temp;
                temp = current->data;
                current->data = current_next->data;
                current_next->data = temp;
            }
            current = current->next;
            current_next = current_next->next;
        }while(current_next != nullptr);

        current = working_list.get_tail();
        current = current->prev;
        current_prev = current->prev;
        do{
            if(current->data < current_prev->data)
            {
                unsigned temp;
                temp = current->data;
                current->data = current_prev->data;
                current_prev->data = temp;
            }
            current = current->prev;
            current_prev = current->prev;
        }while(current_prev!= nullptr);
        current = working_list.get_head();
        current_next = current->next;


    }


    return working_list;
}

lab6::doubly_linked_list sorts::bubble_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    lab6::node *current,*current_next;
    current = working_list.get_head();
    current_next = current->next;

    for(int i=0;(i<iterations)  && (current_next != nullptr);i++)
    {
        do
        {
            if(current->data > current_next->data)
            {
                unsigned temp;
                temp = current->data;
                current->data = current_next->data;
                current_next->data = temp;
            }
            current = current->next;
            current_next = current_next->next;
        }while(current_next != nullptr);
        current = working_list.get_head();
        current_next = current->next;

    }
    return working_list;
}

lab6::doubly_linked_list sorts::merge_sort(lab6::doubly_linked_list input) {
    lab6::doubly_linked_list second_list = input;
    lab6::doubly_linked_list first_list;
    first_list = second_list.split_after(second_list.get_size()/2);
    sorts temp;
    first_list = temp.bubble_sort(first_list,first_list.get_size());
    second_list = temp.bubble_sort(second_list,second_list.get_size());
    lab6::doubly_linked_list working_list;
    lab6::node *list1,*list2;
    list1 = first_list.get_head();
    list2 = second_list.get_head();

    while(list1!= nullptr)
    {
        while(list2 != nullptr)
        {
            if(list1->data < list2->data)
            {
                working_list.append(list1->data);
                list1 = list1->next;
            }
            else
            {
                working_list.append(list2->data);
                list2 = list2->next;
            }
            if(list1 == nullptr && list2 != nullptr)
            {
                while(list2!= nullptr)
                {
                    working_list.append(list2->data);
                    list2 = list2->next;
                }
                break;
            }

        }
        if(list2 == nullptr)
            break;
    }
    if(list1!= nullptr && list2 == nullptr)
    {
        while(list1 != nullptr)
        {
            working_list.append(list1->data);
            list1 = list1->next;
        }
    }
    return working_list;
}



lab6::doubly_linked_list sorts::quick_sort(lab6::doubly_linked_list input) {

    lab6::doubly_linked_list working_list = input;
    quicksort(working_list.get_head(),working_list.get_tail());
    return working_list;
}

void quicksort(lab6::node *start,lab6::node *end)
{
    if(start == end || start == nullptr || end == nullptr)
        return;
    lab6:: node *pIndex;
    pIndex = partition(start,end);
    if(pIndex== nullptr)
        return;
    if(pIndex!=start)
        quicksort(start,pIndex->prev);
    if(pIndex!=end)
        quicksort(pIndex->next,end);
}
lab6::node *partition(lab6::node *start, lab6::node *end)
{
    lab6::node *pivot;
    pivot = end;
    lab6::node *pIndex = start;
    lab6::node *i=start;
    for(;i!=end && i!= pivot;i = i->next)
    {
        if(i->data <= pivot->data)
        {
            unsigned temp;
            temp = i->data;
            i->data = pIndex->data;
            pIndex->data = temp;
            pIndex = pIndex->next;
        }
    }
    if(pIndex!= nullptr)
    {
        unsigned temp;
        temp = pivot->data;
        pivot->data = pIndex->data;
        pIndex->data = temp;
    }

    return pIndex;
}
