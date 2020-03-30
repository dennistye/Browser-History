#pragma once
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>// std::next, std::prev

using namespace std;
using std::string;

struct Node
{
    Node * next;
    Node * prev;
    string url = "";
    size_t fsize = 0;
};

class BrowserHistory
{
public:
    BrowserHistory();
    void visitSite(string url, size_t filesize);
    void backButton();
    void forwardButton();
    void readFile(string fileName);
    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();
private:
    size_t length;
    string text;
    string temp_url;
    size_t temp_size;
    string url;
    
    Node * head;
    Node * tail;
    Node * curr;
};

BrowserHistory::BrowserHistory()
{
    length = 0;
    text = "";
    temp_url = "";
    temp_size = 0;
     
    curr = nullptr;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

void BrowserHistory::readFile(string fileName)
{
    ifstream myfile;
    
    myfile.open(fileName);
    
    while(myfile >> text)
    {
        if(text == "visit")
        {
            myfile >> text;
            temp_url = text;
            myfile >> text;
            temp_size = stoi(text);
            visitSite(temp_url,temp_size);
        }
        else if(text == "back")
        {
            backButton();
        }
        else if(text == "forward")
        {
            forwardButton();
        }
    }
    myfile.close();
}
 
void BrowserHistory::visitSite(string url, size_t filesize)
{
    Node * temp;
    temp = new Node;
    
    if(curr == tail->prev || curr == nullptr)
    {
        temp->url = url;
        temp->fsize = filesize;
    
        temp->prev = tail->prev;
        temp->next = tail;
        tail->prev->next = temp;
        tail->prev = temp;
        curr = temp;
    }
    else
    {
        temp->url = url;
        temp->fsize = filesize;
        
        tail->prev = curr;
        curr->next = tail;
        
        temp->prev = tail->prev;
        temp->next = tail;
        tail->prev->next = temp;
        tail->prev = temp;
        curr = temp;
    }
}

void BrowserHistory::backButton()
{
    if (curr->prev == head)
    {
        return;
    }
    else
    {
        curr = curr->prev;
    }
}

void BrowserHistory::forwardButton()
{
    if(curr->next == tail)
    {
        return;
    }
    else
    {
        curr = curr->next;
    }
}

string BrowserHistory::currentUrl()
{
    if (curr == nullptr)
    {
        return url;
    }
    else
    {
        return curr->url;
    }
}

size_t BrowserHistory::currentPageSize()
{
    return curr->fsize;
}

size_t BrowserHistory::getHistoryLength()
{
    Node * ptr;
    ptr = head;
    ptr = ptr->next;
    while(ptr != tail)
    {
        length++;
        ptr = ptr->next;
    }
    
    delete ptr;
    ptr = nullptr;
    
    return length;
}

