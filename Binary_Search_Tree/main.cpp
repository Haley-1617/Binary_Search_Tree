//
//  main.cpp
//  Binary_Search_Tree
//
//  Created by Haley Lai on 12/23/19.
//  Copyright © 2019 Haley Lai. All rights reserved.
//

#include "Binary_Search_Tree.h"

int main(int argc, const char * argv[]) {
   Binary_Search_Tree test;
   test.insert(8);
   test.insert(4);
   test.insert(12);
   test.insert(2);
   test.insert(6);
   test.insert(10);
   test.insert(14);
   test.insert(1);
   test.insert(3);
   test.insert(5);
   test.insert(7);
   test.insert(9);
   test.insert(11);
   test.insert(13);
   test.insert(15);
   test.display();
   test.remove(12);
   test.display();
   test.remove(11);
   test.remove(9);
   test.display();
   test.remove(6);
   test.display();
   test.remove(4);
   test.display();
   test.remove(1);
   test.display();
   test.remove(10);
   test.display();
   return 0;
}
