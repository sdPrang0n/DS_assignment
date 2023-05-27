// array insertion, deletion, searching, display, traverse, and update

#include <iostream>
using namespace std;

int main()
{
    int arr[10], size, i, num, pos, flag = 0, choice;
    cout << "Enter the size of an array: ";
    cin >> size;
    cout << "Enter the elements of an array: ";
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "1. Insertion" << endl;
    cout << "2. Deletion" << endl;
    cout << "3. Searching" << endl;
    cout << "4. Display" << endl;
    cout << "5. Update" << endl;
    cout << "Enter the choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter the element to be inserted: ";
        cin >> num;
        cout << "Enter the position of the element: ";
        cin >> pos;
        for (i = size - 1; i >= pos - 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = num;
        size++;
        cout << "The new array is: ";
        for (i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        break;
    case 2:
        cout << "Enter the position of the element to be deleted: ";
        cin >> pos;
        num = arr[pos - 1];
        for (i = pos - 1; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "The new array is: ";
        for (i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        break;
    case 3:
        cout << "Enter the element to be searched: ";
        cin >> num;
        for (i = 0; i < size; i++)
        {
            if (arr[i] == num)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "The element is found at position " << i + 1;
        }
        else
        {
            cout << "The element is not found";
        }
        break;
    case 4:
        cout << "The array is: ";
        for (i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        break;
    case 5:
        cout << "Enter the position of the element to be updated: ";
        cin >> pos;
        cout << "Enter the new element: ";
        cin >> num;
        arr[pos - 1] = num;
        cout << "The new array is: ";
        for (i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        break;
    default:
        cout << "Invalid choice";
    }
    return 0;
}
