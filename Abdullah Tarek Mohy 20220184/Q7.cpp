#include <iostream>
#include <vector>

using namespace std;

struct domino {
    int leftDots;
    int rightDots;
};

bool vis[5];

vector<domino> ans;

bool FormsDominoChain(vector<domino> &dominos, int rightDots, int count);

int main() {
    int numDominos;
    cout << "Enter the number of dominos: ";
    cin >> numDominos;

    vector<domino> dominos(numDominos);           // Vector to store dominos entered by the user
    for (int i = 0; i < numDominos; i++) {                   
        cout << "Enter the left and right dots for domino " << i + 1 << ": ";
        cin >> dominos[i].leftDots >> dominos[i].rightDots;               // taking left and right dots for each domino
    }

    if (FormsDominoChain(dominos, 0, 0)) {               //  printing the arrangement if there is any
        cout << "Arrangement: \n";
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].leftDots << "|" << ans[i].rightDots << " ";
        }
    } else {
        cout << "No possible arrangement\n";
    }
    return 0;
}

bool FormsDominoChain(vector<domino> &dominos, int rightDots, int count) {       
    if (count == dominos.size()) {
        return true;                      // If all dominos are used, a valid chain is formed
    }

    bool result = false;
    for (int i = 0; i < dominos.size(); i++) {
        if ((dominos[i].leftDots == rightDots && !vis[i]) || count == 0) {      //adding dominos according to its ending and backtracking if no valid chain formed 
            ans.push_back(dominos[i]);
            vis[i] = true;
            result = FormsDominoChain(dominos, dominos[i].rightDots, count + 1);
            if (result)
                return true;
            vis[i] = false;
            ans.pop_back();
        }
    }
   
    return false;
}
