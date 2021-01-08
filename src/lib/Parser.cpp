/**
 * Parser.cpp : You can found here all functions implemented for
 * the Parser class.
 * Author : Mickael.
 **/

#include "Parser.hpp"

/**
 * *Description : Read the nameFile and fill the freq vector.
 * @param nameFile, the file name.
 * @return vector of Data with the freq and the car of any.
 *          caracters in the file.
 * */
std::vector<Data> Parser::freqChar(std::string nameFile) const {
    std::ifstream flux(nameFile);
    
    int buffSize = 256; bool seeChar;
    int posCharRead = 0;

    std::vector<Data> tabFreq;
    tabFreq.reserve(buffSize);
    char read;

    if(flux) {
        while(flux.get(read)) { // Read char by char in the file.
            seeChar = false;
            for(int i=0; i<int(tabFreq.size()); ++i) {
                if(read == tabFreq[i].car) {  // Char found, add freq.
                    tabFreq[i].freq++;
                    seeChar = true;
                }
            }
            if(!seeChar) { // Char not found, add char.
                Data newData; newData.freq = 1; newData.car = read;
                tabFreq.push_back(newData);
                posCharRead++;
            }
        }
        flux.close();
    }
    else {
        std::cout << "ERROR : can't open '" << nameFile << "'\n";
    }

    // Add default char and freq for fill until the end.
    Data newData; newData.freq = 0; newData.car = '\0';
    for(int i=posCharRead; i < buffSize; ++i) {
        tabFreq[i] = newData;
    }

    return tabFreq;
}

/**
 * *Description : Check if all trees was merge in one.
 * @param forest, the vector of tree.
 * @return boolean, true if all trees have -1 in freq except one.
 *          false, else.
 * */
bool stayOneTree(std::vector<ArbreB> forest) {
    int _stayOneTree = 0;
    for(int i=0; i<int(forest.size()); ++i) {
        if(forest[i].getRoot()->getData().freq != -1) {
            _stayOneTree++; // Add one if tree haven't -1 in freq <=> 
                            // tree isn't merge.
        }
    }
    return (_stayOneTree == 1);
}


/**
 * *Description : Create subtrees with all Data in vector, and merge in one.
 * @param tabFreq, the freq vector of any char.
 * @return the huffman tree.
 * */
ArbreB Parser::creatHuffmanTree(std::vector<Data> tabFreq) const {
    // Select sort.
    int size = 0;
    for(int i=0; i<int(tabFreq.size()); ++i) {
        for(int j=i+1; j<int(tabFreq.size()); ++j)
        if(tabFreq[i].freq != 0) {
            if(tabFreq[i].freq >= tabFreq[j].freq) {
                Data tmp = tabFreq[i];
                tabFreq[i] = tabFreq[j];
                tabFreq[j] = tmp;
            }
        }
        size++; // Real size of the vector without default elements.
    }

    // Create forest, init trees with only one leaf.
    std::vector<ArbreB> forest;
    forest.reserve(size);
    for(Data newData : tabFreq) {
        forest.push_back(ArbreB(newData));
    }

    int posMin, posMin2;
    // Merge all tree in one.
    while(!stayOneTree(forest)) {
        int min = INT32_MAX; // Init min with the max value for int.
        int min2 = INT32_MAX;

        // Found the first min.
        for(int i=0; i<int(forest.size()); ++i) {
            if(forest[i].getRoot()->getData().freq != -1
            && forest[i].getRoot()->getData().freq <= min) {
                min = forest[i].getRoot()->getData().freq;
                posMin = i;
            }
        }

        // Found the second min, different of the first.
        for(int i=0; i<int(forest.size()); ++i) {
            if(forest[i].getRoot()->getData().freq != -1
            && forest[i].getRoot()->getData().freq <= min2
            && !(*forest[i].getRoot() == *forest[posMin].getRoot())) {
                min2 = forest[i].getRoot()->getData().freq;
                posMin2 = i;
            }
        }

        forest[posMin2] += forest[posMin]; // Merge the two minimums trees.
        
        // Put default parameter for indicat the tree is merge with an
        // other one
        Data newData; newData.freq = -1; newData.car = '\0';
        *forest[posMin].getRoot() = newData;
    }

    // Return the final tree.
    for(int i=0; i<int(forest.size()); ++i) {
        if(forest[i].getRoot()->getData().freq != -1) {
            return forest[i];
        }
    }

    // Return default tree in case of error.
    ArbreB tmp;
    return tmp;
}

/**
 * * Description : Check if all trees was merge in one.
 * @param node, the current node.
 * @param str, the string for concat the convert letter.
 * @param stack, a stack for save all convert letter.
 * */
void Parser::readHuffmanTree(Sommet* node, std::string str,
                                std::stack<std::string>* stack) const {
    if(node->isLeaf()) {
        stack->push(str + node->getData().car);
    }
    else {
        if(node->getLeft()) {
            str += "0";
            readHuffmanTree(node->getLeft(), str, stack);
            str.pop_back();
        }
        if(node->getRight()) {
            str += "1";
            readHuffmanTree(node->getRight(), str, stack);
            str.pop_back();
        }
    }
}