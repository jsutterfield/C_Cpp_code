#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

int main()
{
    int myarray[ARRAY_SIZE] = {7, 8, 14, 4, 35, 
                               10, 17, 3, 40, 1};
    int smallest_index, smallest_value;

    // Print inititial array
    cout << "Unsorted Array: " << endl;
    cout << "{ ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << myarray[i];
        if (i != ARRAY_SIZE - 1)
            cout << ",";
        cout << " ";
    }
    cout << "}\n" << endl;


    // Sort array
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        smallest_index = i;
        smallest_value = myarray[i];
        for (int j = i + 1; j < ARRAY_SIZE; j++) 
            if (myarray[j] < smallest_value) {
                smallest_index = j;
                smallest_value = myarray[j];
            }
        if (smallest_index != i) {
            myarray[smallest_index] = myarray[i];
            myarray[i] = smallest_value;
        }

        // Print array on each iteration to show how it's being sorted
        cout << "{ ";
        for (int i = 0; i < ARRAY_SIZE; i++) {
            cout << myarray[i];
            if (i != ARRAY_SIZE - 1)
                cout << ",";
            cout << " ";
        }
        cout << "}" << endl;
    }

    cout << "FINISHED!" << endl;

    return 0;
}
