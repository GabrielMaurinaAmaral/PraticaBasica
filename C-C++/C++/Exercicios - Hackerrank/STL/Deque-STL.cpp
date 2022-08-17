#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k)
{

}

int main()
{
    int size;
    cin >> size;
  
    while (size > 0)
    {
        int tam, sub_tam;
        cin >> tam >> sub_tam;

        int arr[tam];
  
        for (int i = 0; i < tam; i++)
            cin >> arr[i];
  
        printKMax(arr, tam, sub_tam);
        size--;
    }
    
    return 0;
}