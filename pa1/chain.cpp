#include "chain.h"
#include <cmath>
#include <iostream>


// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain() {
  /* your code here */
  
}

/**
 * Inserts a new node after the node pointed to by p in the
 * chain (so p->next is the new node) and returns a pointer to
 * the newly created node.
 * If p is NULL, inserts a new head node to the chain.
 * This function **SHOULD** create a new Node and increase length_.
 *
 * @param p = The new node should be pointed to by p->next.
 *            If p is NULL, the new node becomes the head of the chain.
 * @param ndata = The data to be inserted.
 */
Chain::Node * Chain::insertAfter(Node * p, const Block &ndata) {
  /* your code here */
  length_++;
  
  if (p  != NULL) {
    Node * toAdd = new Node(ndata);
    if (p-> next != NULL) {
      Node * temp = p -> next;
      p -> next = toAdd;
      toAdd -> prev = p;
      toAdd -> next = temp;
      temp-> prev = toAdd;
      return toAdd;
    }
    else {
      p -> next = toAdd;
      toAdd -> prev = p;
      return toAdd;
    }
    
  }
  else {
    Node *add = new Node(ndata);
    if (head_ != NULL) {
      add -> prev = head_ -> prev;
      add -> next = head_;
      head_ -> prev = add;
      return add;
    }
    else {
      head_ = add;
      return head_;
    }
    
  }
  
}

/**
 * Swaps the position in the chain of the two nodes pointed to
 * by p and q.
 * If p or q is NULL or p==q, do nothing.
 * Change the chain's head pointer if necessary.
 */
void Chain::swap(Node * p, Node * q) {
  
  if ((p == NULL || q == NULL || p == q)) {
    return;
  } 

  if (p == head_ && p->next == q && q->next == NULL) {
    q->next = p;
    p->next = NULL;
    q->prev = NULL;
    p->prev = q;
    head_ = q;
    return;
  }

  if (q == head_ && q->next == p && p->next == NULL) {
    p->next = q;
    q->next = NULL;
    p->prev = NULL;
    q->prev = p;
    head_ = p;
  }

    //p is head and q is adjacent
    if (p -> prev == NULL && p-> next == q) {
    
      Node * qNext = q -> next;
      
      p -> next = qNext;
      q -> prev = NULL;
      q -> next = p;
      p -> prev = q;

      qNext -> prev = p;

      head_ = q;
      return;

    }

    //q is head and p is adjacnet
     if (q -> prev == NULL && q-> next == p) {
    
      Node * pNext = p -> next;
      
      q -> next = pNext;
      p -> prev = NULL;
      p -> next = q;
      q -> prev = p;

      pNext -> prev = q;

      head_ = p;
      return;

    }

    //p is tail and q is adjacent
    if (p -> next == NULL && p-> prev == q) {
      Node * qPrev = q -> prev;
      
      p -> prev = qPrev;
      q -> next = NULL;
      q -> prev = p;
      p -> next = q;

      qPrev -> next = p;

      return;
    } 

    //q is tail and p is adjacent
    if (q -> next == NULL && q-> prev == p) {
      Node * pPrev = p -> prev;
      
      q -> prev = pPrev;
      p -> next = NULL;
      p -> prev = q;
      q -> next = p;

      pPrev -> next = q;

      return;
    } 

  // p is head
  if (p -> prev == NULL) {
    
    Node * qPrev = q -> prev;
    Node * pNext = p -> next;

    q -> prev = NULL;
    p -> prev = qPrev;
    qPrev -> next = p;
     
    if (q-> next != NULL) {
        Node * qNext = q -> next;
        p -> next = qNext;
        qNext -> prev = p;
    }
    else {
      p-> next = NULL;
    }
  
    q -> next = pNext;
    pNext -> prev = q;

  head_ = q;
  return;
  }

  // q is head
  if (q -> prev == NULL) {
    
    Node * pPrev = p -> prev;
    Node * qNext = q -> next;
     
    p -> prev = NULL;
    q -> prev = pPrev;
    pPrev -> next = q;
      
    if (p-> next != NULL) {
        Node * pNext = p -> next;
        q -> next = pNext;
        pNext -> prev = q;
    }
    else {
      q-> next = NULL;
    }

    p -> next = qNext;
    qNext -> prev  = p;
    
    head_ = p;
    return;
  }

  // p is tail
  if (p -> next == NULL) {
    Node * qNext = q -> next;
    Node * pPrev = p -> prev;

    q -> next = NULL;
    p -> next = qNext;
    qNext -> prev = p;
     
    if (q-> prev != NULL) {
        Node * qPrev = q -> prev;
        p -> prev = qPrev;
        qPrev -> next = p;
    }
    else {
      p-> prev = NULL;
    }
  
    q -> prev = pPrev;
    pPrev -> next = q;
 
  return;
  }

  //q is tail
  if (q -> next == NULL) {
    Node * pNext = p -> next;
    Node * qPrev = q -> prev;

    p -> next = NULL;
    q -> next = pNext;
    pNext -> prev = q;
     
    if (p-> prev != NULL) {
        Node * pPrev = p -> prev;
        q -> prev = pPrev;
        pPrev -> next = q;
    }
    else {
      q-> prev = NULL;
    }
  
    p -> prev = qPrev;
    qPrev -> next = p;

    return;
  }

  Node * prev_p = p->prev;
  Node * prev_q = q->prev;
  Node * next_p = p->next;
  Node * next_q = q->next;

  if (prev_p == q) {
    
    prev_q->next = p;
    next_p->prev = q;
    
    q->next = next_p;
    p->prev = prev_q;
    q->prev = p;
    p->next = q;

    return;
  } 

  if (prev_q == p) {
      
      prev_p->next = q;
     next_q->prev = p;
      p->next = next_q;
      q->prev = prev_p;
      p->prev = q;
      q->next = p;

    return;
  } 
      prev_p->next = q;
      prev_q->next = p;
      next_p->prev = q;
      next_q->prev = p;

      p->prev = prev_q;
      q->prev = prev_p;
      p->next = next_q;
      q->next = next_p;

  return;

}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear() {
  /* your code here */
}

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other) {

  clear();

  length_ = other.length_;

  if (other.head_ == NULL) {
    return; 
  } 

  head_ = new Node(other.head_->data);  
  Node * curr_node = head_;
  Node * other_node = other.head_->next;

  for(int i = (length_); i > 1; i--) {
    insertAfter(curr_node, other_node->data);
    curr_node = curr_node->next;
    other_node = other_node->next;
  }
}

/* Modifies the current chain: 
 * 1) Find the node with the first (leftmost) block in the unscrambled
 *    image and move it to the head of the chain.
 *	This block is the one whose closest match (to the left) is the
 *	largest.  That is, the distance (using distanceTo) to this block 
 *	is big for all other blocks.
 *	For each block B, find the distanceTo B from every other block
 *	and take the minimum of these distances as B's "value".
 *	Choose the block B with the maximum value over all blocks and
 *	swap its node to the head of the chain.
 *
 * 2) Starting with the (just found) first block B, find the node with
 *    the block that is the closest match to follow B (to the right)
 *    among the remaining blocks, move (swap) it to follow B's node,
 *    then repeat to unscramble the chain/image.
 */
void Chain::unscramble() {
  Node * curr_node = head_->next;
  Node * node_to_swap = head_->next;
  Node * prev_node = head_;

  Node * temp_node;
  double curr_distance;
  double temp_distance;
  double max_min_distance = 0;
  Block prev_data;

  //to find head
  for (int i = (length_ - 1); i > 1; i--) {
      temp_node = curr_node;
      prev_data = prev_node->data;

      temp_distance = prev_data.distanceTo(curr_node->data);

      for (int j = 0; j < i; j++) {
        curr_distance = prev_data.distanceTo(temp_node->data);

        if (temp_distance > curr_distance) {
          temp_distance = curr_distance;
          if (temp_distance > max_min_distance) {
            max_min_distance = temp_distance;
            node_to_swap = curr_node;
            }
          } 
        temp_node = temp_node->next;
      }
      curr_node = node_to_swap->next;
      prev_node = node_to_swap;
    }

  swap(head_, node_to_swap);

  prev_node = head_;
  curr_node = head_->next;

  for (int i = (length_ - 1); i > 1; i--) {
    temp_node = curr_node;
    node_to_swap = curr_node;
    prev_data = prev_node->data;
    temp_distance = prev_data.distanceTo(curr_node->data);

    for (int j = 0; j < i; j++) {
      curr_distance = prev_data.distanceTo(temp_node->data);
      if (temp_distance > curr_distance) {
        temp_distance = curr_distance;
        node_to_swap = temp_node;
      } 
      temp_node = temp_node->next;
    }
  swap(curr_node, node_to_swap);
  curr_node = node_to_swap->next;
  prev_node = node_to_swap;
  }
}
