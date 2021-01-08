/**
 * Writer.cpp : You can found here all functions implemented for the Writer class.
 * Author : Mickael.
 **/

#include "Writer.hpp"

/**
 * *Description : Constructor with parameter.
 * @param nameFile, the name of the file.
 * */
Writer::Writer(std::string nameFile) : file(nameFile) {}

/**
 * *Description : Write a texte in a file, create his huffman tree and write his convert.
 * *Function : textToCode.
 * @param text, the original text.
 * */
void Writer::textToCode(std::string text) {
    // Write the original text.
    std::ofstream flux;
    flux.open(file.c_str(), std::ios::out | std::ios::trunc);
    if(flux) {
        flux << text;
        flux.close();
    }
    else {
        std::cout << "ERROR : can't open '" << file.c_str() << "'\n";
    }

    // Create his huffman tree.
    Parser parser; ArbreB huffmanTree;
    huffmanTree = parser.creatHuffmanTree(parser.freqChar(file.c_str()));
    std::string str = "\0"; std::stack<std::string> stack;
    parser.readHuffmanTree(huffmanTree.getRoot(), str, &stack);

    // Create a map to associate a char and his convert.
    std::map<char, std::string> map;
    std::string convert = "\0";
    while(!stack.empty()) {
        std::string tmp;
        tmp = stack.top();
        stack.pop();
        char c = tmp.back();
        tmp.pop_back(); // Erase the car
        map[c]=tmp;
    }

    // Concat all convert char in one string.
    for(char c : text) {
        std::map<char, std::string>::iterator it;
        it = map.find(c);
        convert += it->second;
    }

    // Write the convert text in a file.
    flux.open("src/txtQt/code.txt", std::ios::out | std::ios::trunc);
    if(flux) {
        flux << convert;
        flux.close();
    }
    else {
        std::cout << "ERROR : can't open '" << file.c_str() << "'\n";
    }
}



/**
 * *Description : Write a texte in a file, create his huffman tree and write his convert.
 * *Function : codeToText.
 * @param text, the original text.
 * */
void Writer::codeToText(std::string text, std::vector<Data> tabFreq) {
    // Write the original text.
    std::ofstream flux;
    flux.open(file.c_str(), std::ios::out | std::ios::trunc);
    if(flux) {
        flux << text;
        flux.close();
    }
    else {
        std::cout << "ERROR : can't open '" << file.c_str() << "'\n";
    }

    // Create his huffman tree.
    Parser parser; ArbreB huffmanTree;
    huffmanTree = parser.creatHuffmanTree(tabFreq);
    std::string str = "\0"; std::stack<std::string> stack;
    parser.readHuffmanTree(huffmanTree.getRoot(), str, &stack);

    // Create a map to associate a char and his convert.
    std::map<std::string, char> map;
    std::string convert = "\0";
    while(!stack.empty()) {
        std::string tmp;
        tmp = stack.top();
        stack.pop();
        char c = tmp.back();
        tmp.pop_back(); // Erase the car
        map[tmp]=c;
    }

    std::string tmp = "\0";
    int positionText = 0;
    while(positionText <= (int)text.size()) {
        std::map<std::string, char>::iterator it;
        it = map.find(tmp);
        if(it != map.end()) {
            convert += it->second;
            tmp = "\0";
        }
        if(positionText < (int)text.size()) {
            tmp += text.at(positionText);
        }
        positionText++;
    }

    // Write the convert text in a file.
    flux.open("src/txtQt/code.txt", std::ios::out | std::ios::trunc);
    if(flux) {
        flux << convert;
        flux.close();
    }
    else {
        std::cout << "ERROR : can't open '" << file.c_str() << "'\n";
    }
}
 