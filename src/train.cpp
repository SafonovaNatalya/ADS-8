// Copyright 2021 NNTU-CS
#include "train.h"
 Train::Train() : first(nullptr), countOp(0) {}

 void Train::addCage(bool light) {
   Cage* Ncage = new Cage;
   Ncage->light = light;
   if (first == nullptr) {
       first = Ncage;
       first->next = first;
       first->prev = first;
   } else {
       Ncage->next = first;
       Ncage->prev = first->prev;
       first->prev = Ncage;
       Ncage->prev->next = Ncage;
 }
 int Train::getLength() {
    Cage* helper = first;
    int kol = 1;
    helper->light = 1;
    countOp = 0;
    while (helper) {
        helper = helper->next;
        if (!helper->light) {
            kol++;
            countOp++;
        } else {
            helper->light = false;
            countOp++;
            for (int i = kol; i > 0; i--) {
                helper = helper->prev;
                countOp++;
            }
            if (!temp->light) {
                return kol;
            }
            kol = 1;
        }
    }
    return -1;
}

int Train::getOpCount() {
    return countOp;
}
