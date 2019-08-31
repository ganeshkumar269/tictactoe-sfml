#ifndef TICTACTOE_H
    #define TICTACTOE_H
    void prettyprint(int (*)[3]);
    void returnTranspose(int (*)[3],int (*)[3]);
    int isSame(int []);
    int returnRandom(int (*)[3]);
    int checkDiagnols(int (*)[3]);
    bool gameOver(int (*)[3]);
    int checkForTwo(int []);
    int returnOptimal(int (*)[3]);
    bool isFull(int (*)[3]);
#endif // TICTACTOE_H
