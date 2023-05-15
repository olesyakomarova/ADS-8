// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  countOp = 0;
  first = nullptr;
  return;
}

void Train::addCage(bool light) {
  Cage *newCage = new Cage;
  newCage->light = light;
  if (first == nullptr) {
    first = newCage;
    first->next = first;
    first->prev = first;
  } else {
    newCage->next = first;
    newCage->prev = first->prev;
    first->prev->next = newCage;
    first->prev = newCage;
  }
  return;
}

int Train::getLength() {
  Cage *current = first;
  current->light = 1;
  int length = 1;
  if (current == nullptr)
    return 0;
  current->light = 1;
  countOp++;
  current = current->next;
  while (current) {
        if (current->light == 0) {
            current = current->next;
            length++;
            countOp++;
        }  else {
            current->light = 0;
            for (int i = length; i > 0; i--) {
                current = current->prev;
                countOp++;
            }
            if (current->light == false) {
              return length;
            } else {
              length = 1;
              countOp++;
              current = current->next;
            }
        }
    }
    return 0;
}

int Train::getOpCount() {
  return countOp;
}
