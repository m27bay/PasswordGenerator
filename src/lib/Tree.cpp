/**
 * Tree.cpp : You can found here all functions implemented for the Tree class.
 * Author : Mickael.
 * */
#include "Tree.hpp"

/**
 * *Description : Create an object 'Sommet' with default parameters.
 * *Function : Constructor by default.
 * */
Sommet::Sommet() {
    data.freq = 0;
    data.car = '\0';
    left = nullptr;
    right = nullptr;
}

/**
 * *Description : Create an object 'ArbreB' with default parameters.
 * *Function : Constructor by default.
 * */
ArbreB::ArbreB() : root(nullptr)  {}

/**
 * *Description : Return a deep copy of the current object.
 * *Function : Copy.
 * */
Sommet* Sommet::copy() {
    Sommet *newNode = new Sommet(data);
    if(left) {
        newNode->left = left->copy();
    }
    if(right) {
        newNode->right = right->copy();
    }
    return newNode;
}

/**
 * *Description : Create an object 'Sommet' with another.
 * *Function : Constructor by copy.
 * @param other, the other node for the copy.
 * */
Sommet::Sommet(const Sommet& other) {
    data = other.data;
    left = nullptr;
    if(other.left) {
        left = other.left->copy();
    }
    right = nullptr;
    if(other.right) {
        right = other.right->copy();
    }
}

/**
 * *Description : Create an object 'ArbreB' with another.
 * *Function : Constructor by copy.
 * @param other, the other tree for the copy.
 * */
ArbreB::ArbreB(const ArbreB& other) {
    root = new Sommet;
    *root = *other.root;
}

/**
 * *Description : Create an object 'Sommet' by initializing the data.
 * *Function : Constructor with parameter.
 * @param newData, the data to init the node.
 * @param newCar, the car to init the node.
 * */
Sommet::Sommet(int newData, char newCar) {
    data.freq = newData;
    data.car = newCar;
    left = nullptr;
    right = nullptr;
}

/**
 * *Description : Create an object 'Sommet' by initializing the data.
 * *Function : Constructor with parameter.
 * @param newData, the data to init the node.
 * */
Sommet::Sommet(Data newData) : data(newData), left(nullptr), right(nullptr) {}

/**
 * *Description : Create an object 'ArbreB' by initializing the root.
 * *Function : Constructor with parameter.
 * @param freqRoot, tha data to init the root of the tree.
 * @param charRoot, tha car to init the root of the tree.
 * */
ArbreB::ArbreB(int freqRoot, char charRoot) {
    root = new Sommet(freqRoot, charRoot);
}

/**
 * *Description : Create an object 'ArbreB' by initializint the root.
 * *Function : constructor with parameter.
 * @param newData, the data(freq and car) to init the root.
 * */
ArbreB::ArbreB(Data newData) {
    root = new Sommet(newData);
}

/**
 * *Description : Copy an object 'Sommet' with another.
 * *Function : Overloading operator=.
 * @param other, the node for the copy.
 * */
Sommet& Sommet::operator=(Sommet other) {
    if(this != &other) {
        data = other.data;
        if(other.left) {
            left = other.left->copy();
        }
        if(other.right) {
            right = other.right->copy();
        }
    }
    return *this;
}

/**
 * *Description : Swap the value of the 'Sommet' with newData.
 * *Function : Overloading operator=.
 * @param newData, the data for swap.
 * */
Sommet& Sommet::operator=(Data newData) {
    data = newData;
    return *this;
}

/**
 * *Description : Copy an object 'ArbreB' with another.
 * *Function : Overloading operator=.
 * @param other, the other tree for the copy.
 * */
ArbreB& ArbreB::operator=(const ArbreB& other) {
    if(this != &other) {
        if(!root) {
            root = new Sommet(other.root->data);
        }
        *root = *other.root;
    }
    return *this;
}

/**
 * *Description : Say if the 'Sommet' is equal to another.
 * *Function : Overloading operator==.
 * @param other, the other node for compare.
 * @return boolean, true if this and other are equals, else false.
 * */
bool Sommet::operator==(const Sommet& other) {
    if(data.freq == other.data.freq && data.car == other.data.car) {
        if(left && other.left) {
            if(!left->equal(other.left)) {
                return false;
            }
        }
        if(right && other.right) {
            return right->equal(other.right);
        }
        if(!left && !right) {
            return true;
        }
    }
    return false;
}

/**
 * *Description : Say if the 'Sommet' is equal to another, recursive version.
 * *Function : Overloading operator==.
 * @param node, the other node for compare.
 * @return boolean, true if this and other are equals, else false.
 * */
bool Sommet::equal(Sommet *node) {
    if(node) {
        if(data.freq != node->data.freq || data.car != node->data.car) {
            return false;
        }
        if(left && node->left) {
            if(!left->equal(node->left)) {
                return false;
            }
        }
        if(right && node->right) {
            return right->equal(node->right);
        }
    }
    return true;
}

/**
 * *Description : Say if the 'ArbreB' is equal to another.
 * *Function : Overloading operator==.
 * @param other, the other tree for compare.
 * @return boolean, true if this and other are equals, else false.
 * */
bool ArbreB::operator==(const ArbreB& other) {
    // Two empty trees is always equal
    if(!root && !other.root) { 
        return true;
    }
    if((!root && other.root) || (root && !other.root)) {
        return false;
    }
    
    // Use operator== for 'Sommet'
    return *root == *other.root;
}

/**
 * *Description : Add a node with the value newData in the tree.
 * *Function : Overloading operator<<.
 * @param newData, the value to add in the tree.
 * */
ArbreB& ArbreB::operator<<(Data newData) {
    if(!root) {
        root = new Sommet(newData);
    }
    else {
        // Call recursive function
        add(root, newData); 
    }
    return *this;
}

/** 
 * *Description : Add a node with the value newData in the tree,
 *                  *recursive version.
 * @param node, for recursive call,
 * @param newData, the value to add.
 * */
void ArbreB::add(Sommet *root, Data newData) {
    // Add randomly the new root 
    if(rand()%2) { 
        if(root->left) {
            add(root->left, newData);
        }
        else {
            root->left = new Sommet(newData);
        }
    }
    else {
        if(root->right) {
            add(root->right, newData);
        }
        else {
            root->right = new Sommet(newData);
        }
    }
}

/**
 * *Description : Dell a node with the value dellData in the tree, if
 *                  *the node with dellData exist.
 * *Function : Overloading operator>>.
 * @param dellData, data need to be deleted.
 * */
ArbreB& ArbreB::operator>>(Data dellData) {
    Sommet *dellNode = find(root, dellData);
    
    // If haven't root or the value dellData wasen't found
    if(!dellNode || !root) {
        return *this;
    }
    if(root->data.freq == dellData.freq && root->data.car == dellData.car) {
        
        // Delete the root
        if(root->isLeaf()) {
            delete root;
            root = nullptr;
        }
        else { // Swap the root with a random leaf
            Sommet *randLeaf = getRandLeaf(root);
            Data swap = randLeaf->data;
            randLeaf->data = root->data;
            root->data = swap;

            dell(root, dellData);
        }
        return *this;
    }

    dell(root, dellData);
    return *this;
}

/**
 * *Description : Delete a node with the value dellData in the tree, if
 *                  *the node with dellData exists, recursive version.
 * @param root, node used for recursive call,
 * @param dellData, data need to be deleted.
 * */
void ArbreB::dell(Sommet *root, Data dellData) {
    if(!root) {
        return;
    }
    if(root->left) {
        if(root->left->data.freq == dellData.freq && root->left->data.car == dellData.car) {
            if(root->left->isLeaf()) { // Delete the left child
                delete root->left;
                root->left = nullptr;
                return;
            }
        //   else{
        //     Sommet *randLeaf = getRandLeaf(root->left);
        //     int swap = randLeaf->data;
        //     randLeaf->data = root->left->data;
        //     root->left->data = swap;

        //     dell(root->left, dellData);
        //   }
        }
        // else {
        //   dell(root->left, dellData);
        // }
    }
    if(root->right) {
        if(root->right->data.freq == dellData.freq && root->right->data.car == dellData.car) {
            if(root->right->isLeaf()) { // Delete the right child
                delete root->right;
                root->right = nullptr;
                return;
            }
        // else{
        //   Sommet *randLeaf = getRandLeaf(root->right);
        //   int swap = randLeaf->data;
        //   randLeaf->data = root->right->data;
        //   root->right->data = swap;

        //   dell(root->right, dellData);
        // }
        }
        // else {
        //   dell(root->right, dellData);
        // }
    }
}


/**
 * *Description : Print the node recursively.
 * *Function : Overloading operator<<.
 * @param flux, where we write.
 * @param node, we print.
 * */
std::ostream &operator<<(std::ostream &flux, const Sommet& node) {
    flux << "(" << node.data.car << ", " << node.data.freq << "), ";
    if(node.left) {
        flux << *node.left;
    }
    if(node.right) {
        flux << *node.right;
    }
    return flux;
}

/**
 * *Description : Print the tree.
 * *Function : Overloading operator<<.
 * @param flux, where we write,
 * @param tree, we print.
 * */
std::ostream &operator<<(std::ostream &flux, const ArbreB& tree) {
    if(tree.root) {
        flux << *tree.root;
    }
    return flux;
}

/**
 * *Description : Merge two trees.
 * *Function : Overloading operator+=.
 * @param other, to merge two trees.
 * */
ArbreB& ArbreB::operator+=(const ArbreB& other) {
    Sommet *cpyOther = other.root->copy();
    
    Data newRootData;
    newRootData.freq = root->data.freq + cpyOther->data.freq;
    newRootData.car = '\0';
    Sommet *newRoot = new Sommet(newRootData);
    newRoot->left = root;
    newRoot->right = cpyOther;

    root = newRoot;
    return *this;
}

/**
 * *Description : Split two trees.
 * *Function : Overloading operator-=.
 * @param other, for split two trees.
 * */
ArbreB& ArbreB::operator-=(ArbreB& other) {
    if(root && root->left && root->right) {
        // Assing right tree to other.
        other.root = root->right;
        
        Sommet *oldRoot = root;
        root = root->left; // Assign left tree to this;
        oldRoot->left = oldRoot->right = nullptr;
        
        delete oldRoot;
    }
    return *this;
}

/**
 * *Description : Get a precise node in the tree.
 * *Function : Overloading operator[].
 * @param index, the position of the node in the tree we need to get.
 * */
Sommet* ArbreB::operator[](int index) {
    index--;

    if(index < 0 || index >= root->countSize()) { // ! Error if index out of band.
        std::cout << "ERROR : index out of band" << std::endl;
        return nullptr;
    }
    else if(index == 0) {
        return root;
    }

    // Breadth First Search (BFS)
    int posNodeInTree = 0;
    std::queue<Sommet*> queue;
    queue.push(root);
    Sommet* start;
    posNodeInTree++;

    while(!queue.empty()) {
        start = queue.front();
        queue.pop();
        
        if(start->left) {
            if(index == posNodeInTree) {
                return start->left;
            }
            posNodeInTree++;
            
            queue.push(start->left);
        }

        if(start->right) {
            if(index == posNodeInTree) {
                return start->right;
            }
            posNodeInTree++;

            queue.push(start->right);
        }
    }

    return nullptr;
}

/**
 * *Description : Split two trees.
 * @param root, for recursive call.
 * @param dataSearch, the value we want to find.
 * */
Sommet* ArbreB::find(Sommet* root, Data dataSearch) {
    if(root) {
        if(root->data.freq == dataSearch.freq && root->data.car == dataSearch.car) {
            return root;
        }
        if(root->left) { // If we find at the left.
            Sommet* ret = find(root->left, dataSearch);
            if(ret) {
                return ret; // Don't need to search at the right, return answer.
            }
        }
        if(root->right) {
            return find(root->right, dataSearch);
        }
    }

    return nullptr;
}

/* Getters */
Data Sommet::getData() const {
    return data;
}

Sommet* Sommet::getLeft() const {
    return left;
}

Sommet* Sommet::getRight() const {
    return right;
}

Sommet* ArbreB::getRoot() const {
    return root;
}

Sommet* ArbreB::getRandLeaf(Sommet* root) const{
    if(!root) {
        return nullptr;
    }
    if(root->isLeaf()) {
        return root;
    }
    if(root->left) {
        return getRandLeaf(root->left);
    }
    if(root->right) {
        return getRandLeaf(root->right);
    }

    return nullptr;
}
/* End getters */

/* Setters */
void Sommet::setLeft(Data leftData) {
    if(left) {
        left->data.freq = leftData.freq;
        left->data.car = leftData.car;
    }
    else {
        left = new Sommet(leftData);
    }
}

void Sommet::setRight(Data rightData) {
    if(right) {
        right->data.freq = rightData.freq;
        right->data.car = rightData.car;
    }
    else {
        right = new Sommet(rightData);
    }
}
/* End setters */

/* Methodes */
bool Sommet::equalsData(Data other) {
    return ((data.freq == other.freq)
        && (data.car == other.car));
}

/**
 * *Description : Found the minimum value in the tree, recursive version.
 * @param min, the minimum of the tree.
 * */
void Sommet::Min(int *min) {
    if(data.freq <= *min) {
        *min = data.freq;
    }
    if(left) {
        left->Min(min);
    }
    if(right) {
        right->Min(min);
    }
}

/**
 * *Description : Found the minimum value in the tree.
 * @return the minimum of the tree.
 * */
int Sommet::dataMin() {
    int min = INT32_MAX; // Init min with the max value for int
    Min(&min);
    return min;
}

/**
 * *Description : Found the maximum value in the tree, recursive version.
 * @param max, the maximum of the tree.
 * */
void Sommet::Max(int *max) {
    if(data.freq >= *max) {
        *max = data.freq;
    }
    if(left) {
        left->Max(max);
    }
    if(right) {
        right->Max(max);
    }
}

/**
 * *Description : Found the maximum value in the tree.
 * @return the maximum of the tree.
 * */
int Sommet::dataMax() {
    int max = INT32_MIN; // Init min with the min value for int
    Max(&max);
    return max;
}

/**
 * *Description : Say if the node is a leaf.
 * @return boolean, true if the node is a leaf (any child), else false.
 * */
bool Sommet::isLeaf() {
    return (!left && !right);
}

/**
 * *Description : Print tree like the next pattern.
 *                  right right child ...
 *      right child
 *                  right left child ...
 * root
 *                  left right child ...
 *      left child
 *                 left left child ...
 * @param space, space between child.
 * */
void Sommet::printBeautifulTree(int space) {
    if(right) {
        right->printBeautifulTree(space + 1);
    }
    for(int i = 0; i < space; i++) {
        std::cout << "   ";
    }
    if(!this->isLeaf()) {
        std::cout << "(" <<  data.freq << "), " << std::endl;
    }
    else {
        std::cout << "(" << data.car << ", " << data.freq << "), " << std::endl;
    }
    if(left) {
        left->printBeautifulTree(space + 1);
    }
}

int maximum(int a, int b){
    return (a > b) ? a : b;
}

/**
 * *Description : Count the depth of the tree.
 * @return the depth.
 * */
int Sommet::countDepth() {
    int depthLeft = 0, depthRight = 0;
    if(left) {
        depthLeft = left->countDepth();
    }
    if(right) {
        depthRight = right->countDepth();
    }
    return 1 + maximum(depthLeft, depthRight);
}

/**
 * *Description : Count the size of the tree.
 * @return the number of element.
 * */
int Sommet::countSize() {
    int countLeft = 0, countRight = 0;
    if(left) {
        countLeft = left->countSize();
    }
    if(right) {
        countRight = right->countSize();
    }
    return 1 + countLeft + countRight;
}
/* End printers */

/* Destructors */
Sommet::~Sommet() {
    if(left) {
        delete left;
    }
    if(right) {
        delete right;
    }
}
ArbreB::~ArbreB() {
    if(root) {
        delete root;
    }
    root = nullptr;
}
/* End destructors */
