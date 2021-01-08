/**
 * Tree.cpp : You can found here the Tree class.
 * Author : Mickael.
 * */

#ifndef Tree_HPP
#define Tree_HPP

#include <iostream>

#include "queue"
#include <string>

#include <cstdlib>
#include <ctime>

struct Data {
  int freq; 
  char car;
};

class Sommet
{
  friend class ArbreB;  // For used 'Sommet' in 'ArbreB' without 
                        // getters or setters

  private:
    /* Data */
    Data data;
    Sommet *left, *right; // Left child and right child

public:
    /* Constructors */
    Sommet(); // Default
    Sommet(const Sommet&); // Copy
    Sommet(int, char);
    Sommet(Data);

    /* Overloaded */
    Sommet& operator=(Sommet);
    Sommet& operator=(Data);
    bool operator==(const Sommet&);

    friend std::ostream &operator<<(std::ostream &, const Sommet&);
    
    /* Methodes */
    bool equalsData(Data);

    void Min(int*);
    int dataMin();

    void Max(int*);
    int dataMax();

    bool isLeaf();
    void printBeautifulTree(int);
    void writeBeautifulTreeInFile(int);
    Sommet* copy();
    bool equal(Sommet*);
    int countDepth();
    int countSize();

    /* Getters */
    Data getData() const;
    Sommet* getLeft() const;
    Sommet* getRight() const;

    /* Setters */
    void setLeft(Data leftData);
    void setRight(Data rightData);

    /* Destructor */
    ~Sommet();
};

class ArbreB
{
  private:
    /* Data */
    Sommet *root;

  public:
    /* Constructors */
    ArbreB(); //Default
    ArbreB(const ArbreB&);
    ArbreB(int, char);
    ArbreB(Data);

    /* Overloaded */
    ArbreB& operator=(const ArbreB&);
    bool operator==(const ArbreB&);
    
    ArbreB& operator<<(Data);
    ArbreB& operator>>(Data);
    Sommet* operator[](int);

    friend std::ostream &operator<<(std::ostream &flux, const ArbreB&);

    ArbreB& operator+=(const ArbreB&);
    ArbreB& operator-=(ArbreB&);

    /* Methodes */
    void add(Sommet*, Data);
    void dell(Sommet*, Data);
    Sommet* find(Sommet*, Data);

    /* Getters */
    Sommet* getRoot() const;
    Sommet* getRandLeaf(Sommet*) const;

    /* Destructor */
    ~ArbreB();
};

#endif
