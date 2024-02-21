#include "deck.h"

/**
 * compare_cards - Comparison function for qsort
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 * Return: Integer less than, equal to, or greater than zero if a is found,
 * respectively, to be less than, to match, or be greater than b
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = (*(const deck_node_t **)a)->card;
	const card_t *card_b = (*(const deck_node_t **)b)->card;

	int kind_diff = card_a->kind - card_b->kind;

	if (kind_diff == 0)
		return (strcmp(card_a->value, card_b->value));
	return (kind_diff);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t deck_size = 52;
	deck_node_t **deck_array = malloc(deck_size * sizeof(deck_node_t *));
	deck_node_t *current_node;
	size_t i;

	if (!deck_array || !deck || !*deck)
		return;

	current_node = *deck;
	for (i = 0; i < deck_size; i++)
	{
		deck_array[i] = current_node;
		current_node = current_node->next;
	}
	qsort(deck_array, deck_size, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < deck_size - 1; i++)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}
	deck_array[deck_size - 1]->next = NULL;
	*deck = deck_array[0];

	free(deck_array);
}

