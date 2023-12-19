#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - struct for card suit.
 * @SPADE: the value of spade.
 * @HEART: the value of hartd.
 * @CLUB: the  value of club.
 * @DIAMOND: the value of diamond.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - struct of the card game
 *
 * @value: the assigned val
 * From "Ace" to "King"
 * @kind: the type of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - struct for the deck
 *
 * @card: the val of the card
 * @prev: the val of the prev
 * @next: the val of th enext
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
