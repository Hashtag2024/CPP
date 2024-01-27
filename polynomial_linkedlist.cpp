#include<iostream>
using namespace std;

class polyll {
private:
    struct polynode {
        float coeff;
        int exp;
        polynode* link;
    };

    polynode* p;

public:
    polyll() {
        p = NULL;
    }

    void polyAppend(float c, int e) {
        polynode* temp = p;
        if (temp == NULL) {
            temp = new polynode;
            p = temp;
        } else {
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = new polynode;
            temp = temp->link;
        }

        temp->coeff = c;
        temp->exp = e;
        temp->link = NULL;
    }

    void displayPoly() {
        polynode* temp = p;
        while (temp != NULL) {
            if (temp->coeff > 0) {
                cout << " + ";
            }
            cout << temp->coeff;
            if (temp->exp > 0) {
                cout << "x^" << temp->exp;
            }
            temp = temp->link;
        }
        cout << endl;
    }

    void polyAdd(polyll& p1, polyll& p2) {
        polynode* temp1 = p1.p;
        polynode* temp2 = p2.p;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->exp > temp2->exp) {
                polyAppend(temp2->coeff, temp2->exp);
                temp2 = temp2->link;
            } else if (temp1->exp < temp2->exp) {
                polyAppend(temp1->coeff, temp1->exp);
                temp1 = temp1->link;
            } else {
                float sumCoeff = temp1->coeff + temp2->coeff;
                polyAppend(sumCoeff, temp1->exp);
                temp1 = temp1->link;
                temp2 = temp2->link;
            }
        }

        while (temp1 != NULL) {
            polyAppend(temp1->coeff, temp1->exp);
            temp1 = temp1->link;
        }

        while (temp2 != NULL) {
            polyAppend(temp2->coeff, temp2->exp);
            temp2 = temp2->link;
        }
    }
};

int main() {
    polyll p1;
    p1.polyAppend(1.4, 5);
    p1.polyAppend(5, 4);
    p1.polyAppend(7, 2);
    p1.polyAppend(1.8, 1);
    p1.polyAppend(1.9, 0);

    cout << "First polynomial: ";
    p1.displayPoly();

    polyll p2;
    p2.polyAppend(1.5, 6);
    p2.polyAppend(2, 5);
    p2.polyAppend(-3.5, 4);
    p2.polyAppend(4.3, 3);
    p2.polyAppend(6.5, 1);

    cout << "Second polynomial: ";
    p2.displayPoly();

    polyll result;
    result.polyAdd(p1, p2);

    cout << "Resultant polynomial: ";
    result.displayPoly();

    return 0;
}

