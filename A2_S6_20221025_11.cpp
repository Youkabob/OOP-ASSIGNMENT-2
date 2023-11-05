/*
 File: A2_S6_20221025_11.cpp
 Purpose: file comparison
 Author: alaa wael mohamed
 Section: s6
 ID: 20221025
 TA: Nardeen Mokhless Khela - Maya Ahmed
 Date: 12 Oct 2023
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int choose;
    cout << "Choose between 1 and 2\n" << "1)Character by Character \n" << "2)Word by Word \n";
    cin >> choose;
    cin.ignore();
    string file1, file2;
    cout << "enter the name of the first file you want to compare >>";
    cin >> file1;
    cout << "enter the name of the second file you want to compare >>";
    cin >> file2;
    ifstream myfile1;
    myfile1.open(file1);
    ifstream myfile2;
    myfile2.open(file2);

    if (!myfile1.is_open() || !myfile2.is_open()) {
        cout << "files not open\n";
        return 0;
    }
    if (choose == 1) {

        char c1, c2;
        int line = 0, pos = 0;
        myfile1.get(c1);
        myfile2.get(c2);
        int error = 0;
        while (!myfile1.eof() && !myfile2.eof()) {
            pos++;

            if (c1 == '\n' && c2 == '\n') {
                line++;
                pos = 0;
            }

            if (c1 != c2) {
                error += 1;
                printf( "Line number : ");
                printf("%d\n",line );
                printf( "Position : " );
                printf("%d\n", pos);
                printf( "Difference: " );
                cout<< c2<< endl;
                break;
            }
            myfile1.get(c1);
            myfile2.get(c2);
        }
        if (error == 0) cout << "files are identical :)";
        myfile1.close();
        myfile2.close();

    } else {

        int line = 0;

        bool error = 0;
        string line1, line2, word1, word2;
        istringstream iss1, iss2;

        while (!myfile1.eof() && !myfile2.eof()) {
            //hold the line in a string from the first and second file
            getline(myfile1, line1);
            getline(myfile2, line2);

            line++;//count the number of lines;

            if (myfile1.good()) {
                //clear the previous state of the var
                iss1.clear();
                iss2.clear();
                iss1.str(line1);
                iss2.str(line2);

                while (iss1.good() && iss2.good()) {
                    //compare them word by word
                    iss1 >> word1;
                    iss2 >> word2;

                    if (word1 != word2) {
                        error = 1;
                        cout << "Line number : " << line << "\n" << "Difference: " << word2 << endl;
                        break;
                    }
                }
                if (error) break;
            }


        }
        if (!error) cout << "files are identical :)";
        myfile1.close();
        myfile2.close();
    }
}
