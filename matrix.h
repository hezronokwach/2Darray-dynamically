#ifndef  MATRIX_H
#define  MATRIX_H

class Dimension{
    int r, c;//no of rows and columns
    int **a;//an array of pointers
    
    public:
        Dimension();
       ~Dimension();
        void product();
};

#endif