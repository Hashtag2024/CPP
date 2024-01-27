#include<iostream>
using namespace std;

class insertion_sort {
    public:
        int i, j, n, a[100], key;

        void get_size() {
            cout << "Enter array size: ";
            cin >> n;
        }

        void get_elem() {
            cout << "Enter elements: ";
            for(i = 0; i < n; i++) {
                cin >> a[i];
            }
        }

        void disp_elem() {
            cout << "Entered elements are as follows: ";
            for(i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }

        void sort_array() {
            for(i = 1; i < n; i++) {
                key = a[i];
                j = i - 1;

                while (j >= 0 && a[j] > key) {
                    a[j + 1] = a[j];
                    j = j - 1;
                }
                a[j + 1] = key;
            }

            cout << "Sorted array: ";
            for(i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    insertion_sort obj;
    obj.get_size();
    obj.get_elem();
    obj.disp_elem();
    obj.sort_array();
    return 0;
}

